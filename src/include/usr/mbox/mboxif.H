//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/mbox/mboxif.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __MBOX_MBOXIF_H
#define __MBOX_MBOXIF_H

#include <sys/msg.h>
#include <errl/errlentry.H>
#include <mbox/mbox_queues.H>

namespace MBOX
{
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
     *
     * @return errlHndl_t on error.
     *
     * @pre i_msg->extra_data ==  NULL If there is no extra data is associated
     *      with the message.
     *
     * @pre i_msg->extra_data = malloc(size); i_msg->data[1] = size; 
     *      Any extra data associated with i_msg was obtained from the heap
     *      using malloc and i_msg->data[1] contains the length of that data.
     *
     * @post free(i_msg->extra_dat)  was done (if no error)
     * @post msg_free(i_msg) was done (if no error)
     */
    errlHndl_t send(queue_id_t i_q_id, msg_t * i_msg);

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

}; // end namespace MBOX

#endif
