/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/kernel/memorymgr.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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
#ifndef __MEMORY_MGR_TEST_H
#define __MEMORY_MGR_TEST_H

#include <cxxtest/TestSuite.H>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <sys/task.h>
#include <tuple>
#include <string.h>
#include <util/singleton.H>
#include <kernel/pagemgr.H>
#include <kernel/heapmgr.H>
#include <kernel/simpletrace.H>
#include <sys/misc.h>

using namespace std;

/**
 *  @brief Run Memory Manager tests
 *         This code exercises PageManager, HeapManager and classes they depend upon.
 *
 *         Single thread testcases
 *          QueueTest
 *          PQueueTest
 *
 *         Multiple thread testcases
 *          ThreadSafeStackTest
 *          ThreadSafePageMgrTest
 *          ThreadSafeSmallHeapTest
 *          ThreadSafeSmallBigHugeTest
 *
 *           The method run_multi_threads() is used to start many threads for each class.
 *           Each of the ThreadSafe classes has a method run_thread(), which is called by
 *           run_multi_threads(). The method run_thread() does the exercising for each
 *           thread.
 */
class MemoryMgrTest : public CxxTest::TestSuite
{
    static inline bool thd_err{false}; // indicates a thread hit an error and
                                       // all threads should exit
    /**
     *  @brief Run tests for class Queue
     */
    class QueueTest
    {
      public:
        void run()
        {
        }
    };

    /**
     *  @brief Run tests for class PQueue
     */
    class PQueueTest
    {
      public:
        void run()
        {
        }
    };

    /**
     *  @brief Run tests exercising the atomic AbaPtr class Stack
     *         This is a good path consistency stress test.
     *         If there are no errors, we can feel confident that
     *         src/include/util/lockfree/stack.H runs well in a
     *         multi-thread stress environment.
     *
     *         NUM_PAGES must accomodate a max of 32 threads
     *                   32 * NUM_CHUNKS * sizeof(chunk_test_t) / 4096
     *         Each thread uses NUM_CHUNKS structs of chunk_test_t.
     *         These come from test_chunks, which are alloc'd in the ctor.
     *         Each thread is passed an id (0..31), and thereby knows which
     *          chunk_test_t structs in test_chunks it may use.
     *          ie, id 0 uses test_chunks[0]   to test_chunks[99]
     *              id 1 uses test_chunks[100] to test_chunks[199]
     *              id 2 uses test_chunks[200] to test_chunks[299]
     *              etc
     *         NUM_LOOPS specifies how long this test runs
     */
    class ThreadSafeStackTest
    {
      public:
        static constexpr uint64_t FREE       = 0xFFEE; // mark struct as FREE
        static constexpr uint64_t ALLOC      = 0xAACC; // mark struct as ALLOC
        static constexpr size_t   NUM_PAGES  = 15;     // 4k pages to allocate for
                                                       //  a max of 32 threads
        static constexpr size_t   NUM_CHUNKS = 100;    // structs per thread
        static constexpr int      NUM_LOOPS  = 50000;  // loops per thread

        struct chunk_test_t  // struct used to push/pop onto the freeQ
        {
            uint64_t      free;
            chunk_test_t *next;
        };
        static inline Util::Lockfree::Stack<chunk_test_t> freeQ{};
        static inline chunk_test_t                       *test_chunks{nullptr};

        /**
         *  @brief Allocate the memory for the chunk_test_t elements this test
         *         will push/pop using freeQ
         */
        ThreadSafeStackTest()
        {
            test_chunks = (chunk_test_t*)PageManager::allocatePage(NUM_PAGES);
        }

        /**
         *  @brief Free the space used for the chunk_test_t elements
         */
        ~ThreadSafeStackTest()
        {
            assert(nullptr != test_chunks);
            PageManager::freePage(test_chunks, NUM_PAGES);
        }

