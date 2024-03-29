/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/attnsvc.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
 * @file attnsvc.C
 *
 * @brief HBATTN background service class function definitions.
 */

#include <sys/msg.h>
#include <errl/errlmanager.H>
#include "ipl/attnsvc.H"
#include "common/attntrace.H"
#include "common/attnprd.H"
#include "common/attnproc.H"
#include "common/attntarget.H"
#include "arch/pirformat.H"
#include "diag/attn/attnreasoncodes.H"
#include <initservice/initserviceif.H>  // for hostboot TI
#include <util/singleton.H>

// Custom compile configs

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

errlHndl_t Service::configureInterrupts(
        msg_q_t i_q,
        ConfigureMode i_mode)
{
    errlHndl_t err = NULL;

    do
    {
        // First register for Q
        // This will set up the psi host bridge logic for
        // lcl_err interrupt on all chips

        if(i_mode == UP)
        {
            err = INTR::registerMsgQ(i_q,
                                     ATTENTION,
                                     INTR::ISN_LCL_ERR);
        }

        if(err)
        {
            ATTN_ERR("INTR::registerMsgQ returned error");
            break;
        }

        // enable/disable attentions
        err = ServiceCommon::configureInterrupts(i_mode);
        if(err)
        {
            ATTN_ERR("ServiceCommon::configureInterrupts "
                     "returned error i_mode: 0x%x", i_mode);
            break;
        }

        if(!err && i_mode == DOWN)
        {
            if(NULL == INTR::unRegisterMsgQ(INTR::LSI_LCL_FIR))
            {
                ATTN_ERR("INTR did not find LSI: 0x%07x",
                        INTR::LSI_LCL_FIR);
            }
        }

    } while(0);

    return err;
}


void* Service::intrTaskWorker(void * i_svc)
{
    // interrupt task loop
    Service & svc = *static_cast<Service *>(i_svc);
    bool shutdown = false;
    msg_t * msg = NULL;

    while(true)
    {
        // wait for a shutdown message or interrupt

        shutdown = svc.intrTaskWait(msg);

        if(shutdown)
        {
            break;
        }

        // got an interrupt.  process it

        svc.processIntrQMsg(*msg);


    }

    return NULL;

} // end intrTaskWorker


void * Service::intrTask(void * i_svc)
{
    // We need to create the actual thread that will do the work
    // and then monitor it for completion.
    tid_t  l_tid = task_create(&intrTaskWorker, i_svc);
    assert( l_tid > 0 );

    int    l_status = 0;
    void * l_Rc = NULL;

    tid_t  l_tidRc = task_wait_tid( l_tid, &l_status, &l_Rc);

    if (l_status == TASK_STATUS_CRASHED)
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        ATTN_INTR_TASK_MODULE
         * @reasoncode      ATTN_INTR_TASK_CRASHED
         * @userdata1       tidRc
         * @userdata2       Task Id that crashed
         *
         * @devdesc         PRD task crashed
         * @custdesc  Task analyzing HW errors has failed.
         */
        errlHndl_t l_err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,     // severity
             ATTN_INTR_TASK_MODULE,                    // moduleid
             ATTN_INTR_TASK_CRASHED,                   // reason Code
             (uint64_t)l_tidRc,                        // tid rc
             (uint64_t)l_tid                           // task that crashed
            );

        l_err->collectTrace("ATTN_FAST" , 512 );
        l_err->collectTrace("PRDF"      , 512 );
        l_err->collectTrace("MDIA_FAST" , 512 );

        // Ensure we are not on the interrupt service list.
        // or we'll get hung during TI waiting for this code
        // that crashed to shutdown.
        INTR::unRegisterMsgQ(INTR::LSI_LCL_FIR);

        // Save PLID for TI purposes
        uint32_t l_fatalEid = l_err->eid();

        // Commit the elog
        ATTN_ERR("Committing INTR task crash elog");
        errlCommit(l_err, ATTN_COMP_ID);
        // Crash now
        INITSERVICE::doShutdown(l_fatalEid, true);

    } // end if crashed


    // On Normal shutdown of thread, we will get here
    // and exit normally
    return NULL;

} // end intrTask


