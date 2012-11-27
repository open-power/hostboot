/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakepresenter.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file attnfakepresenter.C
 *
 * @brief HBATTN fake interrupt presenter class method definitions.
 */

#include "attnfakepresenter.H"
#include "../attntrace.H"
#include "../attntarget.H"

using namespace TARGETING;
using namespace PRDF;

namespace ATTN
{

struct InterruptProperties
{
    TargetHandle_t source;
    MessageType type;
    void * data;
    void (*callback)(TargetHandle_t, MessageType, void *);
    uint64_t xisr;
};

struct PresenterProperties
{
    FakePresenter * presenter;
    msg_q_t msgQ;
};

bool FakePresenter::start(msg_q_t i_q)
{
    // start threads, create message q...

    bool success = false;
    PresenterProperties * properties = NULL;

    mutex_lock(&iv_mutex);

    do {

        if(!iv_recvQ)
        {
            iv_recvQ = msg_q_create();
        }

        if(!iv_recvQ)
        {
            break;
        }

        if(!iv_tid)
        {
            properties = new PresenterProperties;

            properties->presenter = this;
            properties->msgQ = i_q;

            iv_tid = task_create(&main, properties);
        }

        if(!iv_tid)
        {
            msg_q_destroy(iv_recvQ);
            delete properties;

            break;
        }

    } while(0);

    success = ((iv_tid != 0) && (iv_recvQ != 0));

    mutex_unlock(&iv_mutex);

    return success;
}

void FakePresenter::stop()
{
    mutex_lock(&iv_mutex);

    tid_t t = iv_tid;
    iv_tid = 0;

    mutex_unlock(&iv_mutex);

    if(t)
    {
        msg_t * m = msg_allocate();
        m->type = SHUTDOWN;
        msg_send(iv_recvQ, m);

        task_wait_tid(t, 0, 0);
    }
}

void FakePresenter::interrupt(
        TargetHandle_t i_source,
        MessageType i_type,
        void * i_data,
        void (*i_callback)(TargetHandle_t, MessageType, void *))
{
    mutex_lock(&iv_mutex);

    if(iv_tid)
    {
        INTR::XISR_t xisr;

        uint64_t node = 0, chip = 0;

        getTargetService().getAttribute(ATTR_FABRIC_NODE_ID, i_source, node);
        getTargetService().getAttribute(ATTR_FABRIC_CHIP_ID, i_source, chip);

        xisr.node = node;
        xisr.chip = chip;

        InterruptProperties * p = new InterruptProperties;

        p->source = i_source;
        p->type = i_type;
        p->data = i_data;
        p->callback = i_callback;
        p->xisr = xisr.u32;

        msg_t * m = msg_allocate();

        m->type = i_type;
        m->data[0] = reinterpret_cast<uint64_t>(p);

        ATTN_DBG("FakePresenter: interrupt request: src: %p, type: %d",
                p->source, p->type);

        msg_send(iv_recvQ, m);
    }

    mutex_unlock(&iv_mutex);
}

bool FakePresenter::wait(msg_q_t i_q)
{
    bool shutdown = false;

    msg_t * recvMsg = msg_wait(iv_recvQ);

    shutdown = recvMsg->type == SHUTDOWN;

    if(shutdown)
    {
        msg_q_destroy(iv_recvQ);
        iv_recvQ = 0;
    }

    else
    {
        msg_t * sendMsg = msg_allocate();

        InterruptProperties * p = reinterpret_cast<InterruptProperties *>(
                recvMsg->data[0]);

        sendMsg->type = p->type;
        sendMsg->data[0] = p->xisr;

        ATTN_DBG("FakePresenter: raising interrupt: src: %p, type: %d, xisr: 0x%07x",
                p->source, p->type, p->xisr);

        msg_sendrecv(i_q, sendMsg);

        msg_free(sendMsg);

        (*p->callback)(p->source, p->type, p->data);
        delete p;
    }

    msg_free(recvMsg);

    return shutdown;
}

void* FakePresenter::main(void * i_properties)
{
    PresenterProperties * properties
        = static_cast<PresenterProperties *>(i_properties);

    while(true)
    {
        bool shutdown = properties->presenter->wait(properties->msgQ);

        if(shutdown)
        {
            break;
        }
    }

    delete properties;
    return NULL;
}

FakePresenter::FakePresenter()
    : iv_tid(0),
    iv_recvQ(0)
{
    mutex_init(&iv_mutex);
}

FakePresenter::~FakePresenter()
{
    stop();

    if(iv_recvQ)
    {
        msg_q_destroy(iv_recvQ);
    }

    mutex_destroy(&iv_mutex);
}
}
