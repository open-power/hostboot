#include <sys/msg.h>
#include <sys/syscall.h>

#include <string.h>

using namespace Systemcalls;

const char* VFS_ROOT = "/"; // TODO.

msg_q_t msg_q_create()
{
    return (msg_q_t) _syscall0(MSGQ_CREATE);
}

int msg_q_destroy(msg_q_t q)
{
    return (int64_t)_syscall1(MSGQ_DESTROY, q);
}

int msg_q_register(msg_q_t q, char* name)
{
    if (0 == strcmp(VFS_ROOT, name))
    {
	return (int64_t)_syscall1(MSGQ_REGISTER_ROOT, q);
    }
    else
    {
	// TODO.
	return -1;
    }
}

msg_q_t msg_q_resolve(char* name)
{
    if (0 == strcmp(VFS_ROOT, name))
    {
	return (msg_q_t)_syscall0(MSGQ_RESOLVE_ROOT);
    }
    else
    {
	// TODO.
	return NULL;
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

