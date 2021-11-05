/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_msg.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2022                        */
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
#include <sys/msg.h>
#include <sys/syscall.h>
#include <sys/vfs.h>
#include <sys/sync.h>
#include <sys/time.h>
#include <errno.h>

#include <string.h>
#include <memory>
#include <vector>
#include <time.h>

using namespace Systemcalls;

msg_q_t msg_q_create()
{
    return (msg_q_t) _syscall0(MSGQ_CREATE);
}

void msg_q_destroy(msg_q_t q)
{
    _syscall1(MSGQ_DESTROY, q);
}

int msg_q_register(msg_q_t q, const char* name)
{
    if (0 == strcmp(VFS_ROOT, name))
    {
        return (int64_t)_syscall2(MSGQ_REGISTER_ROOT,
                                  reinterpret_cast<void*>(MSGQ_ROOT_VFS),
                                  q);
    }
    else
    {
        msg_q_t vfsQ = (msg_q_t)_syscall1(MSGQ_RESOLVE_ROOT,
                                          reinterpret_cast<void*>(MSGQ_ROOT_VFS));
        msg_t* msg = msg_allocate();
        msg->type = VFS_MSG_REGISTER_MSGQ;
        msg->data[0] = (uint64_t) q;
        msg->extra_data = (void*) name;
        int rc = msg_sendrecv(vfsQ, msg);
        msg_free(msg);
        return rc;
    }
}

int msg_intr_q_register(msg_q_t q, uint64_t i_ipc_base_addr)
{
    int rc = (int64_t)_syscall3(MSGQ_REGISTER_ROOT,
                                reinterpret_cast<void*>(MSGQ_ROOT_INTR),
                                q,
                                reinterpret_cast<void*>(i_ipc_base_addr));

    return rc;
}

int msg_q_remove(const char * name)
{
    msg_q_t vfsQ = (msg_q_t)_syscall1(MSGQ_RESOLVE_ROOT,
                                      reinterpret_cast<void*>(MSGQ_ROOT_VFS));
    msg_t * msg = msg_allocate();
    msg->type = VFS_MSG_REMOVE_MSGQ;
    msg->extra_data = (void *)name;
    msg_sendrecv(vfsQ, msg);
    int rc = static_cast<int>(msg->data[0]);
    msg_free(msg);
    return rc;
}

msg_q_t msg_q_resolve(const char* name)
{
    if (0 == strcmp(VFS_ROOT, name))
    {
        return (msg_q_t)_syscall1(MSGQ_RESOLVE_ROOT,
                                  reinterpret_cast<void*>(MSGQ_ROOT_VFS));
    }
    else if (0 == strcmp(VFS_ROOT_MSG_INTR, name))
    {
        return (msg_q_t)_syscall1(MSGQ_RESOLVE_ROOT,
                                  reinterpret_cast<void*>(MSGQ_ROOT_INTR));
    }
    else
    {
        msg_q_t vfsQ = (msg_q_t)_syscall1(MSGQ_RESOLVE_ROOT,
                                          reinterpret_cast<void*>(MSGQ_ROOT_VFS));
        msg_t* msg = msg_allocate();
        msg->type = VFS_MSG_RESOLVE_MSGQ;
        msg->extra_data = (void*) name;
        msg_sendrecv(vfsQ, msg);
        msg_q_t rc = (msg_q_t) msg->data[0];
        msg_free(msg);
        return rc;
    }
}

msg_t* msg_allocate()
{
    msg_t* msg = reinterpret_cast<msg_t*>(malloc(sizeof(msg_t)));

    memset(msg, 0, sizeof(msg_t));

    return msg;
}

int msg_send(msg_q_t q, msg_t* msg)
{
    int64_t rc = 0;
    do
    {
        rc = (int64_t)_syscall2(MSG_SEND, q, msg);
    } while( rc == -EAGAIN );
    return rc;
}

int msg_sendrecv(msg_q_t q, msg_t* msg)
{
    return (int64_t)_syscall3(MSG_SENDRECV, q, msg, NULL);
}

int msg_sendrecv_noblk(msg_q_t q, msg_t* msg, msg_q_t q2)
{
    return (int64_t)_syscall3(MSG_SENDRECV, q, msg, q2);
}

int msg_respond(msg_q_t q, msg_t* msg)
{
    return (int64_t)_syscall2(MSG_RESPOND, q, msg);
}

msg_t* msg_wait(msg_q_t q)
{
    return (msg_t*)_syscall1(MSG_WAIT, q);
}

struct msg_wait_timeout_task_args
{
    uint64_t milliseconds_to_wait = 0;
    msg_q_t queue = { };
    std::unique_ptr<msg_t, decltype(&msg_free)> waiter_done_msg { nullptr, msg_free };
    volatile bool done = false;
};

static void* msg_wait_timeout_waiter_task(void* const vargs)
{
    task_detach(); // shut hostboot down if we crash

    auto args = static_cast<msg_wait_timeout_task_args*>(vargs);

    int64_t ms_to_wait = args->milliseconds_to_wait;
    const uint64_t MS_PER_POLL = 1;

    while (ms_to_wait > 0)
    {
        nanosleep(0, MS_PER_POLL * NS_PER_MSEC);
        ms_to_wait -= MS_PER_POLL;

        if (args->done)
        {
            break;
        }
    }

    msg_send(args->queue, args->waiter_done_msg.get());
    return nullptr;
}

