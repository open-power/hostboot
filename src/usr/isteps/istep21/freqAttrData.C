/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/freqAttrData.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
 * @file freqAttrSync.C
 * @brief Interrupt Resource Provider
 */

#include "freqAttrData.H"
#include <trace/interface.H>
#include <errno.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <isteps/hwpf_reasoncodes.H>
#include <util/singleton.H>
#include <kernel/ipc.H>
#include <sys/task.h>
#include <vmmconst.h>
#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include <devicefw/userif.H>
#include <sys/time.h>
#include <sys/vfs.h>
#include <arch/ppc.H>
#include <mbox/ipc_msg_types.H>
#include <fapi2/plat_hwp_invoker.H>
#ifndef CONFIG_VPO_COMPILE
#include <p10_check_freq_compat.H>
#include <p10_get_freq_compat_settings.H>
#endif
#include <errl/errluserdetails.H>
#include <errl/errludtarget.H>
#include <targeting/targplatutil.H>
#include <errl/errlreasoncodes.H>

#define INTR_TRACE_NAME INTR_COMP_NAME

using namespace TARGETING;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;

namespace ISTEP_21
{
void* sendFreqAttrData_timer(void* i_msgQPtr)

{
    int rc=0;

    msg_t* msg = msg_allocate();
    msg->type = HB_FREQ_ATTR_DATA_TIMER_MSG;
    uint32_t l_time_ms =0;

    msg_q_t* msgQ = static_cast<msg_q_t*>(i_msgQPtr);


    //this loop will be broken when the main thread receives
    //all the messages and the timer thread receives the
    //HB_FREQ_ATTR_DATA_MSG_DONE message

    do
    {

        if (l_time_ms < MAX_TIME_ALLOWED_MS)
        {
            msg->data[1] = CONTINUE_WAIT_FOR_MSGS;
        }
        else
        {
            // HB_FREQ_ATTR_DATA_TIMER_MSG is sent to the main thread indicating
            // timer expired so the main thread responds back with HB_FREQ_ATTR_DATA_MSG_DONE
            // indicating the timer is not needed and exit the loop
            msg->data[1]=TIME_EXPIRED;

        }

        rc= msg_sendrecv(*msgQ, msg);

        if (rc)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "sendFreqAttrData_timer failed msg sendrecv.");
        }
        if (msg->data[1] == HB_FREQ_ATTR_DATA_MSG_DONE)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "sendFreqAttrData_timer not needed.");
            break;
        }

        nanosleep(0,NS_PER_MSEC);
        l_time_ms++;

    }while(1);

    msg_free(msg);

    return NULL;
}

errlHndl_t sendFreqAttrData()
{
    errlHndl_t  l_elog = nullptr;
    tid_t l_progTid = 0;

    do {

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "sendFreqAttrData" );

        TARGETING::Target * sys = nullptr;

        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != nullptr);

        // Figure out which node we are running on
        TARGETING::Target* mproc = nullptr;

        TARGETING::targetService().masterProcChipTargetHandle(mproc);

        TARGETING::EntityPath epath = mproc->getAttr<TARGETING::ATTR_PHYS_PATH>();

        const TARGETING::EntityPath::PathElement pe =
          epath.pathElementOfType(TARGETING::TYPE_NODE);

        uint32_t nodeid = pe.instance;

        // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
        // Currently set up in host_sys_fab_iovalid_processing() which only
        // gets called if there are multiple physical nodes.   It eventually
        // needs to be setup by a hb routine that snoops for multiple nodes.
        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
          sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "sendFreqAttrData hb_images = 0x%x, nodeid = 0x%x", hb_images, nodeid);

        if(0 == hb_images)
        {
            // Single node system
            break;
        }

        // multi-node system
        // This msgQ catches the node responses from the commands
        msg_q_t msgQ = msg_q_create();
        l_elog = MBOX::msgq_register(MBOX::HB_FREQ_ATTR_DATA_MSGQ,msgQ);
        if(l_elog)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "sendFreqAttrData MBOX::msgq_register failed!" );
            break;
        }

        // keep track of the number of messages we send so we
        // know how many responses to expect
        uint64_t msg_count = 0;


