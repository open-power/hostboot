/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/service.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __TRACE_SERVICE_H
#define __TRACE_SERVICE_H

/** @file service.H
 *
 *  @brief Facade class for the front-side (client) end of trace.
 *
 *  For the lock-less trace design, clients have visibility to two entities:
 *  Component-Descriptors and Buffers.
 *
 *  The Descriptors contain information such as component name, debug on/off
 *  state, and associated buffer type as well as a linked-list of trace
 *  entries associated with the component.  Since the trace entries are
 *  maintained as a linked-list, extracting the traces is simply walking
 *  the linked-list and copying data into the extract buffer.
 *
 *  The Buffers are where new entries go when they are first created.  The
 *  buffers allow us to rate-limit entries by segregating components which
 *  can block and those which cannot block.  (Anything related to sending
 *  traces down to FSP via mailbox cannot block while adding a new trace)
 *
 *
 *  As the buffers start to fill up, a daemon is periodically triggered to
 *  harvest the trace entries and combine them into a single common buffer
 *  within the daemon.  As entries are harvested from the front end buffers
 *  they are copied into "continuous trace" buffers and sent to the FSP
 *  (and/or VPO and simics debug scripts).
 *
 *  The daemon is also responsible for ensuring that components do not
 *  exceed their trace size limit.  Since component descriptors contain
 *  a linked list of entries, the daemon can expire entries from the end of
 *  the list until the size limit is no longer exceeded for a component.
 *  Periodically, along with expiring trace entries, the daemon will
 *  coalesce back-end buffer pages to fill holes caused by expired entries.
 *
 */

#include <trace/interface.H>
#include <stdarg.h>

namespace TRACEDAEMON { class Daemon; } // Forward declaration.

namespace TRACE
{
        // Forward declarations.
    class Buffer;
    class DaemonIf;
    class ComponentList;
    class trace_entry_stamp_t;
    class RsvdTraceBufService;

    /** @class Service
     *
     *  @brief Front-end interfaces for trace.
     *
     *  There should be a singleton instance of this class.
     */
    class Service
    {
        public:
            /** Default constructor */
            Service();
            /** Default destructor */
            ~Service();

            /** @brief Write a normal entry to a trace buffer.
             *
             *  @param[in] i_td - Component Descriptor to write to.
             *
             *  @param[in] i_hash - Hash value.
             *  @param[in] i_fmt - Printf-style format string.
             *  @param[in] i_line - Line number.
             *  @param[in] i_type - TRACE_DEBUG / TRACE_FIELD
             *
             *  @param[in] i_args - Arguments corresponding to i_fmt.
             */
            void writeEntry(ComponentDesc* i_td,
                            trace_hash_val i_hash,
                            const char * i_fmt,
                            uint32_t i_line,
                            uint32_t i_type,
                            va_list i_args);

            /** @brief Write a binary entry to a trace buffer.
             *
             *  @param[in] i_td - Component Descriptor to write to.
             *
             *  @param[in] i_hash - Hash value.
             *  @param[in] i_fmt - Printf-style format string.
             *  @param[in] i_line - Line number.
             *  @param[in] i_ptr - Data to write.
             *  @param[in] i_size - Bytes to write.
             *  @param[in] i_type - TRACE_DEBUG / TRACE_FIELD
             */
            void writeBinEntry(ComponentDesc* i_td,
                               trace_hash_val i_hash,
                               const char * i_fmt,
                               uint32_t i_line,
                               const void* i_ptr,
                               uint32_t i_size,
                               uint32_t i_type);

            /** @brief Extract a component's trace buffer.
             *
             *  @param[in] i_comp - Component to extract.
             *
             *  @param[out] o_data - Buffer to copy to.
             *  @param[in] i_size - Size of buffer.
             *
             *  @return Size of buffer extracted.
             *
             *  If either (o_data == NULL) or (i_size == 0), rather than
             *  copying into the buffer, the function will calculate the size
             *  of the buffer needed to save all of the data currently in the
             *  component's trace.
             */
            size_t getBuffer(ComponentDesc* i_comp,
                             void * o_data,
                             size_t i_size);

            /** @brief Flushes the front-side buffers out to continuous trace.
             */
            void flushBuffers();

            /** @brief Sets TraceLite as enabled or disabled.
             *  @param[in] i_isEnabled - 1 for enabled, 0 for disabled
             */
            void setTraceLite(bool i_isEnabled);

            /** @brief Gets TraceLite setting (either enabled or disabled).
             *  @return 1 for enabled, 0 for disabled
             */
            bool getTraceLite();

#ifndef __HOSTBOOT_RUNTIME
            /** @brief Enable Continous Trace mode (for FSPless)
             */
            void enableContinous();

            /** @brief Disable Continous Trace mode (for FSPless)
             */
            void disableContinous();
#endif
            friend class TRACEDAEMON::Daemon;

        private:
                /** Front-size buffers */
            Buffer* iv_buffers[BUFFER_COUNT]; // slow / fast buffers.

                /** Copy the current time into the timestamp. */
            void _createTimeStamp(trace_entry_stamp_t* o_entry);

                /** Get the singleton instance. */

            static Service* getGlobalInstance();

                /** List of component descriptors. */
            ComponentList* iv_compList;

#ifndef __HOSTBOOT_RUNTIME
                /** Interface to signal daemon. */
            DaemonIf* iv_daemon;

                /** tracelite enabled **/
            bool iv_traceLite;
#else
                /** Runtime daemon **/
            TRACEDAEMON::Daemon * iv_daemon;

                /** Runtime Reserved Trace Buffer Service **/
            RsvdTraceBufService * iv_rsvdtracebufservice;
#endif
    };
}

#endif
