/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_save_config/proc_tod_save_config.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: proc_tod_save_config.C,v 1.5 2012/12/03 21:00:06 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!
// *! TITLE : proc_tod_save_config.C
// *!
// *! DESCRIPTION : Saves TOD configuration registers to i_tod_node->o_todRegs
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_tod_save_config.H"
#include "p8_scom_addresses.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: proc_tod_save_config
//
// parameters: i_tod_node  Reference to TOD topology (FAPI targets included within)
//
// returns: FAPI_RC_SUCCESS if all registers were read and saved in node structure
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_save_config(tod_topology_node* i_tod_node)
{
    fapi::ReturnCode rc;

    FAPI_DBG("proc_tod_save_config: Start");
    do
    {
        if (i_tod_node == NULL)
        {
            FAPI_ERR("proc_tod_save_config: null node passed into function!");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_NULL_NODE);
            break;
        }
        fapi::Target* target = i_tod_node->i_target;

        rc = proc_tod_save_single_reg(*target, TOD_M_PATH_CTRL_REG_00040000, i_tod_node->o_todRegs.tod_m_path_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_M_PATH_CTRL_REG_00040000...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_PRI_PORT_0_CTRL_REG_00040001,i_tod_node->o_todRegs.tod_pri_port_0_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_PRI_PORT_0_CTRL_REG_00040001...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_PRI_PORT_1_CTRL_REG_00040002,i_tod_node->o_todRegs.tod_pri_port_1_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_PRI_PORT_1_CTRL_REG_00040002...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_SEC_PORT_0_CTRL_REG_00040003,i_tod_node->o_todRegs.tod_sec_port_0_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_SEC_PORT_0_CTRL_REG_00040003...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_SEC_PORT_1_CTRL_REG_00040004,i_tod_node->o_todRegs.tod_sec_port_1_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_SEC_PORT_1_CTRL_REG_00040004...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_S_PATH_CTRL_REG_00040005,i_tod_node->o_todRegs.tod_s_path_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_S_PATH_CTRL_REG_00040005...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_I_PATH_CTRL_REG_00040006,i_tod_node->o_todRegs.tod_i_path_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_I_PATH_CTRL_REG_00040006...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_PSS_MSS_CTRL_REG_00040007,i_tod_node->o_todRegs.tod_pss_mss_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_PSS_MSS_CTRL_REG_00040007...");
            break;
        }

        rc = proc_tod_save_single_reg(*target, TOD_CHIP_CTRL_REG_00040010,i_tod_node->o_todRegs.tod_chip_ctrl_reg);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_config: Error saving TOD_CHIP_CTRL_REG_00040010...");
            break;
        }

        // Recurse to save children configuration
        for (std::list<tod_topology_node*>::iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            rc = proc_tod_save_config(tod_node);
            if (!rc.ok())
            {
                FAPI_ERR("proc_tod_save_config: Failure saving downstream configurations!");
                break;
            }
        }
        if (!rc.ok())
        {
            break;  // error in above for loop
        }
    } while(0);

    FAPI_DBG("proc_tod_save_config: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: proc_tod_save_single_reg
//
// parameters: i_target FAPI target
//             i_addr   SCOM address to read
//             o_data   Buffer to save register read
//
// returns: FAPI_RC_SUCCESS if the given register was read and saved into buffer
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_save_single_reg(const fapi::Target& i_target,
                                          const uint64_t      i_addr,
                                          ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_tod_save_single_reg: Start");
    do
    {
        rc_ecmd |= o_data.setBitLength(64);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tod_save_single_reg: Error 0x%08X in ecmdDataBuffer setup for 0x%016llX SCOM.",  rc_ecmd, i_addr);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc=fapiGetScom(i_target,i_addr,o_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_save_single_reg: Error from fapiGetScom when retrieving 0x%016llX...", i_addr);
            break;
        }
        FAPI_DBG("proc_tod_save_single_reg: %016llX = %016llX",i_addr, o_data.getDoubleWord(0));
    } while(0);

    FAPI_DBG("proc_tod_save_single_reg: End");
    return rc;
}

} // extern "C"