#ifndef CONFIG_VPO_COMPILE
        // loop thru rest all nodes -- sending msg to each
        TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
          ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);
        uint32_t pstate = 0;

        // Convert target to fapi2 target
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_fapi_sys_target(sys);
        FAPI_INVOKE_HWP(l_elog, p10_get_freq_compat_settings, l_fapi_sys_target, &pstate);
        if (l_elog)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "sendFreqAttrData::p10_get_freq_compat_settings failed on HUID 0x%08x. "
                    TRACE_ERR_FMT,
                    get_huid(mproc),
                    TRACE_ERR_ARGS(l_elog));
            ErrlUserDetailsTarget(mproc).addToLog(l_elog);
            break;
        }

        for (uint32_t l_node=0; (l_node < MAX_NODES_PER_SYS ); l_node++ )
        {
            // skip sending to ourselves
            if(l_node == nodeid)
            {
                continue;
            }

            if( 0 != ((mask >> l_node) & hb_images ) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "send IPC_FREQ_ATTR_DATA "
                           "message to node %d",l_node );


                msg_t * msg = msg_allocate();

                msg->type = IPC::IPC_FREQ_ATTR_DATA;

                // pack destination node and master node in msg->data[0]
                msg->data[0] = TWO_UINT32_TO_UINT64(l_node, nodeid);

                msg->data[1] = pstate;

                l_elog = MBOX::send(MBOX::HB_IPC_MSGQ, msg, l_node);

                if (l_elog)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "MBOX::send IPC_FREQ_ATTR_DATA to node %d"
                              " failed", l_node);
                    ErrlUserDetailsTarget(mproc).addToLog(l_elog);
                    break;
                }

                ++msg_count;

            } // end if node to process
        } // end for loop on nodes