bool Service::intrTaskWait(msg_t * & o_msg)
{
    // wait for a shutdown message
    // or an interrupt
    bool shutdown = false;
    msg_q_t q = iv_intrTaskQ;

    o_msg = msg_wait(q);

    ATTN_FAST("...intr task woke up");

    shutdown = o_msg->type == SHUTDOWN;

    if(shutdown)
    {
        // this was a shutdown message.
        // ack the message and tell the
        // task loop to exit

        iv_intrTaskQ = 0;
        iv_shutdownPrdTask = true;

        msg_respond(q, o_msg);

        ATTN_FAST("interrupt task shutting down");
    }

    return shutdown;
}


void Service::processIntrQMsgPreAck(const msg_t & i_msg)
{
    // this function should do as little as possible
    // since the hw can't generate additional interrupts
    // until the msg is acknowledged

    TargetHandle_t proc = NULL;

    // ---------------------------
    // P10 uses the PIR structure
    // (but different format than P9)
    // ---------------------------
    // PIR structure is
    // 17 bits unused, 3 bits spareId, 4 bits topology, 1 unused,
    // 5/4 CoreID(norm/fused), 2/3 ThreadId(norm/fused)
    PIR_t  l_pir;
    l_pir.word = i_msg.data[1];


    TargetHandleList procs;
    getTargetService().getAllChips(procs, TYPE_PROC);

    TargetHandleList::iterator it = procs.begin();

    // resolve the PIR to a proc target
    while(it != procs.end())
    {
        uint64_t topologyId = 0;

        getTargetService().getAttribute(ATTR_PROC_FABRIC_TOPOLOGY_ID, *it, topologyId);
        // for debug, but you have to compile it in
        ATTN_TRACE("IntrQMsgPreAck: Topology:0x%X  PirT:0x%X PirW:0x%X",
                    topologyId, l_pir.topologyId, l_pir.word  );

        if (topologyId == l_pir.topologyId)
        {
            proc = *it;
            break;
        }

        ++it;
    }

    ServiceCommon::processAttnPreAck(proc);

}

void Service::processIntrQMsg(msg_t & i_msg)
{
    // processIntrQMsgPreAck function should do as little as possible
    // since the hw can't generate additional interrupts until the
    // msg is acknowledged

    processIntrQMsgPreAck(i_msg);

    // respond to the interrupt service so hw
    // can generate additional interrupts

    INTR::sendEOI(iv_intrTaskQ, &i_msg);

    // wake up the prd task

    mutex_lock(&iv_mutex);

    iv_interrupt = true;

    mutex_unlock(&iv_mutex);

    sync_cond_signal(&iv_cond);

}


void* Service::prdTaskWorker(void * i_svc)
{
    // prd task loop
    Service & svc = *static_cast<Service *>(i_svc);
    bool shutdown = false;

    TargetHandleList procs;
    getTargetService().getAllChips(procs, TYPE_PROC);

    // wait for a wakeup

    while(true)
    {
        shutdown = svc.prdTaskWait();

        if(shutdown)
        {
            // this was a shutdown wakeup.
            // tell the prd task loop to exit

            break;
        }

        // new attentions for prd to handle

        svc.processAttentions(procs);

    }

    return NULL;

} // end prdTaskWorker


void* Service::prdTask(void * i_svc)
{
    // We need to create the actual thread that will do the work
    // and then monitor it for completion.
    tid_t  l_tid = task_create(&prdTaskWorker, i_svc);
    assert( l_tid > 0 );

    int    l_status = 0;
    void * l_Rc = NULL;

    tid_t  l_tidRc = task_wait_tid( l_tid, &l_status, &l_Rc);

    if (l_status == TASK_STATUS_CRASHED)
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        ATTN_PRD_TASK_MODULE
         * @reasoncode      ATTN_PRD_TASK_CRASHED
         * @userdata1       tidRc
         * @userdata2       Task Id that crashed
         *
         * @devdesc         PRD task crashed
         * @custdesc  Task analyzing HW errors has failed.
         */
        errlHndl_t l_err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,     // severity
             ATTN_PRD_TASK_MODULE,                     // moduleid
             ATTN_PRD_TASK_CRASHED,                    // reason Code
             (uint64_t)l_tidRc,                        // tid rc
             (uint64_t)l_tid,                          // task that crashed
             ErrlEntry::ADD_SW_CALLOUT,
             ErrlEntry::FORCE_DUMP
            );

        l_err->collectTrace("PRDF"      , 512 );
        l_err->collectTrace("MDIA_FAST" , 512 );
        l_err->collectTrace("ATTN_FAST" , 512 );

        // Save PLID for TI purposes
        uint32_t l_fatalEid = l_err->eid();

        // Commit the elog
        ATTN_ERR("Committing PRD task crash elog");
        errlCommit(l_err, ATTN_COMP_ID);
        // Crash now
        INITSERVICE::doShutdown(l_fatalEid, true);

    } // end if crashed


    // On Normal shutdown of thread, we will get here
    // and exit normally
    return NULL;

} // end prdTask


