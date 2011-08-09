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
#include <stdio.h>

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

    /**
     * @test Test max component name size
     */
    void testTracCompName(void)
    {
        trace_desc_t *g_trac_test = NULL;
        char l_comp[] = "EXAMPLE89ABCDEFGHI";

        TRAC_INIT_BUFFER(&g_trac_test, l_comp, 4096);

        if(g_trac_test == NULL)
        {
            TS_FAIL("g_trac_test was returned as NULL!");
        }
        else
        {
            TRACFCOMP(g_trac_test, INFO_MRK"Testing max component name");
        }
    }

    /**
     * @test Test trace macros
     */
    void testTracMacros(void)
    {
        trace_desc_t *g_trac_test = NULL;
        char l_comp[] = "TEST";

        #define __COMP_TD__ g_trac_test
        #define __COMP_NAMESPACE__ "TRACE"
        #define __COMP_CLASS__ "TraceTest"
        #define __COMP_FN__ "testTracMacros"

        TRAC_INIT_BUFFER(&g_trac_test, l_comp, 4096);

        if(g_trac_test == NULL)
        {
            TS_FAIL("g_trac_test was returned as NULL!");
        }
        else
        {
            TRAC_ENTER("testTracMacros");
            TRAC_ENTER_();
            TRAC_INF("Testing Info Mark");
            TRAC_ERR("Testing Error Mark");
            TRAC_EXIT("testTracMacros");
            TRAC_EXIT_();

            DTRAC_ENTER("testTracMacros - Debug Trace");
            DTRAC_ENTER_(" - Debug Trace");
            DTRAC_INF("Testing Debug Info Mark");
            DTRAC_ERR("Testing Debug Error Mark");
            DTRAC_EXIT("testTracMacros - Debug Trace");
            DTRAC_EXIT_(" - Debug Trace");
        }

        #undef __COMP_FN__
        #undef __COMP_CLASS__
        #undef __COMP_NAMESPACE__
        #undef __COMP_TD__
    }

    /**
     * @test Test String Trace Interface
     */
    void testTracString(void)
    {
        trace_desc_t *g_trac_test = NULL;
        TRAC_INIT_BUFFER(&g_trac_test, "STRING", 4096);

        if(g_trac_test == NULL)
        {
            TS_FAIL("g_trac_test was returned as NULL!");
        }
        else
        {
            TRACFCOMP(g_trac_test,"String at end '%s'", "Last");
            TRACFCOMP(g_trac_test,"%s: String at beginning", "FIRST");
            TRACFCOMP(g_trac_test,"Test '%s' string", "middle");

            const char * str = "This is a \tlong string\nwith horizontal tab and newline.";
            TRACFCOMP(g_trac_test,"Testing (c,u,s,X): %c, %u, %s 0x%X", 'b',0x11,str,10);

            TRACFCOMP(g_trac_test,"Testing string len 1: %s, %s, %s", "A", "B", "C");
            TRACFCOMP(g_trac_test,"Testing NULL string: %s", "");

            TRACFCOMP(g_trac_test,"Testing string alignment: %s %s", "hello", "world");
            TRACFCOMP(g_trac_test,"Testing string alignment: %s %s", "Hostboot", "Software");
            TRACFCOMP(g_trac_test,"Testing string alignment: %s %s", "Hostboot2", "Software3");

            TRACFCOMP(g_trac_test,"%s %s %s %s", "Four", "strings", "by", "themselves");

            TRACFCOMP(g_trac_test,"Testing special characters: %s",
                      "?!@#$%^&*()\"/\'\\<>.,:;");

            TRACFCOMP(g_trac_test,"Testing percent: %% %%%d %%%s 100%%", 50, "hello");

            TRACFCOMP(g_trac_test, INFO_MRK"Testing all number types (s,c,u,X,d): %s, %c %u 0x%X %d",
                      "hello",'a',10,11,12);
            TRACFCOMP(g_trac_test, "Testing all number types (c,u,s,X,d): %c %u %s 0x%X %d",
                      'b',13,"world!",14,15);
            TRACFCOMP(g_trac_test, "Testing all number types (c,u,X,d,s): %c %u 0x%X %d %s",
                      'c',16,17,18,"Hostboot");
            TRACFCOMP(g_trac_test, "Testing all number types (s,c,s,u,s,X): %s %c %s %u %s 0x%X",
                      "Astring",'d',"Bstring12",19,"Cstring123",20);
        }
    }

    /**
     * @test Test max number of buffers
     */
    void testTracMaxBuffers(void)
    {
        trace_desc_t *g_trac_test = NULL;
        char l_comp[8] = "TRACE";

        for (uint32_t i=0; i < 26; i++)
        {
            sprintf (l_comp, "TRACE%d", i);
            
            g_trac_test = NULL;
            TRAC_INIT_BUFFER(&g_trac_test, l_comp, 4096);

            if(g_trac_test == NULL)
            {
                TS_FAIL("g_trac_test was returned as NULL!");
            }
            else
            {
                TRACFCOMP(g_trac_test, INFO_MRK"Testing max buffers %u", i);
            }
        }
    }
};

#endif

