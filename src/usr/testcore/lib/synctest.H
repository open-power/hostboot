//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/lib/synctest.H $
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
#ifndef __SYNCTEST_H
#define __SYNCTEST_H
/**
 *  @file synctest.H
 *
 *  @brief Test cases for the sycronization
*/

#include <cxxtest/TestSuite.H>
#include <sys/sync.h>
#include <sys/task.h>
#include <sys/time.h>

#include <kernel/timemgr.H>

#define NS_PER_SEC (1000000ull)
#define TEN_CTX_SWITCHES ((NS_PER_SEC/TimeManager::TIMESLICE_PER_SEC)*10)

class SyncTest: public CxxTest::TestSuite
{
    public:


        void testMutex()
        {
            mutex_init(&mutex);
            barrier_init(&barrier, 7);

            task_create(func1, this);
            task_create(func2, this);
            task_create(func2, this);
            task_create(func2, this);
            task_create(func2, this);
            task_create(func2, this);
            barrier_wait(&barrier);
            TS_TRACE("ALL THREADS ENDED");
        }

        void testMutexDoubleWait()
        {
            mutex_init(&mutex);
            barrier_init(&barrier, 3);

            mutex_lock(&mutex);
            task_create(func2, this);
            task_create(func2, this);
            nanosleep(0,TEN_CTX_SWITCHES);
            mutex_unlock(&mutex);
            barrier_wait(&barrier);
            TS_TRACE("ALL THREADS ENDED");
        }

        void testBarrier()
        {
            barrier_t barrier;
            barrier_init(&barrier,3);
            task_create(func3,&barrier);
            task_create(func4,&barrier);
            barrier_wait(&barrier);
            TS_TRACE("B0");
            barrier_destroy(&barrier);
        }

    private:

        mutex_t mutex;
        barrier_t barrier;

        static void func1(void * i_p)
        {
            SyncTest * my = (SyncTest *) i_p;
            mutex_t * mutex = &(my->mutex);
            barrier_t * barrier = &(my->barrier);

            mutex_lock(mutex);
            for(int i = 0; i < 100000; ++i);
            TS_TRACE("ME FIRST");
            mutex_unlock(mutex);
            barrier_wait(barrier);
            task_end();
        }

        static void func2(void * i_p)
        {
            SyncTest * my = (SyncTest *) i_p;
            mutex_t * mutex = &(my->mutex);
            barrier_t * barrier = &(my->barrier);

            mutex_lock(mutex);
            TS_TRACE("ME NEXT");
            mutex_unlock(mutex);
            barrier_wait(barrier);
            task_end();
        }

        static void func3(void * i_p)
        {
            barrier_t * barrier = (barrier_t *) i_p;
            barrier_wait(barrier);
            TS_TRACE("B1");
            task_end();
        }
        static void func4(void * i_p)
        {
            barrier_t * barrier = (barrier_t *) i_p;
            barrier_wait(barrier);
            TS_TRACE("B2");
            task_end();
        }

};
#endif

