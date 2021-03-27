/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/establish_system_smp.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
/**
 *  @file establish_system_smp.C
 *
 *  Support file for IStep: establish_system_smp
 *   Establish System SMP
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1611
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */
/******************************************************************************/
// Includes
/******************************************************************************/

// Local header files
#include "establish_system_smp.H"

// Standard headers
#include <vector>
#include <array>
#include <stdint.h>                        // uint8_t, uint16_t, etc

// Trace/Initservice
#include <trace/interface.H>               // TRACFCOMP
#include <initservice/isteps_trace.H>      // g_trac_isteps_trace
#include <initservice/istepdispatcherif.H> // setAcceptIstepMessages
#include <istep_mbox_msgs.H>               // INITSERVICE::HWSVR_MSG_SUCCESS

// Error logging
#include <errl/errlentry.H>                // errlHndl_t
#include <errl/errludtarget.H>             // ErrlUserDetailsTarget

// Targeting support
#include <targeting/common/target.H>       // TargetHandleList, getAttr
#include <targeting/common/utilFilter.H>   // getAllChips, getEncResources
#include <targeting/common/entitypath.H>   // EntityPath
#include <targeting/targplatutil.H>        // assertGetToplevelTarget
#include <targeting/common/attributes.H>   // ATTR_*

// Fapi support
#include <fapi2/target.H>                  // fapi2::TARGET_TYPE_PROC_CHIP
#include <fapi2/plat_hwp_invoker.H>        // FAPI_INVOKE_HWP
#include <isteps/hwpf_reasoncodes.H>       // fapi::MOD_HOST_COALESCE_HOST

// Systems support
#include <sys/msg.h>                       // msg_t, msg_allocate, msg_q_t, etc
#include <sys/time.h>                      // nanosleep, NS_PER_MSEC

// Secure boot support
#include <secureboot/nodecommif.H>         // SECUREBOOT::NODECOMM::nodeCommAbusExchange
#include <secureboot/service_ext.H>        // SECUREBOOT::lockAbusSecMailboxes

// HWP
#include <p10_block_wakeup_intr.H>        // p10_block_wakeup_intr

// Misc
#include <mbox/ipc_msg_types.H>           // IPC::IPC_TEST_CONNECTION
#include <arch/pirformat.H>               // PIR_t


/******************************************************************************/
// namespace shortcuts
/******************************************************************************/
using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEPS_TRACE;

namespace ESTABLISH_SYSTEM_SMP
{

/// Forward declarations of local APIs
// Support call for public API call_host_coalesce_host
errlHndl_t verify_ipc_connection(ATTR_HB_EXISTING_IMAGE_type i_hbExistingImage);
// Support call for local/private API verify_ipc_connection
void* host_coalesce_timer ( void* i_msgQPtr );
// Support call for public API host_sys_fab_iovalid_processing
void set_is_master_drawer( const EntityPath *i_masterEntityPath );


//******************************************************************************
//                                PUBLIC APIs
//******************************************************************************

//******************************************************************************
// call_host_coalesce_host
//******************************************************************************
errlHndl_t call_host_coalesce_host( )
{
    errlHndl_t l_err(nullptr);

    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_host_coalesce_host" );

    auto l_hbExistingImage = UTIL::assertGetToplevelTarget()->getAttr<ATTR_HB_EXISTING_IMAGE>();

    if (0 == l_hbExistingImage)
    {
        // Single node system so do nothing
        TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                   "call_host_coalesce_host on a single node system is a no-op" );
    }
    else
    {
        // Verify the IPC connections
        l_err = verify_ipc_connection(l_hbExistingImage);
    }

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK"call_host_coalesce_host" );

    return l_err;
} // call_host_coalesce_host


