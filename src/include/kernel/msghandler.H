/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/msghandler.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/** @file msghandler.H
 *  @brief Interfaces for messaging from kernel-space to user-space.
 */
#ifndef __KERNEL_MSGHANDLER_H
#define __KERNEL_MSGHANDLER_H

#include <stdint.h>
#include <kernel/types.h>
#include <kernel/msg.H>
#include <kernel/spinlock.H>
#include <util/locked/list.H>

// Forward declaration.
namespace Systemcalls { void MsgRespond(task_t*); };

/** @brief Struct used for holding pending message information. */
struct MessageHandler_Pending
{
    typedef void* key_type;
        /** Key used for duplicative association. */
    key_type key;
        /** (optional) Task deferred by this message. */
    task_t* task;

        // Linked list pointers used by Util::Locked::List.
    MessageHandler_Pending* prev;
    MessageHandler_Pending* next;
};

/** @class MessageHandler
 *  @brief Class which facilitiates bridging messages between kernel-space and
 *         user space.
 *
 *  This class provides a 'send message' interface to kernel code to send a
 *  message into user-space.  The message is a <type, key, data> tuple sent
 *  to the message queue associated with this object.  The expected response
 *  from userspace is a <type, key, rc> tuple.
 *
 *  The typical use-case of these interfaces is to send a <va, page> pair to a
 *  user-space resource provider to request a page of memory be read or written.
 *  A parameter to the 'send message' interface is an optional task which is to
 *  be deferred until the response is fully processed.
 *
 *  The 'send message' interface will attempt to combine duplicate messages
 *  by associating message requests with the same key and only sending a
 *  single message to user-space for the key (while that key is outstanding).
 *  This behavior aids the typical use-case of these interfaces by combining
 *  multiple tasks page-faulting on a single page into a single request to the
 *  resource provider.
 *
 *  When a response is received, via the user-space msg_respond system call,
 *  the 'recv message' interface will be called to handle the response.  This
 *  interface will trigger an overrideable 'handle response' interface for
 *  each outstanding <key, task> pair.  The default behavior is to resume the
 *  task on successful responses and kill the task on error responses.  This
 *  behavior can be changed by overriding the 'handle response' interface.
 *
 *  SMP safety:
 *     The constructor of this class requests the spinlock for the kernel
 *     subsystem associated with this message handling instance.  Since the
 *     'recv message' interface is the entry point into this subsystem, the
 *     spinlock will be obtained prior to handling the message receipt.  When
 *     the 'send message' interface is called, the typical use-case is that
 *     the subsystem spinlock is already obtained (since the subsystem is
 *     requesting a message to be sent), so this object does not obtain the
 *     spinlock.  This spinlock must be obtained prior to calling 'send
 *     message' in order for the combining of duplicate messages to be
 *     SMP-safe.
 */
class MessageHandler
{
    public:
        /** @brief Results of the 'handle response' interface.
         *
         *  These are used to communicate back to the 'recv message' interface
         *  what to do with the deferred thread.
         *
         *  A result of UNHANDLED_RC will cause the default behavior of
         *  resuming the task on success and killing the task on error.
         */
        enum HandleResult
        {
                /** Response rc (if non-zero) has been successfully handled. */
            SUCCESS,
                /** Do not resume task yet, no matter the rc. */
            CONTINUE_DEFER,
                /** Nothing has been specifically handled for the rc. */
            UNHANDLED_RC,
        };

        /** @brief Constructor.
         *  @param[in] i_lock - Subsystem lock for this message handler, such
         *                      as VmmManager::lock.
         *  @param[in] i_msgq - Queue used to send messages into userspace.
         *
         *  @note The ownership of these parameter instances is maintained by
         *        the caller and not cleaned up by this object upon destruction.
         */
        MessageHandler(Spinlock* i_lock, MessageQueue* i_msgq)
            : iv_lock(i_lock), iv_msgq(i_msgq) {};

        /** @brief Destructor.
         *  No behavior required since ownership is maintained elsewhere.
         */
        virtual ~MessageHandler() {};

        /** @brief 'Send message' interface.
         *  Used to send a message into userspace.
         *
         *  @param[in] i_type - Message type (from sys/msg.h).
         *  @param[in] i_key - Key (msg->data[0]) for the message.
         *  @param[in] i_data - Data (msg->data[1]) for the message.
         *  @param[in] i_task - Optional task being deferred due to this
         *                      message.
         *
         *  The result of this message is that a message will be created and
         *  inserted onto a user-space message queue, awaking the waiter if
         *  blocked.  The task passed as a parameter, if not NULL, will be
         *  deferred.
         */
        void sendMessage(msg_sys_types_t i_type, void* i_key,
                         void* i_data, task_t* i_task);

        /** @brief 'Handle response' interface.
         *  Overrideable handling of the response to the 'send message'.
         *
         *  This is called once per previous 'send message' invocation for
         *  the same key even if duplicate keys were combined into a single
         *  user-space message.
         *
         *  This class, and specifically this method, should be inherited /
         *  overridden if advanced handling is required for the response
         *  above resuming the deferred task.
         *
         *  @param[in] i_type - The message type previously sent.
         *  @param[in] i_key - The key value for the received message.
         *  @param[in] i_task - The deferred task.
         *  @param[in] i_rc - The response rc from userspace.
         *
         *  @return HandleResult - The desired behavior on the 'recv message'
         *                         interface for this <key, task> pair.
         */
        virtual HandleResult handleResponse(msg_sys_types_t i_type, void* i_key,
                                            task_t* i_task, int i_rc);

    protected:
        /** @brief 'Recv message' interface.
         *  Called by the msg_respond sys-call handler to relay the response
         *  from userspace.
         *
         *  This interface will call handleResponse for each of the deferred
         *  <key, task> pairs and then, based on the return of handleResponse,
         *  resume or kill the deferred task.
         *
         *  @param[in] i_msg - The message responded from user-space.
         *
         *  @return Return code for msg_respond.
         */
        int recvMessage(msg_t* i_msg);

    private:
            /** Pointer to the subsystem lock. */
        Spinlock* const iv_lock;
            /** Message queue to relay messages to. */
        MessageQueue* const iv_msgq;
            /** Queue of pending user-space responses. */
        Util::Locked::List<MessageHandler_Pending,
                           MessageHandler_Pending::key_type> iv_pending;

            // Prevent copies.
        MessageHandler(const MessageHandler&);
        MessageHandler& operator=(const MessageHandler&);

    public:
            // Allow msg_respond handler to call recvMessage.
        friend void Systemcalls::MsgRespond(task_t* t);
};

#endif