        /**
         *  @brief Each thread loops calling push and pop to the Stack
         */
        static void* run_thread(void *p)
        {
            vector<chunk_test_t*> list;
            chunk_test_t          *chunk = nullptr;
            int                    id    = (int)(0x00000000ffffffff & (uintptr_t)p);
            tid_t                  tid   = task_gettid();
            int                    first = id*NUM_CHUNKS;
            int                    last  = id*NUM_CHUNKS + NUM_CHUNKS;

            TS_INFO("MemoryMgrTest::ThreadSafeStackTest: START %d", tid);

            // init - set chunks to FREE and push onto freeQ
            for (int i=first; i<last; i++)
            {
                test_chunks[i].free = FREE;
                freeQ.push(test_chunks+i);
            }

            // main work loop for each thread
            for (int loops=0; loops<NUM_LOOPS && !thd_err; loops++)
            {
                // allocate - pop chunks from freeQ, check FREE, set ALLOC
                for (size_t i=0; i<NUM_CHUNKS; i++)
                {
                    chunk = freeQ.pop();
                    if (chunk)
                    {
                        assert(chunk->free == FREE);
                        chunk->free = ALLOC;
                        list.push_back(chunk);
                        chunk->next = nullptr;  // access the memory
                    }
                    else
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeStackTest: pop  %d NULL", tid);
                        thd_err = true;
                        return NULL;
                    }
                }
                // free - check ALLOC, set FREE, push chunk onto freeQ
                for (auto c : list)
                {
                    if (!c)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeStackTest: push %d NULL", tid);
                        thd_err = true;
                        return NULL;
                    }
                    assert(c->free == ALLOC);
                    c->free = FREE;
                    freeQ.push(c);
                    list.pop_back();
                }
            }

