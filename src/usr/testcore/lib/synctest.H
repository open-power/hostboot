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
#include <utility>

#include <kernel/timemgr.H>
#include <kernel/console.H>

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
            nanosleep(0,TEN_CTX_SWITCHES_NS);
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

        void testConditionVariable()
        {

            mutex_init(&mutex);
            sync_cond_init(&cond_var);

            counter = 0;

            barrier_init(&barrier,4);

            TASK_INFO t1(this,1);
            TASK_INFO t2(this,2);
            TASK_INFO t3(this,3); 

            task_create(watch_counter, &t1);
            task_create(increment, &t2);
            task_create(increment, &t3);

            barrier_wait(&barrier);
            TS_TRACE("Conditional Variable test final count = %ld",counter);
            barrier_destroy(&barrier);
            sync_cond_destroy(&cond_var);
            mutex_destroy(&mutex);
            // test is success if it completes w/o hang
        }

        void testConditionVariableBroadcast()
        {
            mutex_init(&mutex);
            sync_cond_init(&cond_var);

            counter = 0;

            barrier_init(&barrier,5);

            TASK_INFO t1(this,4);
            TASK_INFO t2(this,5);
            TASK_INFO t3(this,6); 
            TASK_INFO t4(this,7);

            task_create(watch_counter, &t1);
            task_create(watch_counter, &t2);
            task_create(increment1, &t3);
            task_create(increment1, &t4);

            barrier_wait(&barrier);
            TS_TRACE("Conditional Variable test final count = %ld",counter);
            barrier_destroy(&barrier);
            sync_cond_destroy(&cond_var);
            mutex_destroy(&mutex);
            // test is success if it completes w/o hang
        }



            

    private:

        enum 
        { 
            TO_COUNT = 10,
            COUNT_SIGNAL = 13
        };

        typedef std::pair<SyncTest*, size_t> TASK_INFO;

        mutex_t mutex;
        barrier_t barrier;
        sync_cond_t cond_var;

        size_t counter;


        static void func1(void * i_p)
        {
            SyncTest * my = (SyncTest *) i_p;
            mutex_t * mutex = &(my->mutex);
            barrier_t * barrier = &(my->barrier);

            mutex_lock(mutex);
            nanosleep(0,TEN_CTX_SWITCHES_NS);
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

        static void watch_counter(void * i_p)
        {
            TASK_INFO * info = (TASK_INFO *) i_p;
            SyncTest * my = info->first;
            TS_TRACE("CONDVAR task %ld. Start watching counter",info->second);
            mutex_lock(&(my->mutex));
            while(my->counter < COUNT_SIGNAL)
            {
                sync_cond_wait(&(my->cond_var),&(my->mutex));
                TS_TRACE("CONDVAR task %ld. Condition signal received",
                         info->second);
                my->counter += 100;
                TS_TRACE("CONDVAR task %ld. Counter = %ld",
                         info->second,my->counter);
            }
            mutex_unlock(&(my->mutex));
            barrier_wait(&(my->barrier));
        }


        static void increment(void * i_p)
        {
            TASK_INFO * info = (TASK_INFO *) i_p;
            SyncTest * my = info->first;
            TS_TRACE("CONDVAR task %ld. start Increment counter",info->second);
            for(size_t i = 0; i < TO_COUNT; ++i)
            {
                mutex_lock(&(my->mutex));
                ++(my->counter);

                if(my->counter == COUNT_SIGNAL)
                {
                    sync_cond_signal(&(my->cond_var));
                    TS_TRACE("CONDVAR task %ld. INCR counter = %ld Threshold"
                             " reached",info->second,my->counter);
                }
                TS_TRACE("CONDVAR task %ld INCR counter = %ld Unlocking mutex",
                         info->second, my->counter);
                mutex_unlock(&(my->mutex));
                nanosleep(0,TEN_CTX_SWITCHES_NS);
            }
            barrier_wait(&(my->barrier));
        }

        static void increment1(void * i_p)
        {
            TASK_INFO * info = (TASK_INFO *) i_p;
            SyncTest * my = info->first;
            TS_TRACE("CONDVAR task %ld. start Increment counter",info->second);
            for(size_t i = 0; i < TO_COUNT; ++i)
            {
                mutex_lock(&(my->mutex));
                ++(my->counter);

                if(my->counter == COUNT_SIGNAL)
                {
                    sync_cond_broadcast(&(my->cond_var));
                    TS_TRACE("CONDVAR task %ld. INCR counter = %ld Threshold"
                             " reached",info->second,my->counter);
                }
                TS_TRACE("CONDVAR task %ld INCR counter = %ld Unlocking mutex",
                         info->second, my->counter);
                mutex_unlock(&(my->mutex));
                nanosleep(0,TEN_CTX_SWITCHES_NS);
            }
            barrier_wait(&(my->barrier));
        }

};
#endif

