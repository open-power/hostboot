#ifndef __SLBTEST_H
#define __SLBTEST_H
/**
 *  @file slbtest.H
 *
 *  @brief Test cases for the segment lookaside buffers
*/
#include <cxxtest/TestSuite.H>
#include <arch/ppc.H>
#include <sys/time.h>
#include <sys/task.h>

class slbtest: public CxxTest::TestSuite
{
    public:

        static volatile int rc;

        void testSLB()
        {
            rc = 0;
            task_create(writeEA1TB, this);
            while (rc == 0) task_yield();
            task_yield();
            if (rc == -1)
            {
                TS_FAIL("Data Segment exception expected in 1TB segment\n");
            }

            rc = 0;
            task_create(writeEA2TB, this);
            while (rc == 0) task_yield();
            task_yield();
            if (rc == -1)
            {
                TS_FAIL("Data Storage exception expected in 2TB segment\n");
            }
        }

    private:

        static void writeEA1TB(void *i_p)
        {
            rc = 1;
            sync();
            *(int *)0x10000000000 = 1;
            sync();
            rc = -1;
            task_end();
        }

        static void writeEA2TB(void *i_p)
        {
            rc = 1;
            sync();
            *(int *)0x20000000000 = 1;
            sync();
            rc = -1;
            task_end();
        }
};
volatile int slbtest::rc = 0;

#endif