#endif
        if(l_elog)
        {
            break;
        }
        //wait for all hb images to respond
        //want to spawn a timer thread
        l_progTid = task_create(sendFreqAttrData_timer,&msgQ);

        assert( l_progTid > 0 ,"sendFreqAttrData_timer failed");

        while(msg_count)
        {
            msg_t* response = msg_wait(msgQ);

            if (response->type == HB_FREQ_ATTR_DATA_TIMER_MSG)
            {
                if (response->data[1] == TIME_EXPIRED)
                {
                    //timer has expired
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "IPC_FREQ_ATTR_DATA failed to "
                            "receive messages from all hb images in time" );
                    //tell the timer thread to exit
                    response->data[1] = HB_FREQ_ATTR_DATA_MSG_DONE;
                    msg_respond(msgQ,response);

                    // @Todo RTRC:192370 Add node specific info
                    // Include the number of nodes,  number of non-responses (bit masks)
                    // to know exactly which nodes didn't answer and which did

                    //generate an errorlog
                    /*@
                     *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                     *  @moduleid       ISTEP::MOD_FREQ_ATTR_DATA,
                     *  @reasoncode     ISTEP::RC_FREQ_ATTR_TIMER_EXPIRED,
                     *  @userdata1      MAX_TIME_ALLOWED_MS
                     *  @userdata2      Number of nodes that have not
                     *                  responded
                     *
                     *  @devdesc        messages from other nodes have
                     *                  not returned in time
                     *  @custdesc       An internal firmware error occurred
                     */
                    l_elog = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    ISTEP::MOD_FREQ_ATTR_DATA,
                                    ISTEP::RC_FREQ_ATTR_TIMER_EXPIRED,
                                    MAX_TIME_ALLOWED_MS,
                                    msg_count   );
                    l_elog->collectTrace("ISTEPS_TRACE");
                    l_elog->collectTrace("IPC");
                    l_elog->collectTrace("MBOXMSG");

                    l_elog->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);

                    // Break the While loop and wait for the child thread to exit
                    break;

                }
                else if( response->data[1] == CONTINUE_WAIT_FOR_MSGS)
                {
                    response->data[1] = HB_FREQ_ATTR_DATA_WAITING_FOR_MSG;
                    msg_respond(msgQ,response);
                }
            }
            else if (response->type == IPC::IPC_FREQ_ATTR_DATA)
            {
               TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "sendFreqAttrData Got response from node %d", response->data[0]>>32 );
                --msg_count;
                msg_free(response);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "sendFreqAttrData_timer : unexpected message from drawer %d ",
                    response->data[0]>>32);
            }

        }

        if(l_elog)
        {
            break;
        }


        //the msg_count should be 0 at this point to have
        //exited from the loop above.  If the msg count
        //is not zero then the timer must have expired.
        //Now need to tell the child timer thread to exit

        //simics takes a long time for FLEETWOOD to IPL
        //A check to tell the child timer thread to exit if didn't
        //already timeout
        if (msg_count == 0)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "IPC_FREQ_ATTR_DATA msg_count: %d", msg_count);

            msg_t* response = msg_wait(msgQ);

            if (response->type == HB_FREQ_ATTR_DATA_TIMER_MSG)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "IPC_FREQ_ATTR_DATA received from all hb "
                        "images in time");

                response->data[1] = HB_FREQ_ATTR_DATA_MSG_DONE;
                msg_respond(msgQ,response);
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
                     *  @moduleid       ISTEP::MOD_FREQ_ATTR_DATA,
                     *  @reasoncode     ISTEP::RC_FREQ_ATTR_TIMER_THREAD_FAIL,
                     *  @userdata1      l_tidretrc,
                     *  @userdata2      l_childsts,
                     *
                     *  @devdesc        Freq attribute DATA timer thread
                     *                  failed
                     *  @custdesc       An internal firmware error occurred
                     */
                    l_elog = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    ISTEP::MOD_FREQ_ATTR_DATA,
                                    ISTEP::RC_FREQ_ATTR_TIMER_THREAD_FAIL,
                                    l_tidretrc,
                                    l_childsts);

                    l_elog->collectTrace("ISTEPS_TRACE");

                    l_elog->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);

                    errlCommit(l_elog, HWPF_COMP_ID);

        }

        MBOX::msgq_unregister(MBOX::HB_FREQ_ATTR_DATA_MSGQ);
        msg_q_destroy(msgQ);

    } while(0);

    return(l_elog);
}

errlHndl_t callCheckFreqAttrData(uint64_t i_pstate0)
{
    errlHndl_t l_elog = nullptr;
#ifndef CONFIG_VPO_COMPILE
    // Get current node
    TARGETING::Target * l_sys = TARGETING::UTIL::assertGetToplevelTarget();
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_fapi_sys_target(l_sys);

    // Validate pstate and other attributes
    FAPI_INVOKE_HWP(l_elog, p10_check_freq_compat, l_fapi_sys_target, i_pstate0);

    if (l_elog)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "p10_check_freq_compat failed on HUID 0x%08x with pstate = %d"
                TRACE_ERR_FMT,
                get_huid(l_sys),
                i_pstate0,
                TRACE_ERR_ARGS(l_elog));

        TargetHandleList procList;

        // Get the child proc chips
        getChildAffinityTargets(procList,
                l_sys,
                CLASS_CHIP,
                TYPE_PROC);

        for (const auto & proc: procList)
        {
            l_elog->addHwCallout(proc,
                    HWAS::SRCI_PRIORITY_MEDA,
                    HWAS::NO_DECONFIG,
                    HWAS::GARD_NULL);
        }

        l_elog->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_LOW);

        l_elog->addProcedureCallout(HWAS::EPUB_PRC_INVALID_PART,
                                    HWAS::SRCI_PRIORITY_HIGH);

        l_elog->collectTrace("ISTEPS_TRACE");
    }
#endif
    return l_elog;
}

}
