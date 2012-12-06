/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/daemonif.H $                                    */
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
#ifndef __TRACE_DAEMON_H
#define __TRACE_DAEMON_H

#include <sys/msg.h>
#include <mbox/mbox_queues.H>

    // Forward declaration of Daemon class.
namespace TRACEDAEMON { class Daemon; }

namespace TRACE
{
    /** @class DaemonIf
     *
     *  Defines the interface between the client (front-end) interfaces and
     *  the daemon.
     *
     *  Since the daemon is in a separate extended module the client won't
     *  know when the daemon process is actually available.  This small
     *  interface class is used to provide an abstraction in the base module
     *  for clients.
     *
     */
    class DaemonIf
    {
        public:
            /** Default constructor.
             *
             *  Initializes class and sets daemon as not-running.
             */
            DaemonIf();
            /** Default destructor.
             *
             *  Ensures the daemon is shutdown if running.
             */
            ~DaemonIf();

            /** Allows the client to signal the daemon that work is ready.
             *
             *  @param[in] i_blocking - Indicates if this function should
             *                          block until the daemon satisfies the
             *                          request.
             */
            void signal(bool i_blocking = false);

            friend class BufferTest;
            friend class TRACEDAEMON::Daemon;

        private:
                /** Queue to send messages to daemon on. */
            msg_q_t iv_queue;
                /** Indication if the daemon has already been signalled. */
            uint16_t iv_signalled;
                /** State of daemon process. */
            bool iv_running;

            enum MSG_TYPES
            {
                    /** Client work is ready to be performed; flush buffers. */
                TRACE_DAEMON_SIGNAL = MBOX::FIRST_UNSECURE_MSG | 0,
                    /** Flush continuous trace buffers. */
                TRACE_CONT_TRACE_FLUSH = TRACE_DAEMON_SIGNAL,
                    /** Daemon should shutdown. */
                TRACE_DAEMON_SHUTDOWN = MBOX::FIRST_SECURE_MSG | 1,
                    /** Modify continuous trace state. */
                TRACE_CONT_TRACE_STATE = MBOX::FIRST_UNSECURE_MSG | 2,
                    /** Reset trace buffers. */
                TRACE_RESET_BUFFERS = MBOX::FIRST_UNSECURE_MSG | 3,
                    /** Enable Debug state (TRACS mode). */
                TRACE_ENABLE_DEBUG = MBOX::FIRST_UNSECURE_MSG | 4,
                    /** Disable Debug state (TRACS mode). */
                TRACE_DISABLE_DEBUG = MBOX::FIRST_UNSECURE_MSG | 5,
                    /** Extract all buffers. */
                TRACE_EXTRACT_BUFFERS = MBOX::FIRST_UNSECURE_MSG | 6,
            };

            enum FSP_MSG_TYPES
            {
                TRACE_CONT_TRACE_BUFFER = 0,
                TRACE_BUFFER = 1,
            };

            // Since the below functions are only used by the daemon, they
            // are only implemented in the daemon module.

            /** Mark the daemon as 'running'. */
            void start();
            /** Block the daemon until a message is available. */
            msg_t* wait() { return msg_wait(iv_queue); }
            /** Clear the client signal. */
            void clearSignal();

    };
}

#endif
