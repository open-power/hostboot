#ifndef __TEST_TRACETEST_H
#define __TEST_TRACETEST_H

/**
 *  @file tracetest.H
 *
 *  @brief All unit tests for the trace module in host boot.
*/

#include <cxxtest/TestSuite.H>
//#include <trace/interface.H>
#include <tracinterface.H>

class TraceTest : public CxxTest::TestSuite
{
public:

    /**
     * @test Test Component Trace Interfaces
     */
    void testTracComp(void)
    {
        trace_desc_t *g_trac_test = NULL;
        TRAC_INIT_BUFFER(&g_trac_test, "EXAMPLE", 4096);

        if(g_trac_test == NULL)
        {
            TS_FAIL("g_trac_test was returned as NULL!");
        }
        else
        {
            // Component trace tests - There is no easy way to validate these
            // are working but we can at least ensure we don't cause host boot
            // to crash when running them.

            for(uint32_t i=0;i<100;i++)
            {
                TRACFCOMP(g_trac_test, "Thread ID: %d", task_gettid());
                TRACFCOMP(g_trac_test, "Validate all number types (c,u,X,d): %c %u 0x%X %d",
                          'a',i,i+1,i+2);

                TRACFCOMP(g_trac_test, "Validate pointer type (p): %p",
                          g_trac_test);

                TRACFCOMP(g_trac_test, "64 Bit Value Test - 0x123456789ABCDEF0: 0x%X",
                          0x123456789ABCDEF0);

                // Do a debug trace
                TRACDCOMP(g_trac_test,"This is a debug trace");

                // Need to run a formatting test, but I know it will fail.
            }

            // Be sure a NULL trace descriptor does not cause a failure
            TRACFCOMP(NULL,"This trace should never show up");

        }
    }

    /**
     * @test Test Binary Trace Interface
     */
    void testTracBinary(void)
    {
        trace_desc_t *g_trac_test = NULL;
        TRAC_INIT_BUFFER(&g_trac_test, "EXAMPLE", 4096);

        if(g_trac_test == NULL)
        {
            TS_FAIL("g_trac_test was returned as NULL!");
        }
        else
        {
            // Binary trace tests - There is no easy way to validate these
            // are working but we can at least ensure we don't cause host boot
            // to crash when running them.
            TRACFBIN(g_trac_test,"Binary dump of trace descriptor",
                     g_trac_test,sizeof(trace_desc_t));

            TRACDBIN(g_trac_test,"Unaligned Debug binary trace of the trace descriptor",
                     g_trac_test,9);

            // Be sure a NULL trace descriptor does not cause a failure
            TRACFBIN(NULL,"This trace should never show up",
                     g_trac_test,sizeof(trace_desc_t));

            // Be sure it handles a size of 0
            TRACFBIN(NULL,"This trace should never show up - 0 size",
                     g_trac_test,0);
        }
    }

    /**
     * @test Test a mix of traces
     */
    void testTracMix(void)
    {
        trace_desc_t *g_trac_test = NULL;
        TRAC_INIT_BUFFER(&g_trac_test, "EXAMPLE", 4096);

        if(g_trac_test == NULL)
        {
            TS_FAIL("g_trac_test was returned as NULL!");
        }
        else
        {
            uint32_t l_size = 0;

            for(uint32_t i=0;i<100;i++)
            {

                TRACFCOMP(g_trac_test, INFO_MRK"Validate all number types (c,u,X,d): %c %u 0x%X %d",
                          'a',i,i+1,i+2);

                l_size = i % sizeof(trace_desc_t);

                TRACFBIN(g_trac_test,"Unaligned Binary dump of trace descriptor",
                         g_trac_test,l_size);

                TRACFCOMP(g_trac_test, "64 Bit Value Test - 0x123456789ABCDEF0: 0x%X",
                          0x123456789ABCDEF0);

            }
        }
    }
};

#endif