//******************************************************************************
// host_sys_fab_iovalid_processing
//******************************************************************************
void* host_sys_fab_iovalid_processing(void* io_ptr )
{
    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"host_sys_fab_iovalid_processing" );

    // Input parameter is actually a msg_t pointer
    msg_t* io_pMsg = static_cast<msg_t *>(io_ptr);

    // Assume success, unless we hit an error later.
    io_pMsg->data[0] = INITSERVICE::HWSVR_MSG_SUCCESS;

    // if there is extra data, start processing it
    if (io_pMsg->extra_data)
    {
        iovalid_msg* l_drawerData = reinterpret_cast<iovalid_msg *>(io_pMsg->extra_data);

        // setup a pointer to the first drawer entry in our data
        EntityPath * l_entityPathPtr = l_drawerData->drawers;

        // Cannot use the call 'toString' directly, must cache data and delete to avoid a memory leak.
        char* l_masterNode = l_entityPathPtr->toString();
        const uint16_t l_drawerCount = l_drawerData->count;
        TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                   "Master node %s, List size = %d bytes, Drawer count = %d",
                   l_masterNode, l_drawerData->size, l_drawerCount);

        // Free the results from the call 'toString' to avoid a memory leak.
        free(l_masterNode);
        l_masterNode = nullptr;

        if (l_drawerCount > 0)
        {
            // master node will be first node listed (lowest functional node)
            set_is_master_drawer(l_entityPathPtr);
        }

        // get FABRIC_TO_PHYSICAL_NODE_MAP
        Target * l_sys = UTIL::assertGetToplevelTarget();

        auto l_nodeMap = l_sys->getAttrAsStdArr<ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>();

        ATTR_HB_EXISTING_IMAGE_type l_hbExistingImage = 0;

        // create a vector with the present drawers
        std::vector<EntityPath> l_presentDrawers;

        for (uint8_t i = 0; i < l_drawerCount; i++)
        {
            // Cannot use the call 'toString' directly, must cache data and
            // delete to avoid a memory leak.
            char* l_entityPath = l_entityPathPtr->toString();
            TRACFCOMP( g_trac_isteps_trace, INFO_MRK"list entry[%d] - %s", i, l_entityPath);

            // Free the results from the call 'toString' to avoid a memory leak.
            free(l_entityPath);
            l_entityPath = nullptr;

            l_presentDrawers.push_back(*l_entityPathPtr);

            EntityPath::PathElement l_pathElement = l_entityPathPtr->pathElementOfType(TYPE_NODE);

            // pathElement.instance is the drawer number - convert to logical node
            uint8_t l_logicalNode = l_nodeMap[l_pathElement.instance];

            // set mask to msb of bitmap
            ATTR_HB_EXISTING_IMAGE_type l_hbImageMask = 0x1 << (NUMBER_OF_POSSIBLE_DRAWERS -1);

            // set bit for this logical node.
            l_hbExistingImage |= (l_hbImageMask >> l_logicalNode);

            l_entityPathPtr++;
        } // end for (uint8_t i = 0; i < l_drawerCount; i++)

        l_sys->setAttr<ATTR_HB_EXISTING_IMAGE>(l_hbExistingImage);
#ifdef CONFIG_TPMDD
        {  // CONFIG_TPMDD scoping
            // Run Secure Node-to-Node Communication Procedure
            TRACFCOMP( g_trac_isteps_trace, ERR_MRK
                "host_sys_fab_iovalid_processing: l_hbExistingImage = 0x%X, "
                "isMaster=%d.  Calling nodeCommExchange()",
                l_hbExistingImage, UTIL::isCurrentMasterNode());

            errlHndl_t l_err = SECUREBOOT::NODECOMM::nodeCommExchange();
            if (l_err)
            {
                // Commit error here and the FSP will handle it
                TRACFCOMP( g_trac_isteps_trace, ERR_MRK
                    "host_sys_fab_iovalid_processing: nodeCommExchange() "
                    "returned err: plid=0x%X. Deleting err and continuing",
                    l_err->plid());
                l_err->collectTrace("ISTEPS_TRACE");
                // Let the caller know that an error occurred
                io_pMsg->data[0] = l_err->plid();
                errlCommit(l_err, SECURE_COMP_ID);
           }

            // Lock the secure Link Mailboxes now
            SECUREBOOT::lockSecureMailboxes();
        }
#endif
    }  // end if (io_pMsg->extra_data)
    else  // There is no extra data to process
    {
        // message needs to have at least one entry
        // in the drawer list, else we will say invalid msg
        io_pMsg->data[0] = INITSERVICE::HWSVR_INVALID_MESSAGE;
    } // end if(io_pMsg->extra_data) ... else

    io_pMsg->data[1] = 0;

    // response will be sent by calling routine
    // IStepDispatcher::handleProcFabIovalidMsg()
    // which will also execute the procedure to winkle all cores

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK
               "host_sys_fab_iovalid_processing exit data[0]=0x%X",
               io_pMsg->data[0]);

    return nullptr;
} // host_sys_fab_iovalid_processing


