/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/buffer.H $                                      */
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
#ifndef __TRACE_BUFFER_H
#define __TRACE_BUFFER_H

/** @file buffer.H
 *  Declarations for the buffer class.
 */

#include <trace/interface.H>
#include <sys/sync.h>

namespace TRACEDAEMON { class Daemon; } // Forward declaration.

namespace TRACE
{
        // Forward declarations.
    class BufferPage;
    class Entry;
    class DaemonIf;

    /** @class Buffer
     *  @brief Class to manage the front-side (client) buffers
     *
     *  Provides interfaces for getting an entry to write trace data to and
     *  committing that entry as well as extracting the component trace.
     *
     *  Private interfaces for the daemon to ensure lockless ordering is
     *  maintained.
     */
    class Buffer
    {
        public:

            enum
            {
                /** Used as a parameter to the constructor to indicate that
                 *  the buffer should never block (and could instead run
                 *  the system out of memory). */
                UNLIMITED = UINT32_MAX
            };

            /** Constructor.
             *
             *  @param[in] i_daemon - Daemon interface for this buffer.
             *  @param[in] i_maxPages - Maximum number of pages to consume
             *                          before 'claimEntry' blocks.
             */
            Buffer(DaemonIf* i_daemon, size_t i_maxPages = 4);

            /** @brief Claim an entry from the buffer to write data to.
             *
             *  @param[in] i_comp - Component which will own entry.
             *  @param[in] i_size - Size of data portion of entry.
             *
             *  @return An entry to write to.
             *
             *  If pages allocated is at max pages and there is no room to
             *  create an entry, this function may block.  For components
             *  which cannot block, it is expected that the buffer will be
             *  constructed large enough that we run out of memory before
             *  we block.
             */
            Entry* claimEntry(ComponentDesc* i_comp, size_t i_size);

            /** @brief Commit entry to buffer and component linked-list.
             *
             *  @param[in] i_entry - Entry to commit.
             */
            void commitEntry(Entry* i_entry);

            /** @brief Extract component trace.
             *
             *  See service::getBuffer.  Defined here due to lockless ordering
             *  needs.
             */
            size_t getTrace(ComponentDesc* i_comp, void* o_data, size_t i_size);

        private:
            volatile uint64_t iv_pagesAlloc;   //< Number of pages allocated.
            uint64_t iv_pagesMax;              //< Maximum pages allowed.

            BufferPage* volatile iv_firstPage; //< Most recent page.

            /** @union locklessCounter
             *
             *  This class is mostly lockless in that multiple trace entries
             *  can be created at the same time along with buffer extraction.
             *  This means that all client operations are lockless.
             *
             *  There are minor operations that the daemon must do to ensure
             *  that a client is not in the middle of another operation, such
             *  as when the daemon removes the pages from the front-end to
             *  merge them into the backend.  During this time, the daemon
             *  will obtain the equivalent of a write-lock, which will block
             *  all clients.
             *
             *  It is required that all times where the write-lock is held
             *  are short and cannot cause page-faults that might deadlock
             *  components such as VFS and PNOR.  This means that all code
             *  inside the write-lock is in the base image.
             *
             *  This read/write lock is modeled here as "producers" (clients)
             *  and a "consumer" (daemon).  The active counts of each are
             *  recorded with this structure and unioned to a single uint64_t
             *  so that they can be atomically updated as one entity.
             */
            union locklessCounter
            {
                struct
                {
                    uint32_t producerCount;
                    uint32_t consumerCount;
                };
                uint64_t totals;
            };

            locklessCounter iv_counters; //< The producer/consumer counts.

            DaemonIf* iv_daemon; //< Daemon interface.

            /** @brief Claim front-side buffer pages to be merged into the
             *         common buffer.
             *
             *  @return Pointer to the first page (most recent) from this
             *          buffer.
             *
             *  Gives ownership of all the current pages to the caller and
             *  resets this buffer's allocated page counts.
             */
            BufferPage* claimPages();

            /** @brief Perform operations with the consumer lock held.
             *
             *  These operations cannot be done in the daemon code directly
             *  because the daemon code is swappable and we cannot block
             *  producers.
             *
             *  This function gives a set of primitives to the daemon to
             *  manipulate Entry pointers while secured under the consumer lock.
             *
             *  The primitives that can be done are:
             *     1) if (condAddr == condVal) { condActAddr = condActVal }
             *     2) addr = val
             *
             *  If any of the address parameters are NULL, their action will
             *  not be performed.  So, just calling consumerOp() has the
             *  side-effect of simply toggling the consumer lock on and off.
             *
             *  The return value indicates if primitive #1 failed.
             *
             *  @param[in] i_condAddr - The address to read for primitive 1.
             *  @param[in] i_condVal - The value to expect for primitive 1.
             *  @param[in] i_condActAddr - The address to store for primitive 1.
             *  @param[in] i_condActVal - The value to store for primitive 1.
             *
             *  @param[in] i_addr - The address to store for primitive 2.
             *  @param[in] i_val - The value to store for primitive 2.
             *
             *  @return bool - false if condAddr != condVal, true otherwise.
             */
            bool consumerOp(Entry** i_condAddr = NULL, Entry* i_condVal = NULL,
                                Entry** i_condActAddr = NULL,
                                Entry* i_condActVal = NULL,
                            Entry** i_addr = NULL, Entry* i_val = NULL);

            void _producerEnter();      //< Enter client section.
            void _producerExit();       //< Exit client section.
            void _consumerEnter();      //< Enter daemon section.
            void _consumerExit();       //< Exit daemon section.

            friend class BufferTest;
            friend class TRACEDAEMON::Daemon;
    };
}

#endif
