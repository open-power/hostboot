/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/daemonif.C $                                    */
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