//******************************************************************************
// blockInterrupts
//******************************************************************************
errlHndl_t blockInterrupts()
{
    errlHndl_t l_err(nullptr);

    // Get all functional core units
    TargetHandleList l_coreList;
    getAllChiplets(l_coreList, TYPE_CORE);

    for (auto l_core : l_coreList)
    {
        TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                   "Running p10_block_wakeup_intr(ENABLE_BLOCK_EXIT) on EX target HUID %.8X",
                   get_huid(l_core));

        fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapiCoreTarget(l_core);

        FAPI_INVOKE_HWP( l_err,
                         p10_block_wakeup_intr,
                         l_fapiCoreTarget,
                         p10pmblockwkup::ENABLE_BLOCK_EXIT);

        if ( l_err )
        {
            TRACFCOMP( g_trac_isteps_trace, ERR_MRK
                       "ERROR : p10_block_wakeup_intr(ENABLE_BLOCK_EXIT)"
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_err) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_core).addToLog( l_err );
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                       "SUCCESS : p10_block_wakeup_intr(ENABLE_BLOCK_EXIT)" );
        }
    }

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK
               "SUCCESS : p10_block_wakeup_intr(ENABLE_BLOCK_EXIT) on ALL cores");

    return l_err;
}  // blockInterrupts


