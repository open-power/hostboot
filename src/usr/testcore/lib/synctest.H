/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/synctest.H $                             */
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

            TASK_INFO t1 = { this, 1, 0};
            TASK_INFO t2 = { this, 2, 0};
            TASK_INFO t3 = { this, 3, 0};

            t1.tid = task_create(watch_counter, &t1);
            t2.tid = task_create(increment, &t2);
            t3.tid = task_create(increment, &t3);

            barrier_wait(&barrier);
            TS_TRACE("Conditional Variable test final count = %ld",counter);
            task_wait_tid(t1.tid, NULL, NULL);
            task_wait_tid(t2.tid, NULL, NULL);
            task_wait_tid(t3.tid, NULL, NULL);
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

            TASK_INFO t1 = { this, 4, 0};
            TASK_INFO t2 = { this, 5, 0};
            TASK_INFO t3 = { this, 6, 0};
            TASK_INFO t4 = { this, 7, 0};

            t1.tid = task_create(watch_counter, &t1);
            t2.tid = task_create(watch_counter, &t2);
            t3.tid = task_create(increment1, &t3);
            t4.tid = task_create(increment1, &t4);

            barrier_wait(&barrier);
            TS_TRACE("Conditional Variable test final count = %ld",counter);
            task_wait_tid(t1.tid, NULL, NULL);
            task_wait_tid(t2.tid, NULL, NULL);
            task_wait_tid(t3.tid, NULL, NULL);
            task_wait_tid(t4.tid, NULL, NULL);
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

        struct TASK_INFO { SyncTest* testobj; size_t id;  tid_t tid; };

        mutex_t mutex;
        barrier_t barrier;
        sync_cond_t cond_var;

        size_t counter;


        static void* func1(void * i_p)
        {
            SyncTest * my = (SyncTest *) i_p;
            mutex_t * mutex = &(my->mutex);
            barrier_t * barrier = &(my->barrier);

            mutex_lock(mutex);
            nanosleep(0,TEN_CTX_SWITCHES_NS);
            TS_TRACE("ME FIRST");
            mutex_unlock(mutex);
            barrier_wait(barrier);
            return NULL;
        }

        static void* func2(void * i_p)
        {
            SyncTest * my = (SyncTest *) i_p;
            mutex_t * mutex = &(my->mutex);
            barrier_t * barrier = &(my->barrier);

            mutex_lock(mutex);
            TS_TRACE("ME NEXT");
            mutex_unlock(mutex);
            barrier_wait(barrier);
            return NULL;
        }

        static void* func3(void * i_p)
        {
            barrier_t * barrier = (barrier_t *) i_p;
            barrier_wait(barrier);
            TS_TRACE("B1");
            return NULL;
        }
        static void* func4(void * i_p)
        {
            barrier_t * barrier = (barrier_t *) i_p;
            barrier_wait(barrier);
            TS_TRACE("B2");
            return NULL;
        }

        static void* watch_counter(void * i_p)
        {
            TASK_INFO * info = (TASK_INFO *) i_p;
            SyncTest * my = info->testobj;
            TS_TRACE("CONDVAR task %ld. Start watching counter",info->id);
            mutex_lock(&(my->mutex));
            while(my->counter < COUNT_SIGNAL)
            {
                sync_cond_wait(&(my->cond_var),&(my->mutex));
                TS_TRACE("CONDVAR task %ld. Condition signal received",
                         info->id);
                my->counter += 100;
                TS_TRACE("CONDVAR task %ld. Counter = %ld",
                         info->id,my->counter);
            }
            mutex_unlock(&(my->mutex));
            barrier_wait(&(my->barrier));
            return NULL;
        }


        static void* increment(void * i_p)
        {
            TASK_INFO * info = (TASK_INFO *) i_p;
            SyncTest * my = info->testobj;
            TS_TRACE("CONDVAR task %ld. start Increment counter",info->id);
            for(size_t i = 0; i < TO_COUNT; ++i)
            {
                mutex_lock(&(my->mutex));
                ++(my->counter);

                if(my->counter == COUNT_SIGNAL)
                {
                    sync_cond_signal(&(my->cond_var));
                    TS_TRACE("CONDVAR task %ld. INCR counter = %ld Threshold"
                             " reached",info->id,my->counter);
                }
                TS_TRACE("CONDVAR task %ld INCR counter = %ld Unlocking mutex",
                         info->id, my->counter);
                mutex_unlock(&(my->mutex));
                nanosleep(0,TEN_CTX_SWITCHES_NS);
            }
            barrier_wait(&(my->barrier));
            return NULL;
        }

        static void* increment1(void * i_p)
        {
            TASK_INFO * info = (TASK_INFO *) i_p;
            SyncTest * my = info->testobj;
            TS_TRACE("CONDVAR task %ld. start Increment counter",info->id);
            for(size_t i = 0; i < TO_COUNT; ++i)
            {
                mutex_lock(&(my->mutex));
                ++(my->counter);

                if(my->counter == COUNT_SIGNAL)
                {
                    sync_cond_broadcast(&(my->cond_var));
                    TS_TRACE("CONDVAR task %ld. INCR counter = %ld Threshold"
                             " reached",info->id,my->counter);
                }
                TS_TRACE("CONDVAR task %ld INCR counter = %ld Unlocking mutex",
                         info->id, my->counter);
                mutex_unlock(&(my->mutex));
                nanosleep(0,TEN_CTX_SWITCHES_NS);
            }
            barrier_wait(&(my->barrier));
            return NULL;
        }

};
#endif

