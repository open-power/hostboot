/** @file assert.C
 *  Hooks for dealing with trace in assert statements.
 *
 *  This hook function is registered with the system-library assert functions
 *  when the trace library loads, so that if an application asserts after that
 *  point in time a message will get added to a common ASSERT trace buffer.
 */
#include <assert.h>
#include <trace/interface.H>

namespace TRACE
{
    /** Unique trace buffer for assert statements. */
    trace_desc_t* g_assertTraceBuffer;
    TRAC_INIT(&g_assertTraceBuffer, "ASSERT", 4096);
    
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
