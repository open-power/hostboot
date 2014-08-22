/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/attnsvc.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#include "common/attnmem.H"
#include "common/attntarget.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

void getPbGp2Mask(uint64_t i_pos, void * i_data)
{
    uint64_t & mask = *static_cast<uint64_t *>(i_data);

    uint64_t tmp = 0;
    GP1::getCheckbits(i_pos, tmp);

    mask |= tmp;
}

/**
 * @brief calculated mask cache for ipoll
 */
class HostMask
{
    uint64_t iv_hostMask;
    uint64_t iv_nonHostMask;

    HostMask() : iv_hostMask(0), iv_nonHostMask(0)
    {
        IPOLL::getCheckbits(HOST, iv_hostMask);
        IPOLL::forEach(~0, &iv_nonHostMask, &getIpollMask);

        iv_nonHostMask = iv_nonHostMask & ~iv_hostMask;
    }

    static void getIpollMask(uint64_t i_type, void * i_data)
    {
        uint64_t & mask = *static_cast<uint64_t *>(i_data);

        uint64_t tmp = 0;
        IPOLL::getCheckbits(i_type, tmp);

        mask |= tmp;
    }

    static HostMask & get()
    {
        static HostMask hm;

        return hm;
    }

    public:

    static uint64_t host()
    {
        return get().iv_hostMask;
    }

    static uint64_t nonHost()
    {
        return get().iv_nonHostMask;
    }
};

errlHndl_t Service::configureInterrupts(
        msg_q_t i_q,
        ConfigureMode i_mode)
{
    errlHndl_t err = NULL;

    // First register for Q
    // This will set up the psi host bridge logic for
    // lcl_err interrupt on all chips

    if(i_mode == UP)
    {
        err = INTR::registerMsgQ(i_q,
                                 ATTENTION,
                                 INTR::ISN_LCL_ERR);
    }

    // setup the ITR macro for GPIO type host attentions,
    // on all procs

    if(!err)
    {
        TargetHandleList procs;
        getTargetService().getAllChips(procs, TYPE_PROC);
        TargetHandleList::iterator it = procs.begin();

        while(it != procs.end())
        {
            uint64_t mask = 0;

            // clear GPIO interrupt type status register

            if(i_mode == UP)
            {
                err = putScom(*it, INTR_TYPE_LCL_ERR_STATUS_AND_REG,
                              0);
            }

            if(err)
            {
                break;
            }

            // unmask GPIO interrupt type

            mask = 0x8000000000000000ull;

            err = putScom(
                    *it,
                    (i_mode == UP
                     ? INTR_TYPE_MASK_AND_REG
                     : INTR_TYPE_MASK_OR_REG),
                    i_mode == UP ? ~mask : mask);

            if(err)
            {
                break;
            }

            // set GPIO interrupt type mode - or

            if(i_mode == UP)
            {
                err = putScom(*it, INTR_TYPE_CONFIG_AND_REG,
                                 ~mask);
            }

            if(err)
            {
                break;
            }

            // enable/disable MCSes

            mask = 0;

            GP1::forEach(~0, &mask, &getPbGp2Mask);

            err = modifyScom(
                             *it,
                             GP2_REG,
                             i_mode == UP ? mask : ~mask,
                             i_mode == UP ? SCOM_OR : SCOM_AND);

            if(err)
            {
                break;
            }

            // enable attentions in ipoll mask

            mask = HostMask::nonHost();
            mask |= HostMask::host();

            // this doesn't have an and/or reg for some reason...

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


void Service::processIntrQMsgPreAck(const msg_t & i_msg)
{
    // this function should do as little as possible
    // since the hw can't generate additional interrupts
    // until the msg is acknowledged

    TargetHandle_t proc = NULL;

    INTR::XISR_t xisr;

    xisr.u32 = i_msg.data[0];

    TargetHandleList procs;
    getTargetService().getAllChips(procs, TYPE_PROC);

    TargetHandleList::iterator it = procs.begin();

    // resolve the xisr to a proc target

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

    uint64_t hostMask = HostMask::host();
    uint64_t nonHostMask = HostMask::nonHost();
    uint64_t data = 0;

    // do the minimum that is required
    // for sending EOI without getting
    // another interrupt.  for host attentions
    // this is clearing the gpio interrupt
    // type status register
    // and for xstp,rec,spcl this is
    // masking the appropriate bit in
    // ipoll mask

    // read the ipoll status register
    // to determine the interrupt was
    // caused by host attn or something
    // else (xstp,rec,spcl)

    errlHndl_t err = getScom(proc, IPOLL_STATUS_REG, data);

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);

        // assume everything is on

        data = hostMask | nonHostMask;
    }

    if(data & hostMask)
    {
        // if host attention, clear the ITR macro gpio interrupt
        // type status register.

        err = putScom(proc, INTR_TYPE_LCL_ERR_STATUS_AND_REG, 0);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }
    }

    if(data & nonHostMask)
    {
        // mask local proc xstp,rec and/or special attns if on.

        // the other thread might be trying to unmask
        // on the same target.  The mutex ensures
        // neither thread corrupts the register.

        mutex_lock(&iv_mutex);

        err = modifyScom(proc, IPOLL::address, data & nonHostMask, SCOM_OR);

        mutex_unlock(&iv_mutex);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }
    }
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

void* Service::prdTask(void * i_svc)
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
}

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

void Service::processAttentions(const TargetHandleList & i_procs)
{
    errlHndl_t err = NULL;
    AttentionList attentions;

    MemOps & memOps = getMemOps();
    ProcOps & procOps = getProcOps();

    do {

        attentions.clear();

        // enumerate the highest priority pending attention
        // on every chip and then give the entire set to PRD

        TargetHandleList::const_iterator pit = i_procs.end();

        while(pit-- != i_procs.begin())
        {
            // enumerate proc local attentions (xstp,spcl,rec).

            err = procOps.resolveIpoll(*pit, attentions);

            if(err)
            {
                errlCommit(err, ATTN_COMP_ID);
            }

            // enumerate host attentions and convert
            // to centaur targets

            err = memOps.resolve(*pit, attentions);

            if(err)
            {
                errlCommit(err, ATTN_COMP_ID);
            }
        }

        err = getPrdWrapper().callPrd(attentions);

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }

        // unmask proc local attentions
        // (xstp,rec,special) in ipoll mask

        // any pending attentions will be found
        // on the next pass

        pit = i_procs.end();

        while(pit-- != i_procs.begin())
        {
            mutex_lock(&iv_mutex);

            // the other thread might be trying to mask
            // on the same target.  The mutex ensures
            // neither thread corrupts the register.

            err = modifyScom(
                    *pit,
                    IPOLL::address,
                    ~HostMask::nonHost(),
                    SCOM_AND);

            mutex_unlock(&iv_mutex);

            if(err)
            {
                errlCommit(err, ATTN_COMP_ID);
            }
        }

        // if on a given Centaur with a pending attention
        // on an MBA, an attention comes on in the other MBA
        // we don't get an interrupt for that.  So make another
        // pass and check for that.

    } while(!attentions.empty());
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
    iv_interrupt(false),
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
