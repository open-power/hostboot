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
            nanosleep(1,0);
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

