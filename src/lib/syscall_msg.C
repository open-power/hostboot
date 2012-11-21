/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_msg.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2012              */
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
#include <sys/msg.h>
#include <sys/syscall.h>
#include <sys/vfs.h>
#include <errno.h>

#include <string.h>

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
    return (int64_t)_syscall2(MSG_SEND, q, msg);
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

