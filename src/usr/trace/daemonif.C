/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/daemonif.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#include "daemonif.H"

namespace TRACE
{

    DaemonIf::DaemonIf() :
        iv_queue(msg_q_create()), iv_signalled(0), iv_running(false)
    {
    }

    DaemonIf::~DaemonIf()
    {
        if (iv_running)
        {
            msg_t* msg = msg_allocate();
            msg->type = TRACE_DAEMON_SHUTDOWN;
            msg_sendrecv(iv_queue, msg);
            msg_free(msg);
        }

        msg_q_destroy(iv_queue);
    }

    void DaemonIf::signal(bool i_blocking)
    {
        // Atomically increment the signal count.
        uint16_t count = __sync_fetch_and_add(&iv_signalled, 1);

        // Send a message if this is the first, or requested to be blocking.
        if ((count == 0) || (i_blocking))
        {
            msg_t* msg = msg_allocate();
            msg->type = TRACE_DAEMON_SIGNAL;
            if (i_blocking)
            {
                msg_sendrecv(iv_queue, msg); // sync message due to 'blocking'.
            }
            else
            {
                msg_send(iv_queue, msg); // async message request.
            }
        }
    }

}
