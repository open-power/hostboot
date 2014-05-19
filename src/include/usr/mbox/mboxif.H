/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/mboxif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __MBOX_MBOXIF_H
#define __MBOX_MBOXIF_H

#include <sys/msg.h>
#include <errl/errlentry.H>
#include <mbox/mbox_queues.H>

#define MBOX_TRACE_NAME MBOX_COMP_NAME
#define MBOXMSG_TRACE_NAME "MBOXMSG"

namespace MBOX
{
    enum
    {
        MBOX_NODE_FSP = -1,
    };

    /**
     * Register a message queue to receive mailbox messages
     * @param[in] i_queueu_id, The queue identifier
     * @param[in] i_msgQ, The message queue created with msg_q_create()
     *                    @see sys/msg.h
     * @return errlHndl_t on error
     */
    errlHndl_t msgq_register(queue_id_t i_queue_id, msg_q_t i_msgQ);

    /**
     * Un register a message queue from the mailbox service
     * @param[in] i_queue_id, The queue identifier
     * @return The message queue | NULL if i_queue_id not registered.
     */
    msg_q_t msgq_unregister(queue_id_t i_queue_id);

    /**
     * Send message asynchronously
     * @param[in] i_q_id id, of the FSP message queue to send the msg to.
     * @param[in] i_msg. The message to send.
     * @param[in] i_node The destination node [0-7] for IPC messages, 
     *                   otherwise the default is FSP
     *
     * @return errlHndl_t on error.
     *
     * @note extra_data payload is not supported for interprocessor
     *       communication(IPC) messages therefore the i_msg->extra_data field
     *       may be used as another user data field
     *
     * @pre For FSP mbox messages, i_msg->extra_data must be NULL If there is
     *      no payload associated with the message.
     *
     * @pre For FSP mbox messages, 
     *      i_msg->extra_data = malloc(size); i_msg->data[1] = size; 
     *      Any extra data associated with i_msg was obtained from the heap
     *      using malloc and i_msg->data[1] contains the length of that data.
     *
     * @post free(i_msg->extra_dat)  was done (if no error)
     * @post msg_free(i_msg) was done (if no error)
     */
    errlHndl_t send(queue_id_t i_q_id,
                    msg_t * i_msg,
                    int i_node = MBOX_NODE_FSP);

    /**
     * Send message synchronously
     * @param[in] i_q_id id, of the FSP message queue to send the msg to.
     * @param[in/out] io_msg. The message sent and returned.
     *
     * @return errlHndl_t on error
     *
     * @pre io_msg->extra_data ==  NULL If there is no extra data is associated
     *      with the message.
     *
     * @pre io_msg->extra_data = malloc(size); io_msg->data[1] = size; 
     *      Any extra data associated with io_msg was obtained from the heap
     *      using malloc and io_msg->data[1] contains the length of that data.
     *
     * @post free(i_msg->extra_data)  was done (if no error)
     *
     * @note: On return, if io_msg->extra_data != NULL, the caller must
     * call free(io_msg->extra_data);
     */
    errlHndl_t sendrecv(queue_id_t i_q_id, msg_t * io_msg);

    /**
     * Determine if the mailbox is enabled
     *
     * @return bool
     *             true    -> mailbox is enabled
     *             flalse  -> mailbox is disabled (spless system)
     */
    bool mailbox_enabled();

    /**
     * Suspend the mailbox. 
     *
     * @return error handle on error
     *
     * @note:
     *     Any message sent to the FSP will be queued and send after the mailbox
     *     is resumed. Interrupts from the FSP MBox will be masked.
     */
    errlHndl_t suspend();

    /**
     * Resume the mailbox
     *
     * @return error handle on error
     *
     * @note  FSP Mbox re-enabled, queued messages sent.
     */
    errlHndl_t resume();

}; // end namespace MBOX

#endif
