/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/assert.C $                                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
