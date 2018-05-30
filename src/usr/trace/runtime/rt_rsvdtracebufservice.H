/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_rsvdtracebufservice.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#ifndef __RSVD_TRACE_SERVICE_H
#define __RSVD_TRACE_SERVICE_H

/** @file rt_rsvdtracebufservice.H
 *
 *  @brief class with functions to write HBRT traces in to Reserved Trace Buffer
 *
 *  In the constructor, this will get the reserved memory section through
 *  hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_TRACEBUF) and uses the buffer
 *  to write the HBRT traces of all components serially.
 *  Writing to Reserved Trace Buffer is serialized in this class via Mutex
 *
 *  Reserved Trace Buffer is a wrappable circular buffer, oldest entries
 *  are deleted to write the new trace entries
 *
 */

#include "rt_rsvdtracebuffer.H"   // RsvdTraceBuffer
#include <errl/errlentry.H>       // errlHndl_t

// Forward declaration of the test suite
class RsvdTraceBuffTestSuite;

namespace TRACE
{
    // Forward declarations
    class ComponentDesc;

    /** @class RsvdTraceBufService
     *
     *  @brief Front-end interfaces for reserved trace buffer.
     *
     *  There should be a single instance(a singleton) of this class with
     *  delayed construction.  Constructed when needed not at start up.
     */
    class RsvdTraceBufService
    {
        public:
            /** Default constructor */
            RsvdTraceBufService();

            /** Initializes the buffer, if previously not done.*/
            void init();

            /** Commits the iv_errl with Trace from previous boot,
             *  if created in init()
             *
             *  @return true if iv_errl is valid, otherwise false.
             */
            bool commitRsvdMemTraceErrl();

            /** @brief Write a Normal/Binary entry to a trace buffer
             *
             *  @param[in] i_componentDesc - Component Descriptor to write to.
             *
             *  @param[in] i_data - pointer to the FSP formatted trace data.
             *  @param[in] i_size - size of the data
             */
            void writeEntry(ComponentDesc* i_componentDesc,
                            char*          i_data,
                            uint32_t       i_dataSize);


            /** @brief Extracts Reserved Trace buffer.
             *
             *  @param[out] o_data - Data buffer to copy to.
             *  @param[in] i_size - Size of buffer.
             *
             *  @return Size of buffer extracted.
             *
             *  If either (o_data == NULL) or (i_size == 0), rather than
             *  copy data from the internal buffer, the function will calculate
             *  the size of the data buffer needed to save all of the data
             *  currently in the internal buffer.
             */
            uint32_t getBuffer(void * o_data, uint32_t i_dataSize) const;

        private:

            /** @brief Retrieve the trace info left behind in
             *         buffer from last crash
             */
            void retrieveDataFromLastCrash();

            /** The reserved trace buffer section,
             *  which contains the runtime traces
             */
            RsvdTraceBuffer iv_rsvdTraceBuffer;

            /** errlHandl to hold the trace from the previous boot, if any */
            errlHndl_t iv_errl;

            // For testing purposes only
            friend class ::RsvdTraceBuffTestSuite;
    };
}

#endif
