//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/msg.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
