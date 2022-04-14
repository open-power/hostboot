/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/test/threadpool.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifndef __UTIL_TEST_THREADPOOL_H
#define __UTIL_TEST_THREADPOOL_H

#include <cxxtest/TestSuite.H>
#include <util/threadpool.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <util/util_reasoncodes.H>
#include <hbotcompid.H>
#include <kernel/console.H>

// Thread pool constructor flags
#define DISABLE_CHILD_RC_CHECKING false
#define CHECK_CHILD_RC true

namespace __ThreadPoolTest
{
    /** WorkItem that simply modifies a pointer. */
    struct Simple
    {
        explicit Simple(uint64_t* _v) : iv_value(_v) {};
        void operator()() { (*iv_value) = 0xABCD; };

        private:
            uint64_t* iv_value;
    };

    /** WorkItem that modifies a value and has an order function. */
    struct SimpleOrdered : public Simple
    {
        explicit SimpleOrdered(uint64_t* _v) : Simple(_v) {};
        bool operator<(const SimpleOrdered& rhs) { return false; };
    };

    /** WorkItem that touches a barrier to ensure at least a certain number
     *  of threads have been spawned. */
    struct EnsureThreads
    {
        explicit EnsureThreads(barrier_t* _b) : iv_barrier(_b) {};
        void operator()() { barrier_wait(iv_barrier); };

        private:
            barrier_t* iv_barrier;
    };

    /** WorkItem with an order function that modifies a value in order
     *  sequence.
     *
     *  An EnsureOrder workitem is created with 0, 1, 2, etc.  The order
     *  function ensures that item-0 should run before item-1, etc.  To
     *  perform the test, a read-modify-write of a shared value is performed.
     *  The value should be at the item-n value and the WorkItem increments
     *  the value.
     *
     *  There is no issues with weak consistency with this object because only
     *  a single thread is executing against the pool at this time.
     */
    struct EnsureOrder
    {
        EnsureOrder(uint64_t _i, uint64_t* _v) : iv_id(_i), iv_value(_v) {};
        void operator()()
            {
                if ((*iv_value) != iv_id)
                {
                    TS_FAIL("ID number wrong. %d:%d", (*iv_value), iv_id);
                }
                (*iv_value) = iv_id + 1;
            }
        bool operator<(const EnsureOrder& rhs) { return iv_id < rhs.iv_id; };

        private:
            uint64_t iv_id;
            uint64_t* iv_value;
    };

    /** A simple work item that causes the task to crash */
    struct CrashedTask
    {
        CrashedTask() {};
        void operator()()
        {
            uint8_t* l_ptr = nullptr;
            *l_ptr = 1;
        }
    };

};


class ThreadPoolTest: public CxxTest::TestSuite
{
    public:
        /** Test that we can construct a ThreadPool for both FIFO and non-FIFO
         *  ordered pools. */
        void testSimpleWorkItem()
        {
            Util::ThreadPool<__ThreadPoolTest::Simple>
                    instance(DISABLE_CHILD_RC_CHECKING);
            uint64_t value = 0;

            instance.insert(new __ThreadPoolTest::Simple(&value));
            instance.start();
            instance.shutdown();

            if (value == 0)
            {
                TS_FAIL("Value was not changed by Simple worker thread.");
            }

            Util::ThreadPool<__ThreadPoolTest::SimpleOrdered>
                    instance2(DISABLE_CHILD_RC_CHECKING);
            value = 0;

            instance2.insert(new __ThreadPoolTest::SimpleOrdered(&value));
            instance2.start();
            instance2.shutdown();

            if (value == 0)
            {
                TS_FAIL("Value was not changed by SimpleOrdered"
                        "worker thread.");
            }

        }

        /** Test that the thread manager function creates at least as many
         *  threads as directed. */
        void testThreadManager()
        {
            Util::ThreadPool<__ThreadPoolTest::EnsureThreads>
                    instance(DISABLE_CHILD_RC_CHECKING);
            barrier_t barrier;

            for (size_t count = 1; count < 5; count++)
            {
                Util::ThreadPoolManager::setThreadCount(count);
                barrier_init(&barrier, count);

                for (size_t i = 0; i < count; i++)
                {
                    instance.insert(
                        new __ThreadPoolTest::EnsureThreads(&barrier));
                }

                instance.start();
                instance.shutdown();

                barrier_destroy(&barrier);
            }
        }

