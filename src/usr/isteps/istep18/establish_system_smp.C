/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/establish_system_smp.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#include    <stdint.h>
#include <sys/time.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <istep_mbox_msgs.H>
#include    <vfs/vfs.H>
#include    <config.h>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/attributes.H>

//  fapi support

#include <fapi2.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <arch/pirformat.H>
#include <isteps/hwpf_reasoncodes.H>


#include    <mbox/ipc_msg_types.H>
#include    <intr/interrupt.H>


//  Uncomment these files as they become available:
// #include    "host_coalesce_host/host_coalesce_host.H"
#include <p9_block_wakeup_intr.H>
#include <initservice/istepdispatcherif.H>
#include <isteps/hwpf_reasoncodes.H>

#include    "smp_unfencing_inter_enclosure_abus_links.H"

#include    "establish_system_smp.H"


namespace   ESTABLISH_SYSTEM_SMP
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


//******************************************************************************
//host_coalesce_timer function
//******************************************************************************
void* host_coalesce_timer(void* i_msgQPtr)

{
    int rc=0;

    msg_t* msg = msg_allocate();
    msg->type = HOST_COALESCE_TIMER_MSG;
    uint32_t l_time_ms =0;

    msg_q_t* msgQ = static_cast<msg_q_t*>(i_msgQPtr);


    //this loop will be broken when the main thread receives
    //all the messages and the timer thread receives the
    //HB_COALESCE_MSG_DONE message

    do
    {
        if (l_time_ms < MAX_TIME_ALLOWED_MS)
        {
            msg->data[1] = CONTINUE_WAIT_FOR_MSGS;
        }
        else
        {
            // HOST_COALESCE_TIMER_MSG is sent to the main thread indicating
            // timer expired so the main thread responds back with HB_COALESCE_MSG_DONE
            // indicating the timer is not needed and exit the loop
            msg->data[1]=TIME_EXPIRED;
        }

        rc= msg_sendrecv(*msgQ, msg);
        if (rc)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "coalesce host message timer failed msg sendrecv.");
        }
        if (msg->data[1] == HB_COALESCE_MSG_DONE)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "coalesce host message timer not needed.");
            break;
        }

        nanosleep(0,NS_PER_MSEC);
        l_time_ms++;

    }while(1);

    msg_free(msg);

    return NULL;
}