std::vector<msg_t*> msg_wait_timeout(const msg_q_t q, uint64_t & io_milliseconds)
{
    /* This function waits for a message on a message queue with a timeout. It
     * does this by calling msg_wait on the queue, and if it receives no message
     * within a certain amount of time, a waiter task sends a "timeout" message
     * to the queue to cause the msg_send to return, and we indicate a timeout
     * to the caller.
     *
     * Any implementation of this functionality must satisfy these constraints:
     *
     * A. A "timeout" message has to appear somewhere in the implementation;
     *    there is no other way to cause msg_send to stop blocking a task, and
     *    there is no way to kill a task that is blocked. (We also must not
     *    "leak" tasks, i.e. create tasks that run forever and consume
     *    resources.)
     *
     * B. The timeout message must be sent on the same queue that the caller
     *    gives us. If this does not happen, then the task that calls msg_wait
     *    on the queue will will never be unblocked if a message never arrives
     *    on the queue. (Tasks cannot be killed, and even if they could be,
     *    doing so would introduce a race condition between the task kill and
     *    the msg_read.)
     *
     * C. There will always be a TOCTOU-style race condition between the time
     *    that the waiter task detects a timeout and the time that it actually
     *    places the timeout message on the queue. (If the waiter detects a
     *    timeout, gets descheduled, and then we receive a real message on the
     *    queue, the "timeout" message will appear on the queue after a real
     *    message.) The design of this function must accomodate this and render
     *    the race benign.
     *
     * D. We cannot allow the timeout message to remain on the queue in any
     *    circumstance. Callers cannot be expected to gracefully handle a
     *    message that they do not recognize.
     *
     * E. An unbounded number of messages may appear on the queue before our
     *    timeout message actually makes it on the queue. Given that we *must*
     *    remove the timeout message from the queue, and given that we cannot
     *    place "real" messages back on the queue after we have read them off,
     *    this function must therefore be able to return multiple messages.
     *
     * F. We must not "lose" real messages that were sent on the queue
     *    (i.e. by reading them and not returning them to the caller). Nor can
     *    we "lose" the timeout message, because we must deallocate it or else
     *    cause a memory leak.
     *
     * To satisfy these conditions, this function involves two concurrent tasks:
     *
     * 1. Task 1 will read all messages from the queue, until it receives the
     *    "timeout" message from task 2. Then it will return the list to the
     *    caller.
     *
     * 2. Task 2 will wait a given number of milliseconds, or until task 1 tells
     *    it to stop waiting, and then send the "timeout" message to task 1.
     *    Then it will exit.
     *
     * Since the timeout ("waiter done") message is always sent on the queue in
     * any case and Task 1 will always read it off of the queue, we satisfy
     * conditions (B), (D) and (F) above, and since we save and return ALL the
     * messages that we receive between the time we start listening and the time
     * we receive the "timeout" message, we satisfy conditions (C) and (E)
     * above. (Task 2 will always exit promptly, so condition (A) is also
     * fulfilled.)
     */

    msg_wait_timeout_task_args args { };

    timespec_t start, finish;

    args.milliseconds_to_wait = io_milliseconds;
    args.queue = q;

    // We will provide this message to the waiter task. When it sends this
    // message to us, we will know the waiter is done waiting (either by timeout
    // or by us telling it to stop polling).
    args.waiter_done_msg.reset(msg_allocate());

    clock_gettime(CLOCK_MONOTONIC, &start);
    task_create(msg_wait_timeout_waiter_task, &args);

    std::vector<msg_t*> results;

    while (true)
    {
        msg_t* const msg = msg_wait(q);

        if (msg == args.waiter_done_msg.get())
        {
            break;
        }

        // Accumulate the message, since it's not the "waiter done" message.
        results.push_back(msg);

        // Shut the timeout task down on its next polling loop. We will still
        // wait for it to send us the timeout message to avoid race conditions
        // should it time out between the time we receive a real message and the
        // time we tell it to stop. This way we always read the timeout message
        // from the queue, and the timeout message can't end up waiting on the
        // queue after we have quit polling.
        args.done = true;
    }

    clock_gettime(CLOCK_MONOTONIC, &finish);

    // calculate if any time is left after waiting
    uint64_t start_time_ns = (NS_PER_SEC * start.tv_sec) + start.tv_nsec;
    uint64_t finish_time_ns = (NS_PER_SEC * finish.tv_sec) + finish.tv_nsec;
    if (finish_time_ns > start_time_ns)
    {
        // return the milliseconds remaining of total wait time
        io_milliseconds -= ((finish_time_ns - start_time_ns) / NS_PER_MSEC);
    }
    else
    {
        io_milliseconds = 0;
    }

    return results;
}

int updateRemoteIpcAddr(uint64_t i_Node, uint64_t i_RemoteAddr)
{
    return (int64_t)_syscall2(UPDATE_REMOTE_IPC_ADDR,
                              (void *)i_Node,
                              (void *)i_RemoteAddr);
}

int qryLocalIpcInfo(uint64_t & o_Node, uint64_t & o_Addr)
{
    // need to allocate a buffer on the heap as Kernel cannot
    //  store back to user stack buffer
    uint64_t * l_pTmpBfr = new uint64_t[2];
    l_pTmpBfr[0] = o_Node;    // seed tmp bfr with contents of out bfr
    l_pTmpBfr[1] = o_Addr;    //  to hide the existence of the
                              //  intermediate tmp bfr
    void * l_pNode = reinterpret_cast<void *>(&l_pTmpBfr[0]);
    void * l_pAddr = reinterpret_cast<void *>(&l_pTmpBfr[1]);

    void * l_retVal = _syscall2( QRY_LOCAL_IPC_INFO,
                                 l_pNode,
                                 l_pAddr );

    o_Node = l_pTmpBfr[0];
    o_Addr = l_pTmpBfr[1];
    delete [] l_pTmpBfr;

    return( reinterpret_cast<int64_t>(l_retVal) );
}
