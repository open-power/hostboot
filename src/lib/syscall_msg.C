#include <sys/msg.h>
#include <sys/syscall.h>
#include <sys/vfs.h>

#include <string.h>

using namespace Systemcalls;

msg_q_t msg_q_create()
{
    return (msg_q_t) _syscall0(MSGQ_CREATE);
}

int msg_q_destroy(msg_q_t q)
{
    return (int64_t)_syscall1(MSGQ_DESTROY, q);
}

int msg_q_register(msg_q_t q, const char* name)
{
    if (0 == strcmp(VFS_ROOT, name))
    {
	return (int64_t)_syscall1(MSGQ_REGISTER_ROOT, q);
    }
    else
    {
	msg_q_t vfsQ = (msg_q_t)_syscall0(MSGQ_RESOLVE_ROOT);
	msg_t* msg = msg_allocate();
	msg->type = VFS_MSG_REGISTER_MSGQ;
	msg->data[0] = (uint64_t) q;
	msg->extra_data = (void*) name;
	int rc = msg_sendrecv(vfsQ, msg);
	msg_free(msg);
	return rc;
    }
}

msg_q_t msg_q_resolve(const char* name)
{
    if (0 == strcmp(VFS_ROOT, name))
    {
	return (msg_q_t)_syscall0(MSGQ_RESOLVE_ROOT);
    }
    else
    {
	msg_q_t vfsQ = (msg_q_t)_syscall0(MSGQ_RESOLVE_ROOT);
	msg_t* msg = msg_allocate();
	msg->type = VFS_MSG_RESOLVE_MSGQ;
	msg->extra_data = (void*) name;
	msg_sendrecv(vfsQ, msg);
	msg_q_t rc = (msg_q_t) msg->data[0];
	msg_free(msg);
	return rc;
    }
}

int msg_send(msg_q_t q, msg_t* msg)
{
    return (int64_t)_syscall2(MSG_SEND, q, msg);
}

int msg_sendrecv(msg_q_t q, msg_t* msg)
{
    return (int64_t)_syscall2(MSG_SENDRECV, q, msg);
}

int msg_respond(msg_q_t q, msg_t* msg)
{
    return (int64_t)_syscall2(MSG_RESPOND, q, msg);
}

msg_t* msg_wait(msg_q_t q)
{
    return (msg_t*)_syscall1(MSG_WAIT, q);
}