//******************************************************************************
// call_host_coalesce_host function
//******************************************************************************
errlHndl_t call_host_coalesce_host( )
{
    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_coalesce_host entry" );

    std::vector<TARGETING::EntityPath> present_drawers;


    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    if (sys == NULL)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_coalesce_host: error getting system target");
        assert(0, "call_host_coalesce_host system target is NULL");
    }

    TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_existing_image = 0;

    hb_existing_image = sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

    if (hb_existing_image == 0)
    {
        //single node system so do nothing
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_coalesce_host on a single node system is a no-op" );
    }
    else
    {

        // This msgQ catches the responses to messages sent from each
        //node to verify the IPC connection
        msg_q_t msgQ = msg_q_create();
        l_errl = MBOX::msgq_register(MBOX::HB_COALESCE_MSGQ,msgQ);

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "call_host_coalesce_host:msgq_register failed" );
            return l_errl;
        }

        //multi-node system
        uint8_t node_map[NUMBER_OF_POSSIBLE_DRAWERS];
        uint64_t msg_count = 0;

        bool rc = sys->tryGetAttr<TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>
            (node_map);
        if (rc == false)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "call_host_coalesce_host:failed to get node map" );
            assert(0,"call_host_coalesce_host:failed to get node map");
        }

        // The assertion is that the hostboot instance must be equal to
        // the logical node we are running on. The ideal would be to have
        // a function call that would return the HB instance number.
        uint64_t this_node = PIR_t(task_getcpuid()).groupId;

        //loop though all possible drawers whether they exist or not
        // An invalid or non-existent logical node number in that drawer
        // indicates that the drawerCount does not exist.
        TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x0;
        TARGETING::ATTR_HB_EXISTING_IMAGE_type master_node_mask = 0x0;

        for(uint16_t drawerCount = 0; drawerCount < NUMBER_OF_POSSIBLE_DRAWERS; ++drawerCount)
        {
            uint16_t drawer = node_map[drawerCount];

            if(drawer < NUMBER_OF_POSSIBLE_DRAWERS)
            {

                // set mask to msb
                mask = 0x1 <<
                    (NUMBER_OF_POSSIBLE_DRAWERS -1);

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "mask=%X,hb_existing_image=%X",
                           mask,hb_existing_image);
                if( 0 != ((mask >> drawerCount) & hb_existing_image ) )
                {
                    //The first nonzero bit in hb_existing_image represents the
                    // master node, set mask for later comparison
                    if (master_node_mask == 0)
                    {
                        master_node_mask = mask;
                    }
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "send coalesce host message to drawer %d",
                               drawerCount );
                    ++msg_count;
                    msg_t * msg = msg_allocate();
                    msg->type = IPC::IPC_TEST_CONNECTION;
                    msg->data[0] = drawer;     // target drawer
                    msg->data[1] = this_node;  // node to send a msg back to
                    l_errl = MBOX::send(MBOX::HB_IPC_MSGQ, msg, drawer);
                    if (l_errl)
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "MBOX::send failed");
                        break;
                    }
                }
            } else{
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ATTR_FABRIC_TO_PHYSICAL_NODE_MAP is out of bounds, loop %d, drawer %x",
                           drawerCount, drawer);
            }
        }

        //if the send failed we just want to indicate that the
        //istep failed and not wait for messages to come back from
        //the other nodes
        if(l_errl == NULL)
        {
            // reset mask to msb
            mask = 0x1 << (NUMBER_OF_POSSIBLE_DRAWERS -1);
            //create mask to apply to hb_existing_image for this particular node
            mask = mask >> this_node;

            if (master_node_mask & (hb_existing_image & mask))
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "Master Node detected, continue allowing "
                               "istep messages to this node.");
                INITSERVICE::setAcceptIstepMessages(true);
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "This node is not the master node, no longer "
                               "respond to istep messages.");
                INITSERVICE::setAcceptIstepMessages(false);
            }

            //wait for all hb images to respond
            //want to spawn a timer thread
            tid_t l_progTid = task_create(
                       ESTABLISH_SYSTEM_SMP::host_coalesce_timer,&msgQ);
            assert( l_progTid > 0 ,"host_coalesce_timer failed");
            while(msg_count)
            {
                msg_t* msg = msg_wait(msgQ);
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "coalesce host message for drawer %d completed.",
                         msg->data[0]);
                if (msg->type == HOST_COALESCE_TIMER_MSG)
                {
                    if (msg->data[1] == TIME_EXPIRED)
                    {
                        //timer has expired
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "call_host_coalesce_host failed to "
                                "receive messages from all hb images in time" );
                        //tell the timer thread to exit
                        msg->data[1] = HB_COALESCE_MSG_DONE;
                        msg_respond(msgQ,msg);

                        //generate an errorlog
                        /*@
                         *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                         *  @moduleid       fapi::MOD_HOST_COALESCE_HOST,
                         *  @reasoncode     fapi::RC_HOST_TIMER_EXPIRED,
                         *  @userdata1      MAX_TIME_ALLOWED_MS
                         *  @userdata2      Number of nodes that have not
                         *                  responded
                         *
                         *  @devdesc        messages from other nodes have
                         *                  not returned in time
                         */
                        l_errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                        fapi::MOD_HOST_COALESCE_HOST,
                                        fapi::RC_HOST_TIMER_EXPIRED,
                                        MAX_TIME_ALLOWED_MS,
                                        msg_count   );
                        l_errl->collectTrace("ISTEPS_TRACE");
                        l_errl->collectTrace("IPC");
                        l_errl->collectTrace("MBOXMSG");
                        return l_errl;

                    }
                    else if( msg->data[1] == CONTINUE_WAIT_FOR_MSGS)
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "coalesce host timer continue waiting message.");
                        msg->data[1] =HB_COALESCE_WAITING_FOR_MSG;
                        msg_respond(msgQ,msg);
                    }
                }
                else if (msg->type == IPC::IPC_TEST_CONNECTION)
                {
                   TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                              "Got response from node %d", msg->data[0] );
                    --msg_count;
                    msg_free(msg);
                }

            }

            //the msg_count should be 0 at this point to have
            //exited from the loop above.  If the msg count
            //is not zero then the timer must have expired
            //and the code would have asserted
            //Now need to tell the child timer thread to exit

            //temp change while simics takes a long time for FLEETWOOD to IPL
            //tmp check to tell the child timer thread to exit if didn't
            //already timeout
            if (msg_count ==0)
            {
                msg_t* msg = msg_wait(msgQ);
                if (msg->type == HOST_COALESCE_TIMER_MSG)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "call_host_coalesce_host received all hb "
                            "images in time");

                    msg->data[1] = HB_COALESCE_MSG_DONE;
                    msg_respond(msgQ,msg);
                }
            }

            //wait for the child thread to end
            int l_childsts =0;
            void* l_childrc = NULL;
            tid_t l_tidretrc = task_wait_tid(l_progTid,&l_childsts,&l_childrc);
            if ((static_cast<int16_t>(l_tidretrc) < 0)
                || (l_childsts != TASK_STATUS_EXITED_CLEAN ))
            {
                // the launched task failed or crashed,
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "task_wait_tid failed; l_tidretrc=0x%x, l_childsts=0x%x",
                    l_tidretrc, l_childsts);

                        //generate an errorlog
                        /*@
                         *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                         *  @moduleid       fapi::MOD_HOST_COALESCE_HOST,
                         *  @reasoncode     fapi::RC_HOST_TIMER_THREAD_FAIL,,
                         *  @userdata1      l_tidretrc,
                         *  @userdata2      l_childsts,
                         *
                         *  @devdesc        host coalesce host timer thread
                         *                  failed
                         */
                        l_errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                        fapi::MOD_HOST_COALESCE_HOST,
                                        fapi::RC_HOST_TIMER_THREAD_FAIL,
                                        l_tidretrc,
                                        l_childsts);

                        l_errl->collectTrace("ISTEPS_TRACE");
                        return l_errl;
            }
        }

        MBOX::msgq_unregister(MBOX::HB_COALESCE_MSGQ);
        msg_q_destroy(msgQ);


    }



    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_coalesce_host exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_errl;
}

