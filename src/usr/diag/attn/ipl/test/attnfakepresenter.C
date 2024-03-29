/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/test/attnfakepresenter.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
 * @file attnfakepresenter.C
 *
 * @brief HBATTN fake interrupt presenter class method definitions.
 */

#include "attnfakepresenter.H"
#include "../../common/attntrace.H"
#include "../../common/attntarget.H"
#include "arch/pirformat.H"

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
    uint64_t  pir;
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
        PIR_t    l_pir;
        uint64_t topologyId = 0;

        getTargetService().getAttribute(ATTR_PROC_FABRIC_TOPOLOGY_ID, i_source, topologyId);

        l_pir.topologyId = topologyId;

        InterruptProperties * p = new InterruptProperties;

        p->source = i_source;
        p->type = i_type;
        p->data = i_data;
        p->callback = i_callback;
        p->pir = l_pir.word;

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
        sendMsg->data[0] = p->pir;

        ATTN_DBG("FakePresenter: raising interrupt: src: %p, type: %d, pir: 0x%08x",
                p->source, p->type, p->pir);

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