//******************************************************************************
//                                LOCAL API
//******************************************************************************
//******************************************************************************
// verify_ipc_connection
//******************************************************************************
errlHndl_t verify_ipc_connection(ATTR_HB_EXISTING_IMAGE_type i_hbExistingImage)
{
    errlHndl_t l_err(nullptr);

    Target * l_sys = UTIL::assertGetToplevelTarget();

    do
    {
        // This l_msgQ catches the responses to messages sent from each
        // node to verify the IPC connection
        msg_q_t l_msgQ = msg_q_create();
        l_err = MBOX::msgq_register(MBOX::HB_COALESCE_MSGQ, l_msgQ);

        if (l_err)
        {
            TRACFCOMP( g_trac_isteps_trace, ERR_MRK
                       "call_host_coalesce_host:msgq_register failed"
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_err) );
            break;
        }

        // multi-node system
        auto l_nodeMap = l_sys->getAttrAsStdArr<ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>();

        uint64_t l_msgCount(0);

        // The assertion is that the hostboot instance must be equal to
        // the logical node we are running on. The ideal would be to have
        // a function call that would return the HB instance number.
        uint64_t l_thisNode = PIR_t::groupFromPir(PIR_t(task_getcpuid()));

        // Loop though all possible drawers whether they exist or not.
        // An invalid or non-existent logical node number in that drawer
        // indicates that the drawerCount does not exist.
        decltype(i_hbExistingImage)  l_mask = 0x0;
        decltype(i_hbExistingImage)  l_masterNodeMask = 0x0;

        for ( uint16_t l_drawerCount = 0;
              l_drawerCount < NUMBER_OF_POSSIBLE_DRAWERS;
              ++l_drawerCount)
        {
            uint16_t l_drawer = l_nodeMap[l_drawerCount];

            if (l_drawer < NUMBER_OF_POSSIBLE_DRAWERS)
            {
                // set l_mask to msb
                l_mask = 0x1 << (NUMBER_OF_POSSIBLE_DRAWERS -1);

                TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                           "mask=0x%02X, HB existing image=0x%02X",
                           l_mask, i_hbExistingImage);
                if ( 0 != ((l_mask >> l_drawerCount) & i_hbExistingImage ) )
                {
                    //The first nonzero bit in hb_existing_image represents the
                    // master node, set mask for later comparison
                    if (l_masterNodeMask == 0)
                    {
                        l_masterNodeMask = l_mask >> l_drawerCount;

                        TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                                   "master_node_mask=0x%X",l_masterNodeMask);
                    }

                    TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                               "send coalesce host message to drawer %d",
                               l_drawerCount );
                    ++l_msgCount;
                    msg_t * l_msg = msg_allocate();
                    l_msg->type = IPC::IPC_TEST_CONNECTION;
                    l_msg->data[0] = l_drawer;    // target drawer
                    l_msg->data[1] = l_thisNode;  // node to send a msg back to
                    l_err = MBOX::send(MBOX::HB_IPC_MSGQ, l_msg, l_drawer);
                    if (l_err)
                    {
                        TRACFCOMP( g_trac_isteps_trace, ERR_MRK"MBOX::send failed"
                                   TRACE_ERR_FMT,
                                   TRACE_ERR_ARGS(l_err) );
                        break;
                    }
                } // if( 0 != ((l_mask >> l_drawerCount) & hb_existing_image ) )
            } // if (l_drawer < NUMBER_OF_POSSIBLE_DRAWERS)
            else
            {
                TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                           "ATTR_FABRIC_TO_PHYSICAL_NODE_MAP is out of bounds, loop %d, drawer %x",
                           l_drawerCount, l_drawer);
            } // if (l_drawer < NUMBER_OF_POSSIBLE_DRAWERS) ... else ...
        } // for ( uint16_t l_drawerCount = 0; ...

        //if the send failed we just want to indicate that the
        //istep failed and not wait for messages to come back from
        //the other nodes
        if (nullptr == l_err)
        {
            // reset mask to msb
            l_mask = 0x1 << (NUMBER_OF_POSSIBLE_DRAWERS -1);
            //create mask to apply to hb_existing_image for this particular node
            l_mask = l_mask >> l_thisNode;

            if (l_masterNodeMask & (i_hbExistingImage & l_mask))
            {
                TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                           "Master Node detected, continue allowing istep messages to this node.");
                INITSERVICE::setAcceptIstepMessages(true);
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                           "This node is not the master node, no longer respond to istep messages.");
                INITSERVICE::setAcceptIstepMessages(false);
            }

            //wait for all hb images to respond
            //want to spawn a timer thread
            tid_t l_progTid = task_create(
                       ESTABLISH_SYSTEM_SMP::host_coalesce_timer,&l_msgQ);
            assert( l_progTid > 0 ,"host_coalesce_timer failed");
            while (l_msgCount)
            {
                msg_t* l_msg = msg_wait(l_msgQ);
                TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                           "coalesce host message for drawer %d completed.",
                           l_msg->data[0]);
                if (l_msg->type == HOST_COALESCE_TIMER_MSG)
                {
                    if (l_msg->data[1] == TIME_EXPIRED)
                    {
                        //timer has expired
                        TRACFCOMP( g_trac_isteps_trace, ERR_MRK
                                "call_host_coalesce_host failed to "
                                "receive messages from all hb images in time" );
                        //tell the timer thread to exit
                        l_msg->data[1] = HB_COALESCE_MSG_DONE;
                        msg_respond(l_msgQ, l_msg);

                        //generate an errorlog
                        /*@
                         *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                         *  @moduleid       fapi::MOD_VERIFY_IPC_CONNECTION
                         *  @reasoncode     fapi::RC_HOST_TIMER_EXPIRED
                         *  @userdata1      MAX_TIME_ALLOWED_MS
                         *  @userdata2      Number of nodes that have not
                         *                  responded
                         *
                         *  @devdesc        messages from other nodes have
                         *                  not returned in time
                         *  @custdesc       Error encountered during IPL of the system
                         */
                        l_err = new ErrlEntry( ERRL_SEV_CRITICAL_SYS_TERM,
                                               fapi::MOD_VERIFY_IPC_CONNECTION,
                                               fapi::RC_HOST_TIMER_EXPIRED,
                                               MAX_TIME_ALLOWED_MS,
                                               l_msgCount );
                        l_err->collectTrace("ISTEPS_TRACE");
                        l_err->collectTrace("IPC");
                        l_err->collectTrace("MBOXMSG");
                        break;

                    }
                    else if( l_msg->data[1] == CONTINUE_WAIT_FOR_MSGS)
                    {
                        TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                                   "coalesce host timer continue waiting message.");
                        l_msg->data[1] = HB_COALESCE_WAITING_FOR_MSG;
                        msg_respond(l_msgQ, l_msg);
                    }
                }
                else if (l_msg->type == IPC::IPC_TEST_CONNECTION)
                {
                   TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                              "Got response from node %d", l_msg->data[0] );
                    --l_msgCount;
                    msg_free(l_msg);
                }

            } // while (l_msgCount)

            if (l_err)
            {
                break;
            }

            //the l_msgCount should be 0 at this point to have
            //exited from the loop above.  If the msg count
            //is not zero then the timer must have expired
            //and the code would have asserted
            //Now need to tell the child timer thread to exit

            //temp change while simics takes a long time for Denali to IPL
            //tmp check to tell the child timer thread to exit if didn't
            //already timeout
            if (l_msgCount ==0)
            {
                msg_t* l_msg = msg_wait(l_msgQ);
                if (l_msg->type == HOST_COALESCE_TIMER_MSG)
                {
                    TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                               "call_host_coalesce_host received all hb images in time");

                    l_msg->data[1] = HB_COALESCE_MSG_DONE;
                    msg_respond(l_msgQ, l_msg);
                }
            } // if (l_msgCount ==0)

            // Wait for the child thread to end
            int l_childSts(0);
            void* l_childRc(nullptr);
            tid_t l_tidRetRc = task_wait_tid(l_progTid, &l_childSts, &l_childRc);
            if ( (static_cast<int16_t>(l_tidRetRc) < 0)  ||
                 (l_childSts != TASK_STATUS_EXITED_CLEAN ) )
            {
                // the launched task failed or crashed,
                TRACFCOMP( g_trac_isteps_trace, ERR_MRK
                           "task_wait_tid failed; l_tidRetRc=0x%x, l_childSts=0x%x",
                           l_tidRetRc, l_childSts);

                //generate an errorlog
                /*@
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       fapi::MOD_VERIFY_IPC_CONNECTION
                 *  @reasoncode     fapi::RC_HOST_TIMER_THREAD_FAIL
                 *  @userdata1      l_tidRetRc
                 *  @userdata2      l_childSts
                 *
                 *  @devdesc        host coalesce host timer thread failed
                 *  @custdesc       Error encountered during IPL of the system
                 */
                l_err = new ErrlEntry( ERRL_SEV_CRITICAL_SYS_TERM,
                                       fapi::MOD_VERIFY_IPC_CONNECTION,
                                       fapi::RC_HOST_TIMER_THREAD_FAIL,
                                       l_tidRetRc,
                                       l_childSts);

                l_err->collectTrace("ISTEPS_TRACE");
                break;
            }
        } // if (nullptr == l_err)

        MBOX::msgq_unregister(MBOX::HB_COALESCE_MSGQ);
        msg_q_destroy(l_msgQ);

        // Only set if multiple nodes are in play
        l_sys->setAttr<TARGETING::ATTR_EXTEND_TPM_MEAS_TO_OTHER_NODES>(true);
        TRACFCOMP(g_trac_isteps_trace, INFO_MRK
                  "Enabling x-node TPM measurement mirroring for node %d",
                  l_thisNode);

    } while (0);
    return l_err;
} // verify_ipc_connection


