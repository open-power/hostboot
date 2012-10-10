/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/tracedaemon.H $                                 */
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
#include <targeting/common/target.H>

namespace TRACE
{
    /** @class TraceDaemon
     *  @brief Encapsulates the daemon functionality of trace.
     *
     *  The main-line trace paths can send messages to this code to request
     *  actions, such as buffer offload (by mailbox or signalling a scratch
     *  register), to be done or (TODO) the FSP can send messages to it.
     */
    class TraceDaemon
    {
        public:
            /** Default Constructor
             *
             *  Initializes class and starts daemon thread.
             */
            TraceDaemon();

            /** Default Destructor
             *
             *  Shuts down daemon thread and releases mailbox queue.
             */
            ~TraceDaemon();

            /** Message types supported by the trace daemon. */
            enum SUPPORTED_MSG_TYPES
            {
                UPDATE_SCRATCH_REG,     //< Update cont-trace scratch reg.
                SEND_TRACE_BUFFER,      //< Send buffer to FSP.

                DAEMON_SHUTDOWN,        //< Shutdown daemon thread.
            };

            // Make trace class a friend so it can get the message queue.
            friend class Trace;

        protected:
                /** Message Queue */
            msg_q_t iv_msgQ;

        private:
                /** Target for master processor */
            TARGETING::Target* iv_pMaster;

                /** SCOM address of scratch register. */
            static const uint32_t MB_SCRATCH_REGISTER_0 = 0x00050038;

            /** @brief Function to start daemon thread (using task_create).
             *  @param[in] Pointer to self.
             */
            static void* start(void*);

            /** @brief Main daemon loop. */
            void run();

            /** @brief Update a scratch register with the desired value.
             *  @param[in] i_value - Value to write to scratch register.
             */
            void updateScratchReg(uint64_t i_value);
    };
};

#endif