bool Service::prdTaskWait()
{
    // wait for a wakeup
    bool shutdown = false;

    mutex_lock(&iv_mutex);

    while(!iv_interrupt && !iv_shutdownPrdTask)
    {
        sync_cond_wait(&iv_cond, &iv_mutex);
    }

    ATTN_FAST("...prd task woke up, shutdown: %d, pending: %d",
            iv_shutdownPrdTask,
            iv_interrupt);

    if(iv_shutdownPrdTask)
    {
        swap(shutdown, iv_shutdownPrdTask);
    }

    iv_interrupt = false;

    mutex_unlock(&iv_mutex);

    if(shutdown)
    {
        ATTN_FAST("prd task shutting down");
    }

    return shutdown;
}

errlHndl_t Service::stop()
{
    ATTN_SLOW("shutting down...");

    mutex_lock(&iv_mutex);

    tid_t intrTask = iv_intrTask;
    tid_t prdTask = iv_prdTask;

    msg_q_t q = iv_intrTaskQ;

    iv_intrTask = 0;
    iv_prdTask = 0;

    mutex_unlock(&iv_mutex);

    if(intrTask)
    {
        errlHndl_t err = configureInterrupts(q, DOWN);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }

        msg_t * shutdownMsg = msg_allocate();
        shutdownMsg->type = SHUTDOWN;

        msg_sendrecv(q, shutdownMsg);
        msg_free(shutdownMsg);

        task_wait_tid(intrTask, 0, 0);

        msg_q_destroy(q);
    }

    if(prdTask)
    {
        sync_cond_signal(&iv_cond);
        task_wait_tid(prdTask, 0, 0);
    }

    ATTN_SLOW("..shutdown complete");

    return 0;
}

bool Service::startIntrTask()
{
    if(!iv_intrTask)
    {
        iv_intrTask = task_create(&intrTask, this);
    }

    return iv_intrTask != 0;
}

bool Service::startPrdTask()
{
    if(!iv_prdTask)
    {
        iv_prdTask = task_create(&prdTask, this);
    }

    return iv_prdTask != 0;
}

errlHndl_t Service::start()
{
    errlHndl_t err = NULL;
    bool cleanStartup = false;

    ATTN_SLOW("starting...");

    mutex_lock(&iv_mutex);

    do {

        if(!iv_intrTaskQ) {

            // register msg q with interrupt
            // service for attention type interrupts

            msg_q_t q = msg_q_create();

            err = configureInterrupts(q, UP);

            if(err)
            {
                msg_q_destroy(q);
                break;
            }

            iv_intrTaskQ = q;
        }

        if(!startIntrTask())
        {
            break;
        }

        if(!startPrdTask())
        {
            break;
        }

        cleanStartup = true;

    } while(0);

    tid_t prd = iv_prdTask, intr = iv_intrTask;

    mutex_unlock(&iv_mutex);

    if(!cleanStartup)
    {
        errlHndl_t err2 = stop();

        if(err2)
        {
            errlCommit(err2, ATTN_COMP_ID);
        }
    }
    else
    {
        ATTN_SLOW("..startup complete, intr: %d, prd: %d", intr, prd);
    }

    return err;
}

Service::Service() :
    ServiceCommon(),
    iv_interrupt(false),
    iv_intrTaskQ(0),
    iv_shutdownPrdTask(false),
    iv_prdTask(0),
    iv_intrTask(0)
{
    sync_cond_init(&iv_cond);
}

Service::~Service()
{
    errlHndl_t err = stop();

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }

    sync_cond_destroy(&iv_cond);
}

bool Service::running()
{
    bool running;

    mutex_lock(&iv_mutex);

    running = 0 != iv_intrTaskQ;

    mutex_unlock(&iv_mutex);

    return running;
}

Service* Service::getGlobalInstance()
{
    return &(Singleton<Service>::instance());
}
}
