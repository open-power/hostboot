//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/util/test/threadpool.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __UTIL_TEST_THREADPOOL_H
#define __UTIL_TEST_THREADPOOL_H

#include <cxxtest/TestSuite.H>
#include <util/threadpool.H>

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

};


class ThreadPoolTest: public CxxTest::TestSuite
{
    public:
        /** Test that we can construct a ThreadPool for both FIFO and non-FIFO
         *  ordered pools. */
        void testSimpleWorkItem()
        {
            Util::ThreadPool<__ThreadPoolTest::Simple> instance;
            uint64_t value = 0;

            instance.insert(new __ThreadPoolTest::Simple(&value));
            instance.start();
            instance.shutdown();

            if (value == 0)
            {
                TS_FAIL("Value was not changed by Simple worker thread.");
            }

            Util::ThreadPool<__ThreadPoolTest::SimpleOrdered> instance2;
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
            Util::ThreadPool<__ThreadPoolTest::EnsureThreads> instance;
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
            Util::ThreadPool<__ThreadPoolTest::EnsureOrder> instance;
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
};

#endif
