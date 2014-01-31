/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/establish_system_smp/establish_system_smp.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <istep_mbox_msgs.H>
#include    <vfs/vfs.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <smp_unfencing_inter_enclosure_abus_links.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/attributes.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/hwpf_reasoncodes.H>

#include    "establish_system_smp.H"
#include    <mbox/ipc_msg_types.H>
#include    <intr/interrupt.H>

//  Uncomment these files as they become available:
// #include    "host_coalesce_host/host_coalesce_host.H"
#include    "p8_block_wakeup_intr/p8_block_wakeup_intr.H"

namespace   ESTABLISH_SYSTEM_SMP
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   EDI_EI_INITIALIZATION;

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
const uint8_t HB_COALESCE_WAITING_FOR_MSG = 0x0;
const uint8_t HB_COALESCE_MSG_DONE = 0x1;
const uint32_t MAX_TIME_ALLOWED_MS = 10000;
const uint8_t NUMBER_OF_POSSIBLE_NODES = 8;
const uint8_t CONTINUE_WAIT_FOR_MSGS = 0x2;
const uint8_t TIME_EXPIRED=0x3;

//******************************************************************************
//host_coalese_timer function
//******************************************************************************
void* host_coalese_timer(void* i_msgQPtr)

{
    int rc=0;

    msg_t* msg = msg_allocate();
    msg->type = HOST_COALESCE_TIMER_MSG;
    uint32_t l_time_ms =0;

    msg_q_t* msgQ = static_cast<msg_q_t*>(i_msgQPtr);


    //this loop will be broken when the main thread recieves
    //all the messages and the timer thread recieves the
    //HB_COALESCE_MSG_DONE message

    do
    {
        if (l_time_ms < MAX_TIME_ALLOWED_MS)
        {
            msg->data[1] = CONTINUE_WAIT_FOR_MSGS;
        }
        else
        {
            msg->data[1]=TIME_EXPIRED;
        }

        rc= msg_sendrecv(*msgQ, msg);
        if (rc)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "coalese host message timer failed msg sendrecv.");
        }
        if (msg->data[1] == HB_COALESCE_MSG_DONE)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "coalese host message timer not needed.");
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
        assert(0);
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

        // This msgQ catches the reponses to messages sent from each
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
        uint8_t node_map[NUMBER_OF_POSSIBLE_NODES];
        uint64_t msg_count = 0;

        bool rc =
            sys->tryGetAttr<TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>
            (node_map);
        if (rc == false)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "call_host_coalesce_host:failed to get node map" );
            assert(0);
        }

        // The assertion is that the hostboot instance must be equal to
        // the logical node we are running on. The ideal would be to have
        // a function call that would return the HB instance number.
        const INTR::PIR_t masterCpu = task_getcpuid();
        uint64_t this_node = masterCpu.nodeId;


        //loop though all possible drawers whether they exist or not
        // An invalid or non-existant logical node number in that drawer
        // indicates that the drawer does not exist.

        TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x0;

        for(uint16_t drawer = 0; drawer < NUMBER_OF_POSSIBLE_NODES; ++drawer)
        {
            uint16_t node = node_map[drawer];

            if(node < NUMBER_OF_POSSIBLE_NODES)
            {

                // set mask to msb
                mask = 0x1 <<
                    (NUMBER_OF_POSSIBLE_NODES -1);

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "mask=%X,hb_existing_image=%X",
                           mask,hb_existing_image);
                if( 0 != ((mask >> node) & hb_existing_image ) )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "send coalese host message to drawer %d",
                               drawer );
                    ++msg_count;
                    msg_t * msg = msg_allocate();
                    msg->type = IPC::IPC_TEST_CONNECTION;
                    msg->data[0] = drawer;     // target drawer
                    msg->data[1] = this_node;  // node to send a msg back to
                    l_errl = MBOX::send(MBOX::HB_IPC_MSGQ, msg, node);
                    if (l_errl)
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "MBOX::send failed");
                        break;
                    }
                }
            }
        }

        //if the send failed we just want to indicate that the
        //istep failed and not wait for messages to come back from
        //the other nodes
        if(l_errl == NULL)
        {
            //wait for all hb images to respond
            //want to spawn a timer thread
            tid_t l_progTid = task_create(
                       ESTABLISH_SYSTEM_SMP::host_coalese_timer,&msgQ);
            assert( l_progTid > 0 );
            while(msg_count)
            {
                msg_t* msg = msg_wait(msgQ);
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "coalese host message for drawer %d completed.",
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
                            "coalese host timer continue waiting message.");
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

            //temp change while simics takes a long time for BRAZOS to IPL
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

    errlHndl_t l_errl = NULL;

    // if there is extra data, start processing it
    if(io_pMsg->extra_data)
    {
        iovalid_msg * drawerData = (iovalid_msg *)io_pMsg->extra_data;

        // setup a pointer to the first drawer entry in our data
        TARGETING::EntityPath * ptr = drawerData->drawers;

        const uint16_t count = drawerData->count;
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Master node %s List size = %d bytes Drawer count = %d",
                ptr->toString(), drawerData->size, count);

        // get FABRIC_TO_PHYSICAL_NODE_MAP
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        uint8_t node_map[8];
        bool rc = sys->tryGetAttr<TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>
                    (node_map);
        assert(rc == true);

        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_existing_image = 0;

        // create a vector with the present drawers
        std::vector<TARGETING::EntityPath> present_drawers;

        for(uint8_t i = 0; i < count; i++)
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
                (NUMBER_OF_POSSIBLE_NODES -1);

            // set bit for this logical node.
            hb_existing_image |= (mask >> logical_node);

            ptr++;
        }

        sys->setAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>(hb_existing_image);

        // $TODO RTC:63128 - exchange between present drawers to agree
        // on valid endpoints
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "$TODO RTC:63128 - hb instances exchange and agree on cfg");

        // after agreement, open abuses as required
        l_errl = smp_unfencing_inter_enclosure_abus_links();
        if (l_errl)
        {
            io_pMsg->data[0] = l_errl->plid();
            errlCommit(l_errl, HWPF_COMP_ID);
        }
    }
    else
    {
        // message needs to have at least one entry
        // in the drawer list, else we will say invalid msg
        io_pMsg->data[0] = INITSERVICE::HWSVR_INVALID_MESSAGE;
    }

    io_pMsg->data[1] = 0;

    // if there wasn't an error
    if (io_pMsg->data[0] == INITSERVICE::HWSVR_MSG_SUCCESS)
    {
        uint32_t l_plid = 0;

        // loop thru all proc and find all functional ex units
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);
        for (TargetHandleList::const_iterator l_procIter =
             l_procTargetList.begin();
             l_procIter != l_procTargetList.end();
             ++l_procIter)
        {
            const TARGETING::Target* l_pChipTarget = *l_procIter;

            // Get EX list under this proc
            TARGETING::TargetHandleList l_exList;
            getChildChiplets( l_exList, l_pChipTarget, TYPE_EX );

            for (TargetHandleList::const_iterator
                l_exIter = l_exList.begin();
                l_exIter != l_exList.end();
                ++l_exIter)
            {
                const TARGETING::Target * l_exTarget = *l_exIter;
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running p8_block_wakeup_intr(SET) on EX target HUID %.8X",
                    TARGETING::get_huid(l_exTarget));

                fapi::Target l_fapi_ex_target( TARGET_TYPE_EX_CHIPLET,
                         (const_cast<TARGETING::Target*>(l_exTarget)) );

                FAPI_INVOKE_HWP(l_errl,
                                p8_block_wakeup_intr,
                                l_fapi_ex_target,
                                BLKWKUP_SET);
                if ( l_errl )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR : p8_block_wakeup_intr(SET)" );
                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_exTarget).addToLog( l_errl );
                    if (l_plid != 0)
                    {
                        // use the same plid as the previous
                        l_errl->plid(l_plid);
                    }
                    else
                    {
                        // set this plid for the caller to see
                        l_plid = l_errl->plid();
                        io_pMsg->data[0] = l_errl->plid();
                    }
                    errlCommit( l_errl, HWPF_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "SUCCESS : p8_block_wakeup_intr(SET)" );
                }
            } // for ex
        } // for proc
    }

    // response will be sent by calling routine
    // IStepDispatcher::handleProcFabIovalidMsg()
    // which will also execute the procedure to winkle all cores

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_sys_fab_iovalid_processing exit data[0]=0x%X",
            io_pMsg->data[0]);
    return NULL;
}

};   // end namespace
