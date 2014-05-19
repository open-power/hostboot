/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/assert.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/** @file assert.C
 *  Hooks for dealing with trace in assert statements.
 *
 *  This hook function is registered with the system-library assert functions
 *  when the trace library loads, so that if an application asserts after that
 *  point in time a message will get added to a common ASSERT trace buffer.
 */
#include <assert.h>
#include <trace/interface.H>
#include <limits.h>

namespace TRACE
{
    /** Unique trace buffer for assert statements. */
    trace_desc_t* g_assertTraceBuffer;
    TRAC_INIT(&g_assertTraceBuffer, "ASSERT", KILOBYTE, TRACE::BUFFER_SLOW);

    /** @fn assertTrace
     *  @brief Hook to perform a trace on an assert failure.
     *
     *  @param[in] i_linkRegister - Address from which 'assert' was called.
     *  @param[in] i_lineNumber - Line number in the file which 'assert'ed.
     */
    void assertTrace(void* i_linkRegister, size_t i_lineNumber)
    {
        TRACFCOMP(g_assertTraceBuffer,
                  "Assertion failed @%p on line %d.",
                  i_linkRegister, i_lineNumber);
    }

    /** Location to assign the assertTrace hook for __assert function to use. */
    extern void(*traceCallback)(void*, size_t);

    /** @class __init_trace_callback
     *  @brief Class which registers the assertTrace function statically.
     */
    class __init_trace_callback
    {
        public:
            __init_trace_callback() { traceCallback = &assertTrace; };
    };
    __init_trace_callback __init_trace_callback_instance;
};