//******************************************************************************
// host_coalesce_timer
//******************************************************************************
void* host_coalesce_timer(void* i_msgQPtr)

{
    uint32_t l_rc(0);

    msg_t* l_msg = msg_allocate();
    l_msg->type = HOST_COALESCE_TIMER_MSG;
    uint32_t l_timeMs(0);

    msg_q_t* l_msgQ = static_cast<msg_q_t*>(i_msgQPtr);

    // This loop will be broken when the main thread receives
    // all the messages and the timer thread receives the
    // HB_COALESCE_MSG_DONE message
    do
    {
        if (l_timeMs < MAX_TIME_ALLOWED_MS)
        {
            l_msg->data[1] = CONTINUE_WAIT_FOR_MSGS;
        }
        else
        {
            // HOST_COALESCE_TIMER_MSG is sent to the main thread indicating
            // timer expired so the main thread responds back with HB_COALESCE_MSG_DONE
            // indicating the timer is not needed and exit the loop
            l_msg->data[1] = TIME_EXPIRED;
        }

        l_rc = msg_sendrecv(*l_msgQ, l_msg);
        if (l_rc)
        {
            TRACFCOMP( g_trac_isteps_trace, ERR_MRK
                       "coalesce host message timer failed msg sendrecv.");
        }

        if (l_msg->data[1] == HB_COALESCE_MSG_DONE)
        {
            TRACFCOMP( g_trac_isteps_trace, INFO_MRK
                       "coalesce host message timer not needed.");
            break;
        }

        nanosleep(0, NS_PER_MSEC);
        l_timeMs++;
    } while(1);

    msg_free(l_msg);

    return nullptr;
} // host_coalesce_timer

//******************************************************************************
// set_is_master_drawer
//******************************************************************************
void set_is_master_drawer(const EntityPath *i_masterEntityPath)
{
    // Figure out which node we are running on
    Target *l_masterProc(nullptr);
    targetService().masterProcChipTargetHandle(l_masterProc);

    const EntityPath::PathElement l_masterProcPathElement(l_masterProc->getAttr<ATTR_PHYS_PATH>().
                                                          pathElementOfType(TYPE_NODE) );

    const EntityPath::PathElement l_masterPathElement(i_masterEntityPath->pathElementOfType(TYPE_NODE));

    // get current node
    TargetHandleList l_nodelist;
    getEncResources(l_nodelist, TYPE_NODE, UTIL_FILTER_FUNCTIONAL);
    assert(l_nodelist.size() == 1, "ERROR, only looking for one node.");

    Target *l_currentNodeTarget(l_nodelist[0]);

    if (l_masterProcPathElement.instance == l_masterPathElement.instance)
    {
        // Current node is master, unset IS_SLAVE_DRAWER
        l_currentNodeTarget->setAttr<ATTR_IS_SLAVE_DRAWER>(0);
    }
    else
    {
        // Current node is not master, set IS_SLAVE_DRAWER
        l_currentNodeTarget->setAttr<ATTR_IS_SLAVE_DRAWER>(1);
    }
} // set_is_master_drawer

};   // end namespace
