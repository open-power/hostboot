//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/kernel/vmmbasetest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/** @file vmmbasetest.H
 *  @brief Test cases for permission settings on the base block of the VMM.
 */
#ifndef __KERNEL_VMMBASETEST_H
#define __KERNEL_VMMBASETEST_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>
#include <kernel/console.H>
#include <arch/ppc.H>

class VmmBaseTest : public CxxTest::TestSuite
{
    public:
        static volatile int rc;

        void testNullAccess()
        {
            rc = 0; sync();
            printk("Test case: Expect to see uncaught exception! ");
            task_create(readFromNULL, NULL);
            while (rc == 0) task_yield();
            task_yield();
            if (rc == -1)
            {
                TS_FAIL("Write to NULL not caught.");
            }

            rc = 0; sync();
            printk("Test case: Expect to see uncaught exception! ");
            task_create(writeToNULL, NULL);
            while (rc == 0) task_yield();
            task_yield();
            if (rc == -1)
            {
                TS_FAIL("Write to NULL not caught.");
            }
        }

        void testWriteToKernelCode()
        {
            rc = 0; sync();
            printk("Test case: Expect to see uncaught exception! ");
            task_create(writeToKernelCode, NULL);
            while (rc == 0) task_yield();
            task_yield();
            if (rc == -1)
            {
                TS_FAIL("Write to kernel code not caught.");
            }
        }

        void testExecuteKernelDataSpace()
        {
            // @TODO. VMM not ready.
        }

        void testWriteModuleText()
        {
            // @TODO. VMM not ready.
        }

        void testExecuteModuleDataSpace()
        {
            // @TODO. VMM not ready.
        }

    private:

        static void readFromNULL(void* unused)
        {
            rc = 1; sync();
            printk("%lx", (*(uint64_t*)NULL)); sync();
            rc = -1; sync();
            task_end();
        }

        static void writeToNULL(void* unused)
        {
            rc = 1; sync();
            (*(uint64_t*)NULL) = 0x12345678; sync();
            rc = -1; sync();
            task_end();
        }

        static void writeToKernelCode(void* unused)
        {
            rc = 1; sync();
            (*(*(uint64_t**)&printk)) = 0x12345678; sync();
            rc = -1; sync();
            task_end();
        }

};
volatile int VmmBaseTest::rc = 0;

#endif
