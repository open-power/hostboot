/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnsvc.C $                                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 * @file attnsvc.C
 *
 * @brief HBATTN background service class function definitions.
 */

#include <sys/msg.h>
#include <errl/errlmanager.H>
#include "attnsvc.H"
#include "attntrace.H"
#include "attnlistutil.H"
#include "attnprd.H"
#include "attnproc.H"
#include "attnmem.H"
#include "attntarget.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

void getMask(uint64_t i_type, void * i_data)
{
    uint64_t & mask = *static_cast<uint64_t *>(i_data);
    uint64_t tmp = 0;

    IPOLL::getCheckbits(i_type, tmp);

    mask |= tmp;
}

errlHndl_t Service::configureInterrupts(
        msg_q_t i_q,
        ConfigureMode i_mode)
{
    errlHndl_t err = NULL;

    // First register for Q
    // This will set up the lcl_err interrupt on all chips
    if(i_mode == UP)
    {
        err = INTR::registerMsgQ(i_q,
                                 ATTENTION,
                                 INTR::ISN_LCL_ERR);
    }

    //Issue scoms to allow attentions to flow via INTR
    if(!err)
    {
        TargetHandleList procs;
        getTargetService().getAllChips(procs, TYPE_PROC);
        TargetHandleList::iterator it = procs.begin();

        while(it != procs.end())
        {
            uint64_t mask = 0;

            // clear status

            if(i_mode == UP)
            {
                err = putScom(*it, INTR_TYPE_LCL_ERR_STATUS_REG,
                              0);
            }

            if(err)
            {
                break;
            }

            // unmask lcl err intr

            mask = 0x8000000000000000ull;

            err = modifyScom(
                             *it,
                             INTR_TYPE_MASK_REG,
                             i_mode == UP ? ~mask : mask,
                             i_mode == UP ? SCOM_AND : SCOM_OR);

            if(err)
            {
                break;
            }

            // set lcl err intr conf - or

            if(i_mode == UP)
            {
                err = modifyScom(*it, INTR_TYPE_CONFIG_REG,
                                 ~mask, SCOM_AND);
            }

            if(err)
            {
                break;
            }

            // enable powerbus gpin

            mask = 0x0018000000000000ull;

            err = modifyScom(
                             *it,
                             GP2_REG,
                             i_mode == UP ? mask : ~mask,
                             i_mode == UP ? SCOM_OR : SCOM_AND);

            if(err)
            {
                break;
            }

            // enable interrupts in ipoll mask

            mask = 0;

            IPOLL::forEach(~0, &mask, &getMask);

            err = modifyScom(
                    *it,
                    IPOLL::address,
                    i_mode == UP ? ~mask : mask,
                    i_mode == UP ? SCOM_AND : SCOM_OR);

            if(err)
            {
                break;
            }

            ++it;
        }

        if(!err && i_mode == DOWN)
        {
            if(NULL == INTR::unRegisterMsgQ(INTR::ISN_LCL_ERR))
            {
                ATTN_ERR("INTR did not find isn: 0x%07x",
                        INTR::ISN_LCL_ERR);
            }
        }
    }
    return err;
}

void * Service::intrTask(void * i_svc)
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
}

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

