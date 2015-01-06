/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/daemon/daemon.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __TRACE_DAEMON_DAEMON_H
#define __TRACE_DAEMON_DAEMON_H

/** @file daemon.H
 *  Declarations for the daemon class.
 */

#include <stdint.h>
#include "../service.H"

    // Forward declarations.
namespace TRACE
{
    class BufferPage;
    class Entry;
}

namespace TRACEDAEMON
{
    /** @class Daemon
     *
     *  @brief Class to handle trace background ops and mailbox messages.
     */
    class Daemon
    {
        public:
            /** Default constructor.
             *
             *  Initializes class.
             *
             */
            Daemon();
            /** Destructor.
             *
             *  Not currently supported, asserts.
             */
            ~Daemon();

            /** @fn start
             *
             *  Thread entry-point for daemon.  Calls 'execute'.
             */
            static void* start(void*);

        private:

            /** @fn execute
             *
             *  Performs daemon work.
             */
            void execute();

            /** Gather trace pages from client-side buffers. */
            void collectTracePages();
            /** Send continuous trace buffer to SP.
             *
             *  Ownership of i_buffer is transferred to mailbox.
             */
            void sendContBuffer(void* i_buffer, size_t i_size);
            /** Send extract trace buffer to SP.
             *
             *  Ownership of i_buffer is transferred to mailbox.
             */
            void sendExtractBuffer(void* i_buffer, size_t i_size);
            /** Reduce component trace buffers if exceeded max size. */
            void pruneTraceEntries(bool i_all = false);
            /** Combine trace buffer pages to remove pruned entries. */
            void coalescePages();
            /** Extract all trace buffers down to the SP. */
            void extractTraceBuffer();

            /** Locklessly move a trace entry from one location to another. */
            void replaceEntry(TRACE::Entry* from, TRACE::Entry* to);

            /** Write mailbox scratch register to a value. */
            void writeScratchReg(uint64_t i_value);
            /** Read mailbox scratch register. */
            uint64_t readScratchReg();

                /** Client-service object. */
            TRACE::Service* iv_service;

                /** First (oldest) combined-buffer page. */
            TRACE::BufferPage* iv_first;
                /** Last (newested) combined-buffer page. */
            TRACE::BufferPage* iv_last;

            // These are kept as class variables rather than function variables
            // so that they can be extraced by the debug tools, since we might
            // be in the middle of the 'collectTracePages' function when the
            // debug tools try to extract the trace.
                /** Intermediate pages
                 *      After collection from client-side, before combining. */
            TRACE::BufferPage* iv_curPages[TRACE::BUFFER_COUNT];
                /** Current offset into intermediate page. */
            size_t iv_curOffset[TRACE::BUFFER_COUNT];

                /** Current size of trace entries pruned. */
            size_t iv_totalPruned;

                /** Address of scratch register. */
            static const uint32_t MB_SCRATCH_REGISTER_1 = 0x00050038;

    };


}

#endif