//******************************************************************************
// host_sys_fab_iovalid_processing function
//******************************************************************************
void *host_sys_fab_iovalid_processing(void* io_ptr )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_sys_fab_iovalid_processing entry" );
    // input parameter is actually a msg_t pointer
    msg_t* io_pMsg = static_cast<msg_t *>(io_ptr);
    // assume success, unless we hit an error later.
    io_pMsg->data[0] = INITSERVICE::HWSVR_MSG_SUCCESS;

    // if there is extra data, start processing it
    if(io_pMsg->extra_data)
    {
        iovalid_msg * drawerData = (iovalid_msg *)io_pMsg->extra_data;

        // setup a pointer to the first drawer entry in our data
        TARGETING::EntityPath * ptr = drawerData->drawers;

        const uint16_t drawerCount = drawerData->count;
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Master node %s List size = %d bytes Drawer count = %d",
                ptr->toString(), drawerData->size, drawerCount);

        // get FABRIC_TO_PHYSICAL_NODE_MAP
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL,"host_sys_fab_iovalid_processing system target is NULL");

        uint8_t node_map[8];
        bool rc = sys->tryGetAttr<TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>
                    (node_map);
        assert(rc == true,"host_sys_fab_iovalid_processing:failed to get node map");

        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_existing_image = 0;

        // create a vector with the present drawers
        std::vector<TARGETING::EntityPath> present_drawers;

        for(uint8_t i = 0; i < drawerCount; i++)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "list entry[%d] - %s", i, ptr->toString());

            present_drawers.push_back(*ptr);

            TARGETING::EntityPath::PathElement pe =
                ptr->pathElementOfType(TARGETING::TYPE_NODE);

            // pe.instance is the drawer number - convert to logical node
            uint8_t logical_node = node_map[pe.instance];

            // set mask to msb of bitmap
            TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
                (NUMBER_OF_POSSIBLE_DRAWERS -1);

            // set bit for this logical node.
            hb_existing_image |= (mask >> logical_node);

            ptr++;
        }

        sys->setAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>(hb_existing_image);

        // after agreement, open a-busses as required
        // @TODO RTC:187337 -- HB doesn't have the knowledge of attributes that
        // p9_fab_iovalid requires at the moment. Currently, this is being called
        // from the FSP. We need to figure out a way to gather that info from the
        // FSP and re-enable this piece of code.
//        l_errl = EDI_EI_INITIALIZATION::smp_unfencing_inter_enclosure_abus_links();
//        if (l_errl)
//        {
//            io_pMsg->data[0] = l_errl->plid();
//            errlCommit(l_errl, HWPF_COMP_ID);
//        }
    }
    else
    {
        // message needs to have at least one entry
        // in the drawer list, else we will say invalid msg
        io_pMsg->data[0] = INITSERVICE::HWSVR_INVALID_MESSAGE;
    }

    io_pMsg->data[1] = 0;

    // response will be sent by calling routine
    // IStepDispatcher::handleProcFabIovalidMsg()
    // which will also execute the procedure to winkle all cores

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_sys_fab_iovalid_processing exit data[0]=0x%X",
            io_pMsg->data[0]);
    return NULL;
}


errlHndl_t blockInterrupts()
{
    errlHndl_t l_errl = NULL;

    // Get all functional core units
    TARGETING::TargetHandleList l_coreList;
    getAllChiplets(l_coreList, TYPE_CORE);

    for (auto l_core : l_coreList)
    {

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Running p9_block_wakeup_intr(SET) on EX target HUID %.8X",
            TARGETING::get_huid(l_core));

        fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapi2_core_target(l_core);

        FAPI_INVOKE_HWP(l_errl,
                        p9_block_wakeup_intr,
                        l_fapi2_core_target,
                        p9pmblockwkup::SET);
        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : p9_block_wakeup_intr(SET)" );
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_core).addToLog( l_errl );
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : p9_block_wakeup_intr(SET)" );
        }
    }
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS : p9_block_wakeup_intr(SET) on ALL cores" );

    return l_errl;
}

};   // end namespace