        /** Test that the order functions work on the thread pool. */
        void testThreadOrder()
        {
            Util::ThreadPool<__ThreadPoolTest::EnsureOrder>
                    instance(DISABLE_CHILD_RC_CHECKING);
            uint64_t value = 0;

            // Ensure that adding work items in order works.
            Util::ThreadPoolManager::setThreadCount(1);
            for (uint64_t i = 0; i < 29; i++)
            {
                instance.insert(new __ThreadPoolTest::EnsureOrder(i, &value));
            }

            instance.start();
            instance.shutdown();

            // Ensure that adding work items in reverse order works.
            value = 0;
            for (uint64_t i = 0; i < 29; i++)
            {
                instance.insert(
                    new __ThreadPoolTest::EnsureOrder(28 - i, &value));
            }

            instance.start();
            instance.shutdown();

            // Ensure that adding work items in a unsorted order works.
            //
            // Since 29 is a prime, i*n mod 29 generates the additive group of
            // all integers (mod 29).  Use this to create a pseudo-random
            // ordering of the integers 0-28: 0, 23, 17, 11, 5, 28, 22, ...
            value = 0;
            for (uint64_t i = 0; i < 29; i++)
            {
                instance.insert(
                    new __ThreadPoolTest::EnsureOrder((i*23) % 29, &value));

            }

            instance.start();
            instance.shutdown();
        }

        /** Test a good child task that doesn't return an error. */
        void testChildRCGoodTask()
        {
            TS_INFO(ENTER_MRK"testChildRCGoodTask");
            Util::ThreadPool<__ThreadPoolTest::Simple>
                    l_threadPool(CHECK_CHILD_RC);
            uint64_t l_value = 0;

            do {
            l_threadPool.insert(new __ThreadPoolTest::Simple(&l_value));
            l_threadPool.start();
            errlHndl_t l_errl = l_threadPool.shutdown();
            if(l_errl)
            {
                TS_FAIL("testChildRCGoodTask: an unexpected error log (EID 0x%.8x) returned from the thread pool", l_errl->eid());
                errlCommit(l_errl, CXXTEST_COMP_ID);
                break;
            }

            if(l_value == 0)
            {
                TS_FAIL("testChildRCGoodTask: the test value was not changed by the child task");
                break;
            }

            }while(0);
            TS_INFO(EXIT_MRK"testChildRCGoodTask");
        }

        /** Test that the crashed task's error log is returned to thread pool
            correctly */
        void testChildRCCrashedTask()
        {
            TS_INFO(ENTER_MRK"testChildRCCrashedTask");
            Util::ThreadPool<__ThreadPoolTest::CrashedTask>
                    l_threadPool(CHECK_CHILD_RC);
            errlHndl_t l_errl = nullptr;

            do {
            printk("testChildRCCrashedTask: Expect to see uncaught exception\n");
            l_threadPool.insert(new __ThreadPoolTest::CrashedTask());
            l_threadPool.start();
            l_errl = l_threadPool.shutdown();
            if(!l_errl)
            {
                TS_FAIL("testChildRCCrashedTask: the thread pool did not return an error log as was expected");
                break;
            }

            if(l_errl->moduleId() != Util::UTIL_MOD_TP_SHUTDOWN)
            {
                TS_FAIL("testChildRCCrashedTask: unexpected moduleId returned from EID 0x%.8x; expected: 0x%x; actual: 0x%x",
                        l_errl->eid(),
                        Util::UTIL_MOD_TP_SHUTDOWN,
                        l_errl->moduleId());
                break;
            }

            if(l_errl->reasonCode() != Util::UTIL_RC_CHILD_TASK_FAILED)
            {
                TS_FAIL("testChildRCCrashedTask: unexpected return code from EID 0x%.8x; expected: 0x%x; actual 0x%x",
                        l_errl->eid(),
                        Util::UTIL_RC_CHILD_TASK_FAILED,
                        l_errl->reasonCode());
                break;
            }
            }while(0);

            if(l_errl)
            {
                ERRORLOG::errlCommit(l_errl, CXXTEST_COMP_ID);
            }
            TS_INFO(EXIT_MRK"testChildRCCrashedTask");
        }

        /* Test that error is not returned by crashed task when explicitly
           not requested by thread pool */
        void testChildNoRCCrashedTask()
        {
            TS_INFO(ENTER_MRK"testChildNoRCCrashedTask");
            Util::ThreadPool<__ThreadPoolTest::CrashedTask>
                        l_threadPool(DISABLE_CHILD_RC_CHECKING);
            errlHndl_t l_errl = nullptr;

            printk("testChildNoRCCrashedTask: Expect to see uncaught exception\n");
            l_threadPool.insert(new __ThreadPoolTest::CrashedTask());
            l_threadPool.start();
            l_errl = l_threadPool.shutdown();

            if(l_errl)
            {
                TS_FAIL("testChildNoRCCrashedTask: unexpected error returned from the thread pool (EID 0x%.8x)", l_errl->eid());
                ERRORLOG::errlCommit(l_errl, CXXTEST_COMP_ID);
            }

            TS_INFO(EXIT_MRK"testChildNoRCCrashedTask");
        }
};

#endif