            return NULL;
        }
    };

    /**
     *  @brief Run tests exercising class PageManager
     *         This is a good path consistency stress test.
     *         If there are no errors, we can feel confident that
     *         src/kernel/pagemgr.C runs well in a multi-thread stress environment.
     *
     *         Each loop:  allocate N pages, and write a byte to each page
     *                     free half of the alloc'd pages,
     *                     run a coalesce, which is more difficult because all pages
     *                       are not free
     *                     free N pages
     *                     run a coalesce, which is easier now that all pages are free
     *                     validate that all pages were freed
     *
     *  NUM_LOOPS   - specifies how long this test runs
     *  alloc_pages - This affects how much memory is used per thread in the test.
     *                If we specify too much, then it runs out of memory and asserts.
     *  alloc_max   - Max size of each allocatePage in a loop
     *                If we specify too much, then it runs out of memory and asserts.
     */
    class ThreadSafePageMgrTest
    {
      public:
        static constexpr int NUM_LOOPS  = 1000;  // loops per thread

        /**
         *  @brief Each thread loops calling allocatePage, freePage, and coalesce
         *
         */
        static void* run_thread(void *p)
        {
            size_t alloc_pages = 100; // pages for each thread to allocate per loop
            size_t alloc_max   = 16;  // max pages per allocatePage
            size_t pages       = 0;   // sum of pages currently allocated in each loop
            size_t alloc_size  = 0;   // calculate a size for each allocate
            size_t free_num    = 0;   // use to free half of the pages
            tid_t  tid         = task_gettid();
            vector<pair<uint8_t*,int>> freeme;  // save the alloc'd memory addrs to free
            vector<pair<uint8_t*,int>>::iterator itr;

            TS_INFO("MemoryMgrTest::ThreadSafePageMgrTest: START %d", tid);

            uint8_t *memory{0}; // used to write to a page allocated

            // main work loop for each thread
            for (int i=0; i<NUM_LOOPS && !thd_err; i++)
            {
                while (pages < alloc_pages)  // do the allocates
                {
                    // bump alloc_size, and roll back to 1 at max
                    alloc_size = ++alloc_size==alloc_max ? 1 : alloc_size;

                    memory = (uint8_t*)PageManager::allocatePage(alloc_size);
                    if (!memory)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafePageMgrTest: %d "
                                "sz:%ld pages_alloc:%ld",
                                tid, alloc_size, freeme.size());
                        thd_err = true;
                        return NULL;
                    }
                    *memory = 0xab;   // write the memory to force it into cache memory
                    pages += alloc_size;
                    freeme.push_back(make_pair(memory,alloc_size));
                }

                free_num = freeme.size()/2;
                while (free_num--)    // free half of the allocated pages
                {
                    itr = freeme.begin();
                    assert(nullptr != itr->first);
                    assert(0       != itr->second);
                    PageManager::freePage(itr->first, itr->second);
                    pages -= itr->second;
                    freeme.erase(itr);
                }

                // do a coalesce with only half of the pages free
                PageManager::coalesce();

                // free the rest of the allocated pages
                for (itr=freeme.begin(); itr!=freeme.end();)
                {
                    assert(nullptr != itr->first);
                    assert(0       != itr->second);
                    PageManager::freePage(itr->first, itr->second);
                    pages -= itr->second;
                    itr = freeme.erase(itr);
                }

                // do a coalesce with all of the pages free
                PageManager::coalesce();

                if (pages) // ensure all pages have been freed
                {
                    TS_FAIL("MemoryMgrTest::ThreadSafePageMgrTest: pages not 0");
                    thd_err = true;
                    return NULL;
                }
            }

            return NULL;
        }
    };

    /**
     *  @brief Run tests exercising class HeapManager using only small heap sizes
     *         This is a good path consistency stress test.
     *         If there are no errors, we can feel confident that the small heap in
     *         src/kernel/heapmgr.C runs well in a multi-thread stress environment.
     *
     *         Each loop:  malloc N bytes, and write a byte to each page
     *                     free half of the memory allocated,
     *                     run a coalesce, which is more difficult because all memory
     *                       allocated is not free
     *                     free all memory
     *                     run a coalesce, which is easier now that all memory is free
     *                     validate that all memory was freed
     *
     *   NUM_LOOPS   - specifies how long this test runs
     *   alloc_bytes - This affects how much memory is used during the test.
     *                 If we specify too much, then it runs out of memory and asserts.
     *   alloc_max   - Max size of each malloc for an iteration of the loop
     *                 If we specify too much, then it runs out of memory and asserts.
     */
    class ThreadSafeSmallHeapTest
    {
      public:
        static constexpr int NUM_LOOPS = 5000;  // loops per thread

        /**
         *  @brief Each thread loops calling new, delete, and PageManager::coalesce
         */
        static void* run_thread(void *p)
        {
            size_t alloc_bytes = 1000; // bytes to allocate per loop
            size_t alloc_max   = 100;  // max size for each allocate
            size_t bytes       = 0;    // sum of total bytes allocate each loop
            size_t alloc_size  = 0;    // random size for each call to new
            size_t free_num    = 0;    // used to free half of allocates
            tid_t  tid         = task_gettid();
            vector<pair<uint8_t*,int>> freeme; // allocated memory addrs to free
            vector<pair<uint8_t*,int>>::iterator itr;

            TS_INFO("MemoryMgrTest::ThreadSafeSmallHeapTest: START %d", tid);

            uint8_t *memory{nullptr};

            // main work loop for each thread
            for (int i=0; i<NUM_LOOPS && !thd_err; i++)
            {
                while (bytes < alloc_bytes)  // do the allocates
                {
                    alloc_size = (getTB() % alloc_max) + 1;
                    memory = new uint8_t[alloc_size];
                    if (!memory)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeSmallHeapTest"
                                "allocate failed allocs:%ld", freeme.size());
                        thd_err = true;
                        return NULL;
                    }
                    *memory = 0xab; // access the memory
                    bytes += alloc_size;
                    freeme.push_back(make_pair(memory,alloc_size));
                }

                // free half of the allocates
                free_num = freeme.size()/2;
                while (free_num--)
                {
                    itr = freeme.begin();
                    assert(nullptr != itr->first);
                    delete [] itr->first;
                    bytes -= itr->second;
                    freeme.erase(itr);
                }

                // do coalesce with only half of the allocates freed
                PageManager::coalesce();

                // free the rest of the allocates
                for (itr=freeme.begin(); itr!=freeme.end();)
                {
                    assert(nullptr != itr->first);
                    delete [] itr->first;
                    bytes -= itr->second;
                    itr = freeme.erase(itr);
                }

                // do coalesces with all of the allocates freed
                PageManager::coalesce();

                // ensure all bytes allocated were freed
                if (bytes)
                {
                    TS_FAIL("MemoryMgrTest::ThreadSafeSmallHeapTest: bytes not 0");
                    thd_err = true;
                    return NULL;
                }
            }

            return NULL;
        }
    };

    /**
     *  @brief Run tests exercising class HeapManager using small, big, and huge sizes
     *         This is a good path consistency stress test.
     *         If there are no errors, we can feel confident that the small, big,
     *          and huge heaps in src/kernel/heapmgr.C runs well in a multi-thread
     *          stress environment.
     *
     *         Each loop:  malloc N bytes from the Small heap, and write a byte
     *                     realloc N+32 bytes from the small heap and write a byte
     *                     free all memory
     *                     validate that all memory was freed
     *                     malloc alloc_bytes_big from the Big heap, and write a byte
     *                     realloc 2*alloc_bytes_big from the small heap and write a byte
     *                     free all memory
     *                     validate that all memory was freed
     *                     malloc alloc_bytes_big from the Huge heap, and write a byte
     *                     realloc 2*alloc_bytes_huge from the small heap and write a byte
     *                     free all memory
     *                     validate that all memory was freed
     *                     run a PageManager coalesce
     *
     *   NUM_LOOPS        - specifies how long this test runs
     *   alloc_bytes      - This affects how much small heap memory is used during the test.
     *   alloc_bytes_big  - This affects how much big heap memory is used during the test.
     *   alloc_bytes_huge - This affects how much huge heap memory is used during the test.
     *       *If we specify too much memory for small/big/huge,
     *        then the test runs out of memory and asserts.
     *   alloc_max        - Used to limit the size of a malloc
     *                      If we specify too much, then it runs out of memory and asserts.
     */
    class ThreadSafeSmallBigHugeTest
    {
      public:
        static constexpr int NUM_LOOPS = 700;  // loops per thread

        /**
         *  @brief Each thread loops calling new, realloc, delete for small, big,
         *         and huge sizes
         */
        static void* run_thread(void *p)
        {
            size_t alloc_bytes      = 1000;
            size_t alloc_bytes_big  = HeapManager::MAX_SMALL_ALLOC_SIZE * 20;
            size_t alloc_bytes_huge = HeapManager::MAX_BIG_ALLOC_SIZE   * 3;
            size_t alloc_small_max  = 100;
            size_t alloc_larger_max = 10000;
            size_t realloc_bump     = 0;
            size_t bytes            = 0;
            size_t alloc_size       = 0;
            tid_t  tid              = task_gettid();
            vector<pair<uint8_t*,int>> freeme;
            vector<pair<uint8_t*,int>> realloc;
            vector<pair<uint8_t*,int>>::iterator itr;

            TS_INFO("MemoryMgrTest::ThreadSafeSmallBigHugeTest: START %d", tid);

            uint8_t *memory{nullptr};
            uint8_t *realloc_memory{nullptr};

            // main work loop for each thread
            for (int i=0; i<NUM_LOOPS && !thd_err; i++)
            {
                while (bytes < alloc_bytes)            // SMALL allocate
                {
                    alloc_size = (getTB() % alloc_small_max) + 1;
                    memory = new uint8_t[alloc_size];
                    if (!memory)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest "
                                "allocate failed allocs:%ld", freeme.size());
                        thd_err = true;
                        return NULL;
                    }
                    *memory = 0xab; // access the memory
                    bytes += alloc_size;
                    realloc.push_back(make_pair(memory,alloc_size));
                }
                for (itr=realloc.begin(); itr!=realloc.end();) // SMALL realloc
                {
                    realloc_bump = getTB() % alloc_small_max;
                    bytes += realloc_bump;
                    alloc_size = itr->second + realloc_bump;
                    realloc_memory = (uint8_t*)HeapManager::realloc(itr->first, alloc_size);
                    itr = realloc.erase(itr);
                    if (!realloc_memory)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest"
                                "realloc failed allocs:%ld", freeme.size());
                        thd_err = true;
                        return NULL;
                    }
                    *realloc_memory = 0xab; // access the memory
                    freeme.push_back(make_pair(realloc_memory, alloc_size));
                }
                for (itr=freeme.begin(); itr!=freeme.end();)    // SMALL free
                {
                    assert(nullptr != itr->first);
                    delete [] itr->first;
                    bytes -= itr->second;
                    itr = freeme.erase(itr);
                }
                if (bytes) // ensure all bytes allocated are now free
                {
                    TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest"
                            "allocate bytes not 0");
                    thd_err = true;
                    return NULL;
                }

                while (bytes < alloc_bytes_big)        // BIG allocate
                {
                    alloc_size = HeapManager::MAX_SMALL_ALLOC_SIZE + 1 +
                                 (getTB() % alloc_small_max);
                    memory = new uint8_t[alloc_size];
                    if (!memory)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest"
                                "allocateBig failed allocs:%ld", freeme.size());
                        thd_err = true;
                        return NULL;
                    }
                    *memory = 0xab; // access the memory
                    bytes += alloc_size;
                    realloc.push_back(make_pair(memory,alloc_size));
                }
                for (itr=realloc.begin(); itr!=realloc.end();)  // BIG realloc
                {
                    realloc_bump = HeapManager::MAX_SMALL_ALLOC_SIZE +
                                   (getTB() % alloc_larger_max);
                    bytes += realloc_bump;
                    alloc_size = itr->second + realloc_bump;
                    realloc_memory = (uint8_t*)HeapManager::realloc(itr->first, alloc_size);
                    if (!realloc_memory)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest"
                                "reallocBIG failed allocs:%ld", freeme.size());
                        thd_err = true;
                        return NULL;
                    }
                    itr = realloc.erase(itr);
                    *realloc_memory = 0xab; // access the memory
                    freeme.push_back(make_pair(realloc_memory, alloc_size));
                }
                for (itr=freeme.begin(); itr!=freeme.end();)   // BIG free
                {
                    assert(nullptr != itr->first);
                    delete [] itr->first;
                    bytes -= itr->second;
                    itr = freeme.erase(itr);
                }
                if (bytes)   // ensure all bytes allocated are now free
                {
                    TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest"
                            "allocateBig bytes not 0");
                    thd_err = true;
                    return NULL;
                }

                while (bytes < alloc_bytes_huge)        // HUGE allocate
                {
                    alloc_size = HeapManager::MAX_BIG_ALLOC_SIZE + 1 +
                                 (getTB() % alloc_small_max);
                    memory = new uint8_t[alloc_size];
                    if (!memory)
                    {
                        // mm ops can fail, so just retry
                        continue;
                    }
                    *memory = 0xab; // access the memory
                    bytes += alloc_size;
                    realloc.push_back(make_pair(memory,alloc_size));
                }
                for (itr=realloc.begin(); itr!=realloc.end();)  // HUGE realloc
                {
                    realloc_bump   = HeapManager::MAX_SMALL_ALLOC_SIZE +
                                     (getTB() % alloc_larger_max);
                    alloc_size     = itr->second + realloc_bump;
                    realloc_memory = (uint8_t*)HeapManager::realloc(itr->first, alloc_size);
                    if (!realloc_memory)
                    {
                        TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest "
                                "reallocHUGE failed %p allocs:%ld", itr->first, freeme.size());
                        delete [] itr->first;
                        continue;
                    }
                    bytes += realloc_bump;
                    itr = realloc.erase(itr);
                    *realloc_memory = 0xab; // access the memory
                    freeme.push_back(make_pair(realloc_memory, alloc_size));
                }
                for (itr=freeme.begin(); itr!=freeme.end();)    // HUGE free
                {
                    assert(nullptr != itr->first);
                    delete [] itr->first;
                    bytes -= itr->second;
                    itr = freeme.erase(itr);
                }
                if (bytes)  // ensure all bytes allocated are now free
                {
                    TS_FAIL("MemoryMgrTest::ThreadSafeSmallBigHugeTest "
                            "allocateHuge bytes not 0");
                    thd_err = true;
                    return NULL;
                }
                PageManager::coalesce();
            }

            return NULL;
        }
    };

    static inline bool RUN_THREAD_LOWER_BUCKETS{true};

    /**
     *  @brief Run a background thread exercising class PageManager
     *         Each thread loops calling allocatePage and freePage for
     *         only sizes 1 and 2, to exercise the lockless lower buckets
     */
    static void* run_thread_lower_buckets(void *p)
    {
        size_t pages       = 0;
        size_t alloc_size  = 1;
        tid_t  tid         = task_gettid();
        vector<pair<uint8_t*,int>> freeme;
        vector<pair<uint8_t*,int>>::iterator itr;

        TS_INFO("MemoryMgrTest:run_thread_lower_buckets: START %d", tid);

        uint8_t *memory{nullptr};

        while (RUN_THREAD_LOWER_BUCKETS && !thd_err)
        {
            for (int i=0; i<100; i++)    // allocate pages
            {
                alloc_size = alloc_size==1 ? 2 : 1; // alternate between 1 and 2
                memory = (uint8_t*)PageManager::allocatePage(alloc_size);
                if (!memory)
                {
                    TS_FAIL("MemoryMgrTest::run_thread_lower_buckets: %d "
                            "sz:%ld pages_alloc:%ld",
                            tid, alloc_size, freeme.size());
                    thd_err = true;
                    return NULL;
                }
                *memory = 0xab; // access the memory
                pages += alloc_size;
                freeme.push_back(make_pair(memory,alloc_size));
            }
            for (itr=freeme.begin(); itr!=freeme.end();)  // free pages
            {
                assert(nullptr != itr->first);
                PageManager::freePage(itr->first, itr->second);
                pages -= itr->second;
                itr = freeme.erase(itr);
            }
            if (pages)  // ensure all pages are now free
            {
                TS_FAIL("MemoryMgrTest::run_thread_lower_buckets: %d : pages not 0", tid);
                thd_err = true;
                return NULL;
            }
        }

        TS_INFO("MemoryMgrTest:run_thread_lower_buckets: EXIT  %d", tid);

        return NULL;
    }

    /**
     *  @brief Trace the SUCCESS or FAIL of each thread when it exits
     */
    void check_status(tid_t tid,
                      tid_t ret_tid,
                      int   thd_rc)
    {
        if (ret_tid == tid && thd_rc == TASK_STATUS_EXITED_CLEAN)
        {
            TS_INFO("MemoryMgrTest: %d EXIT: SUCCESS",tid);
        }
        else
        {
            thd_err = true;
            TS_FAIL("MemoryMgrTest: EXIT: FAIL tid:%d ret_tid:%d thd_rc:%d thd_err:%d",
                    tid, ret_tid, thd_rc, thd_err);
        }
    }

    /**
     *  @brief Start N threads that run the fcn passed in
     */
    void run_multi_threads(uint64_t thdN, void* (*fcn)(void*))
    {
        std::list<tid_t>  tlist;  // list of the running threads
        int               thd_rc{0};

        thd_err = false;

        // start the threads
        for (uint64_t i=0; i<thdN; i++)
        {
            tid_t tid = task_create(fcn, (void*)i);
            tlist.push_back(tid);
        }

        // wait for the threads to complete
        while (!tlist.empty())
        {
            tid_t tid = tlist.front();
            tid_t ret_tid;
            tlist.pop_front();

            ret_tid = task_wait_tid(tid, &thd_rc, nullptr);
            check_status(tid, ret_tid, thd_rc);
        }
    }

  public:
    static constexpr int NUM_THREADS = 5;  // number of threads run in the ThreadSafe
                                           // tests below
    /**
     *  @brief Run the tests for the Kernel Memory Manager
     */
    void test_MemoryMgr()
    {
        STRC_KSHORT_SET_LEVEL(STRC_L1); // ensure the KSHORT trace is enabled

        TS_INFO("MemoryMgrTest::QueueTest: BEGIN");
        QueueTest qt;
        qt.run();
        TS_INFO("MemoryMgrTest::QueueTest: END");

        TS_INFO("MemoryMgrTest::PQueueTest: BEGIN");
        PQueueTest pqt;
        pqt.run();
        TS_INFO("MemoryMgrTest::PQueueTest: END");

        TS_INFO("MemoryMgrTest::ThreadSafeStackTest: BEGIN");
        ThreadSafeStackTest tsStack;
        run_multi_threads(NUM_THREADS, tsStack.run_thread);
        TS_INFO("MemoryMgrTest::ThreadSafeStackTest: END");

        // start a background thread to exercise the PageManager lower buckets
        RUN_THREAD_LOWER_BUCKETS = true;
        tid_t tid = task_create(run_thread_lower_buckets, NULL);

        TS_INFO("MemoryMgrTest::ThreadSafePageMgrTest: BEGIN");
        ThreadSafePageMgrTest tsPageMgr;
        run_multi_threads(NUM_THREADS, tsPageMgr.run_thread);
        TS_INFO("MemoryMgrTest::ThreadSafePageMgrTest: END");

        TS_INFO("MemoryMgrTest::ThreadSafeSmallHeapTest: BEGIN");
        ThreadSafeSmallHeapTest tsSmallHeap;
        run_multi_threads(NUM_THREADS, tsSmallHeap.run_thread);
        TS_INFO("MemoryMgrTest::ThreadSafeSmallHeapTest: END");

        TS_INFO("MemoryMgrTest::ThreadSafeSmallBigHugeTest: BEGIN");
        ThreadSafeSmallBigHugeTest tsSmallBigHuge;
        run_multi_threads(NUM_THREADS, tsSmallBigHuge.run_thread);
        TS_INFO("MemoryMgrTest::ThreadSafeSmallBigHugeTest: END");

        // stop the background lower buckets thread
        RUN_THREAD_LOWER_BUCKETS = false;
        int thd_rc{0};
        tid_t ret_tid = task_wait_tid(tid, &thd_rc, nullptr);
        check_status(tid, ret_tid, thd_rc);

        TS_INFO("MemoryMgrTest: EXIT");
        return;
    }
};
#endif
