/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_init/proc_tod_init.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: proc_tod_init.C,v 1.15 2014/10/23 18:56:17 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *!
// *! TITLE : proc_tod_init.C
// *!
// *! DESCRIPTION : Initializes the TOD topology to 'running'
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
#include "proc_tod_utils.H"
#include "proc_tod_init.H"
#include "p8_scom_addresses.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: proc_tod_init
//
// parameters:
//         i_tod_node  Reference to TOD topology (FAPI targets included within)
//
//         i_failingTodProc, Pointer to the fapi target, the memory location
//         addressed by this parameter will be populated with processor target
//         which is not able to recieve proper singals from OSC.
//         Caller needs to look at this parameter only when proc_tod_init fails
//         and reason code indicates OSC failure. It is defaulted to NULL.
//
// returns: FAPI_RC_SUCCESS if TOD topology is successfully initialized
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_init(const tod_topology_node* i_tod_node,
                 fapi::Target* i_failingTodProc )
{
    fapi::ReturnCode rc;

    FAPI_INF("proc_tod_init: Start");
    do
    {
        if (i_tod_node == NULL)
        {
            FAPI_ERR("proc_tod_init: null node passed into function!");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_NULL_NODE);
            break;
        }

        rc = proc_tod_clear_error_reg(i_tod_node);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_init: Failure clearing TOD error registers!");
            break;
        }

        //Start configuring each node; (init_tod_node will recurse on each child)
        rc = init_tod_node(i_tod_node,i_failingTodProc);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_init: Failure initializing TOD!");
            break;
        }

    } while (0);

    FAPI_INF("proc_tod_init: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: proc_tod_clear_error_reg
//
// parameters: i_tod_node  Reference to TOD topology (FAPI targets included within)
//
// returns: FAPI_RC_SUCCESS if every TOD node is cleared of errors
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_clear_error_reg(const tod_topology_node* i_tod_node)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    uint32_t rc_ecmd = 0;
    fapi::Target* target = i_tod_node->i_target;

    FAPI_INF("proc_tod_clear_error_reg: Start");
    do
    {
        if (i_tod_node == NULL)
        {
            FAPI_ERR("proc_tod_clear_error_reg: null node passed into function!");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_NULL_NODE);
            break;
        }

        FAPI_DBG("proc_tod_clear_error_reg: Clear any previous errors from TOD_ERROR_REG_00040030");
        rc_ecmd |= data.flushTo1();
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tod_clear_error_reg: Error 0x%08X in ecmdDataBuffer setup for TOD_ERROR_REG_00040030.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(*target, TOD_ERROR_REG_00040030, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_clear_error_reg: Could not write TOD_ERROR_REG_00040030.");
            break;
        }

        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            rc = proc_tod_clear_error_reg(tod_node);
            if (!rc.ok())
            {
                FAPI_ERR("proc_tod_clear_error_reg: Failure clearing errors from downstream node!");
                break;
            }
        }
        if (!rc.ok())
        {
            break;  // error in above for loop
        }
    } while (0);

    FAPI_INF("proc_tod_clear_error_reg: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: init_tod_node
//
// parameters:
//          i_tod_node  Reference to TOD topology (FAPI targets included within)
//
//          i_failingTodProc, Pointer to the fapi target, the memory location
//          addressed by this parameter will be populated with processor target
//          which is not able to recieve proper singals from OSC.
//          Caller needs to look at this parameter only when proc_tod_init fails
//          and reason code indicates OSC failure. It is defaulted to NULL.
//
// returns: FAPI_RC_SUCCESS if TOD topology is successfully initialized
//          else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode init_tod_node(const tod_topology_node* i_tod_node,
        fapi::Target* i_failingTodProc)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    uint32_t rc_ecmd = 0;
    uint32_t tod_init_pending_count = 0; // Timeout counter for bits that are cleared by hardware
    fapi::Target* target = i_tod_node->i_target;

    FAPI_INF("init_tod_node: Start: Initializing %s", target->toEcmdString());

    do
    {
        const bool is_mdmt = (i_tod_node->i_tod_master && i_tod_node->i_drawer_master);

        if (is_mdmt)
        {
            FAPI_INF("init_tod_node: Master: Chip TOD step checkers enable");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(0);
            if (rc_ecmd)
            {
                FAPI_ERR("init_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_TX_TTYPE_2_REG_00040013 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_TX_TTYPE_2_REG_00040013, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Could not write TOD_TX_TTYPE_2_REG_00040013.");
                break;
            }

            FAPI_INF("init_tod_node: Master: switch local Chip TOD to 'Not Set' state");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(TOD_LOAD_TOD_MOD_REG_FSM_LOAD_TOD_MOD_TRIG);
            if (rc_ecmd)
            {
                FAPI_ERR("init_tod_node: Master: Error 0x%08X in ecmdDataBuffer setup for TOD_LOAD_TOD_MOD_REG_00040018 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_LOAD_TOD_MOD_REG_00040018, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Master: Could not write TOD_LOAD_TOD_MOD_REG_00040018");
                break;
            }
            FAPI_INF("init_tod_node: Master: switch all Chip TOD in the system to 'Not Set' state");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(0);
            if (rc_ecmd)
            {
                FAPI_ERR("init_tod_node: Master: Error 0x%08X in ecmdDataBuffer setup for TOD_TX_TTYPE_5_REG_00040016 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_TX_TTYPE_5_REG_00040016, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Master: Could not write TOD_TX_TTYPE_5_REG_00040016");
                break;
            }

            FAPI_INF("init_tod_node: Master: Chip TOD load value (move TB to TOD)");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setWord(0,0x00000000);
            rc_ecmd |= data.setWord(1,0x00003FF0); // bits 51:59 must be 1s
            if (rc_ecmd)
            {
                FAPI_ERR("init_tod_node: Master: Error 0x%08X in ecmdDataBuffer setup for TOD_LOAD_TOD_REG_00040021 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_LOAD_TOD_REG_00040021, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Master: Could not write TOD_LOAD_TOD_REG_00040021");
                break;
            }
            FAPI_INF("init_tod_node: Master: Chip TOD start_tod (switch local Chip TOD to 'Running' state)");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(TOD_START_TOD_REG_FSM_START_TOD_TRIGGER);
            if (rc_ecmd)
            {
                FAPI_ERR("init_tod_node: Master: Error 0x%08X in ecmdDataBuffer setup for TOD_START_TOD_REG_00040022 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_START_TOD_REG_00040022, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Master: Could not write TOD_START_TOD_REG_00040022");
                break;
            }

            FAPI_INF("init_tod_node: Master: Send local Chip TOD value to all Chip TODs");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(0);
            if (rc_ecmd)
            {
                FAPI_ERR("init_tod_node: Master: Error 0x%08X in ecmdDataBuffer setup for TOD_TX_TTYPE_4_REG_00040015",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_TX_TTYPE_4_REG_00040015, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Master: Could not write TOD_TX_TTYPE_4_REG_00040015");
                break;
            }
        }

        FAPI_INF("init_tod_node: Check TOD is Running");
        tod_init_pending_count = 0;
        while (tod_init_pending_count < PROC_TOD_UTIL_TIMEOUT_COUNT)
        {
            FAPI_DBG("init_tod_node: Waiting for TOD to assert TOD_FSM_REG_TOD_IS_RUNNING...");

            rc = fapiDelay(PROC_TOD_UTILS_HW_NS_DELAY,
                           PROC_TOD_UTILS_SIM_CYCLE_DELAY);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: fapiDelay error");
                break;
            }
            rc = fapiGetScom(*target, TOD_FSM_REG_00040024, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Could not retrieve TOD_FSM_REG_00040024");
                break;
            }
            if (data.isBitSet(TOD_FSM_REG_TOD_IS_RUNNING))
            {
                FAPI_INF("init_tod_node: TOD is running!");
                break;
            }
            ++tod_init_pending_count;
        }
        if (!rc.ok())
        {
            break;  // error in above while loop
        }
        if (tod_init_pending_count>=PROC_TOD_UTIL_TIMEOUT_COUNT)
        {
                FAPI_ERR("init_tod_node: TOD is not running! (It should be)");
                const fapi::Target & CHIP_TARGET = *target;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_INIT_NOT_RUNNING);
                break;
        }

        FAPI_INF("init_tod_node: clear TTYPE#2, TTYPE#4, and TTYPE#5 status");
        rc_ecmd |= data.flushTo0();
        rc_ecmd |= data.setBit(TOD_ERROR_REG_RX_TTYPE_2);
        rc_ecmd |= data.setBit(TOD_ERROR_REG_RX_TTYPE_4);
        rc_ecmd |= data.setBit(TOD_ERROR_REG_RX_TTYPE_5);
        if (rc_ecmd)
        {
            FAPI_ERR("init_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_ERROR_REG_00040030.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(*target, TOD_ERROR_REG_00040030, data);
        if (!rc.ok())
        {
            FAPI_ERR("init_tod_node: Could not write TOD_ERROR_REG_00040030.");
            break;
        }

        FAPI_INF("init_tod_node: checking for TOD errors");
        rc = fapiGetScom(*target, TOD_ERROR_REG_00040030, data);
        if (!rc.ok())
        {
            FAPI_ERR("init_tod_node: Could not read TOD_ERROR_REG_00040030.");
            break;
        }
        if (data.getDoubleWord(0) != 0)
        {
            const fapi::Target & CHIP_TARGET = *target;
            const uint64_t TOD_ERROR_REG = data.getDoubleWord(0);
            if (data.isBitSet(TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR))
            {
                FAPI_ERR("init_tod_node: M_PATH_0_STEP_CHECK_ERROR! (TOD_ERROR_REG = 0x%016llX)",data.getDoubleWord(0));
                FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_INIT_M_PATH_0_STEP_CHECK_ERROR);
                *i_failingTodProc = *target;
            }
            else if (data.isBitSet(TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR))
            {
                FAPI_ERR("init_tod_node: M_PATH_1_STEP_CHECK_ERROR! (TOD_ERROR_REG = 0x%016llX)",data.getDoubleWord(0));
                FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_INIT_M_PATH_1_STEP_CHECK_ERROR);
                *i_failingTodProc = *target;
            }
            else
            {
                FAPI_ERR("init_tod_node: FIR bit active! (TOD_ERROR_REG = 0x%016llX)",data.getDoubleWord(0));
                FAPI_SET_HWP_ERROR(rc, RC_PROC_TOD_INIT_ERROR);
            }
            break;
        }

        // TOD_ERROR_MASK_STATUS_REG_00040032 is not writable on some chips
        uint8_t chipHasTodErrorMaskBug = 0;
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_HW_BUG_TOD_ERROR_MASK_NOT_WRITABLE, target, chipHasTodErrorMaskBug);
        if(rc)
        {
            FAPI_ERR("init_tod_node: Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_HW_BUG_TOD_ERROR_MASK_NOT_WRITABLE");
            break;
        }
        if(!chipHasTodErrorMaskBug)
        {
            FAPI_INF("init_tod_node: set error mask to runtime configuration");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setWord(1,0x03F00000); // Mask TTYPE received informational bits 38:43
            if (rc_ecmd)
            {
                FAPI_ERR("init_tod_node: Error 0x%08X in ecmdDataBuffer setup for TOD_ERROR_MASK_STATUS_REG_00040032 SCOM.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(*target, TOD_ERROR_MASK_STATUS_REG_00040032, data);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Could not write TOD_ERROR_MASK_STATUS_REG_00040032");
                break;
            }
        }
        else
        {
            FAPI_INF("init_tod_node: Skipping TOD error mask setup because of chip limitation.");
        }

        // Finish configuring downstream nodes
        for (std::list<tod_topology_node*>::const_iterator child = (i_tod_node->i_children).begin();
             child != (i_tod_node->i_children).end();
             ++child)
        {
            tod_topology_node* tod_node = *child;
            rc = init_tod_node(tod_node,i_failingTodProc);
            if (!rc.ok())
            {
                FAPI_ERR("init_tod_node: Failure configuring downstream node!");
                break;
            }
        }
        if (!rc.ok())
        {
            break;  // error in above for loop
        }

    } while(0);

    FAPI_INF("init_tod_node: End");
    return rc;
}

} // extern "C"