errlHndl_t Service::processIntrQMsgPreAck(const msg_t & i_msg,
        AttentionList & o_attentions)
{
    // this function should do as little as possible
    // since the hw can't generate additional interrupts
    // until the msg is acknowledged

    errlHndl_t err = NULL;

    TargetHandle_t proc = NULL;

    INTR::XISR_t xisr;

    xisr.u32 = i_msg.data[0];

    TargetHandleList procs;
    getTargetService().getAllChips(procs, TYPE_PROC);

    TargetHandleList::iterator it = procs.begin();

    while(it != procs.end())
    {
        uint64_t node = 0, chip = 0;

        getTargetService().getAttribute(ATTR_FABRIC_NODE_ID, *it, node);
        getTargetService().getAttribute(ATTR_FABRIC_CHIP_ID, *it, chip);

        if(node == xisr.node
                && chip == xisr.chip)
        {
            proc = *it;
            break;
        }

        ++it;
    }

    ATTN_DBG("preack: xisr: 0x%07x, tgt: %p", xisr.u32, proc);

    do {

        // determine what has an attention
        // determine what attentions are unmasked
        // in the ipoll mask register and query the proc & mem
        // resolvers for active attentions

        ProcOps & procOps = getProcOps();
        MemOps & memOps = getMemOps();

        uint64_t ipollMaskScomData = 0;

        // get ipoll mask register content and decode
        // unmasked attention types

        err = getScom(proc, IPOLL::address, ipollMaskScomData);

        if(err)
        {
            break;
        }

        ATTN_DBG("resolving 0x%016x...", ipollMaskScomData);

        // query the proc resolver for active attentions

        err = procOps.resolve(proc, ipollMaskScomData, o_attentions);

        if(err)
        {
            break;
        }

        // query the mem resolver for active attentions

        err = memOps.resolve(proc, ipollMaskScomData, o_attentions);

        if(err)
        {
            break;
        }

        // mask them

        err = o_attentions.forEach(MaskFunct()).err;

        if(err)
        {
            break;
        }

        // clear anything in the status register

        err = putScom(proc, INTR_TYPE_LCL_ERR_STATUS_REG, 0);

        if(err)
        {
            break;
        }

        ATTN_DBG("...resolved %d", o_attentions.size());

    } while(0);

    return err;
}

void Service::processIntrQMsg(msg_t & i_msg)
{
    errlHndl_t err = NULL;

    AttentionList newAttentions;

    // processIntrQMsgPreAck function should do as little as possible
    // since the hw can't generate additional interrupts until the
    // msg is acknowledged

    err = processIntrQMsgPreAck(i_msg, newAttentions);

    // respond to the interrupt service so hw
    // can generate additional interrupts

    msg_respond(iv_intrTaskQ, &i_msg);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }
    else if(!newAttentions.empty())
    {
        // put the new attentions in the list

        mutex_lock(&iv_mutex);

        iv_attentions.merge(newAttentions);

        mutex_unlock(&iv_mutex);

        // wake up the prd task

        sync_cond_signal(&iv_cond);
    }
}

void* Service::prdTask(void * i_svc)
{
    // prd task loop

    Service & svc = *static_cast<Service *>(i_svc);
    bool shutdown = false;
    AttentionList attentions;

    // wait for a wakeup

    while(true)
    {
        shutdown = svc.prdTaskWait(attentions);

        if(shutdown)
        {
            // this was a shutdown wakeup.
            // tell the prd task loop to exit

            break;
        }

        // new attentions for prd to handle

        svc.processAttentions(attentions);
    }
    return NULL;
}

bool Service::prdTaskWait(AttentionList & o_attentions)
{
    // wait for a wakeup

    bool shutdown = false;

    mutex_lock(&iv_mutex);

    while(iv_attentions.empty() && !iv_shutdownPrdTask)
    {
        sync_cond_wait(&iv_cond, &iv_mutex);

        ATTN_FAST("...prd task woke up");
    }

    o_attentions = iv_attentions;
    iv_attentions.clear();

    if(o_attentions.empty() && iv_shutdownPrdTask)
    {
        swap(shutdown, iv_shutdownPrdTask);
    }

    mutex_unlock(&iv_mutex);

    if(shutdown)
    {
        ATTN_FAST("prd task shutting down");
    }

    return shutdown;
}

void Service::processAttentions(const AttentionList & i_attentions)
{
    errlHndl_t err = NULL;

    err = getPrdWrapper().callPrd(i_attentions);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }

    do {

        // figure out which attentions PRD did not clear.

        AttentionList cleared, uncleared;

        err = i_attentions.split(cleared, uncleared, ClearedPredicate()).err;

        if(err)
        {
            break;
        }

        mutex_lock(&iv_mutex);

        // reinsert attentions PRD did not clear.

        iv_attentions.merge(uncleared);

        mutex_unlock(&iv_mutex);

        // unmask cleared attentions

        err = cleared.forEach(UnmaskFunct()).err;

        if(err)
        {
            break;
        }

    } while(0);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }
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
    iv_intrTaskQ(0),
    iv_shutdownPrdTask(false),
    iv_prdTask(0),
    iv_intrTask(0)
{
    mutex_init(&iv_mutex);
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
    mutex_destroy(&iv_mutex);
}

bool Service::running()
{
    bool running;

    mutex_lock(&iv_mutex);

    running = 0 != iv_intrTaskQ;

    mutex_unlock(&iv_mutex);

    return running;
}
}
