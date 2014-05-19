/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/kernel/taskwaittest.H $                      */
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
/** @file tasktest.H
 *  @brief Test cases for task interfaces.
 */

#include <cxxtest/TestSuite.H>
#include <sys/task.h>
#include <sys/time.h>
#include <errno.h>
#include <kernel/console.H>
#include <kernel/timemgr.H>

class TaskWaitTest : public CxxTest::TestSuite
{
    public:

        void testWaitAfterChildExit()
        {
            int status = 0x1234;
            tid_t child = task_create(&WaitSomeTime, NULL);
            WaitSomeLongerTime(NULL);

            // Join with that child task to clean it up.
            if (child != task_wait_tid(child, &status, NULL))
            {
                TS_FAIL("Failed to join with test-case child.");
            }
            if (status != TASK_STATUS_EXITED_CLEAN)
            {
                TS_FAIL("Task status is incorrect after wait.");
            }
        }

        void testWaitBeforeChildExit()
        {
            tid_t child = task_create(&WaitSomeLongerTime, NULL);
            WaitSomeTime(NULL);

            // Join with that child task to clean it up.
            if (child != task_wait_tid(child, NULL, NULL))
            {
                TS_FAIL("Failed to join with test-case child.");
            }
        }

        void testWaitOnTwoChildren()
        {
            tid_t child[2] = { task_create(&WaitSomeTime, NULL),
                               task_create(&WaitSomeTime, NULL) };

            tid_t completed = 0;

            completed = task_wait(NULL, NULL);
            if ((completed != child[0]) && (completed != child[1]))
            {
                TS_FAIL("Different child returned than one waited on.");
            }

            completed = task_wait(NULL, NULL);
            if ((completed != child[0]) && (completed != child[1]))
            {
                TS_FAIL("Different child returned than one waited on.");
            }
        }

        void testWaitOnGrandchild()
        {
            tid_t child = task_create(&TaskWithChild, NULL);
            void* retval;

            task_wait_tid(child, NULL, &retval);

            tid_t grandchild = static_cast<tid_t>(
                                    reinterpret_cast<uint64_t>(retval));

            if (grandchild != task_wait_tid(grandchild, NULL, NULL))
            {
                TS_FAIL("Grand-child task was not joined with.");
            }
        }

        void testWaitOnCrash()
        {
            int status = 1234;
            tid_t child = task_create(&TaskThatCrashes, NULL);

            task_wait_tid(child, &status, NULL);

            if (status != TASK_STATUS_CRASHED)
            {
                TS_FAIL("Task wait status is incorrect.");
            }
        }

        void testWaitDeadlock()
        {
            // Check for any thread when we don't have a child.
            if (((tid_t)-EDEADLK) != task_wait(NULL, NULL))
            {
                TS_FAIL("Deadlock condition not detected.");
            }

            // Check for waiting on the wrong task.
            tid_t child = task_create(&WaitSomeTime, NULL);
            if (((tid_t)-EDEADLK) != task_wait_tid(0, NULL, NULL))
            {
                TS_FAIL("Deadlock condition not detected.");
            }

            // Join with that child task to clean it up.
            if (child != task_wait_tid(child, NULL, NULL))
            {
                TS_FAIL("Failed to join with test-case child.");
            }
        }

        void testWaitAddrFault()
        {
            if (((tid_t)-EFAULT) != task_wait((int*)4, NULL))
            {
                TS_FAIL("Bad address on status not caught.");
            }

            if (((tid_t)-EFAULT) != task_wait(NULL, (void**)4))
            {
                TS_FAIL("Bad address on ret-val not caught.");
            }
        }

        static void* WaitSomeTime(void* retval)
        {
            nanosleep(0,TEN_CTX_SWITCHES_NS);
            return retval;
        }

        static void* WaitSomeLongerTime(void* retval)
        {
            nanosleep(0, 2*TEN_CTX_SWITCHES_NS);
            return retval;
        }

        static void* TaskWithChild(void* unused)
        {
            tid_t child = task_create(&WaitSomeTime, NULL);
            return reinterpret_cast<void*>(child);
        }

        static void* TaskThatCrashes(void* unused)
        {
            printk("Test case: Expect to see uncaught exception! ");
            *(int64_t*)(0) = 0xDEADC0DE;
            return NULL;
        }
};
