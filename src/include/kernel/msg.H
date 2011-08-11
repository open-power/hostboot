#ifndef __KERNEL_MSG_H
#define __KERNEL_MSG_H

#include <kernel/types.h>
#include <sys/msg.h>
#include <kernel/spinlock.H>
#include <util/locked/list.H>
#include <util/locked/queue.H>

struct MessagePending
{
    typedef msg_t* key_type;
    key_type key;
    task_t* task;

    MessagePending* prev;
    MessagePending* next;
};

class MessageQueue
{
    public:
	Spinlock lock;
	Util::Locked::List<MessagePending, MessagePending::key_type> messages;
	Util::Locked::List<MessagePending, MessagePending::key_type> responses;
	Util::Locked::Queue<task_t> waiting;
};

#endif
