/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/tls.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __LIB_TLS_H
#define __LIB_TLS_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>

#include "../tlsmod/nontrivialctor.H"

namespace __tls_test
{
    const size_t THREADS_PER_TEST = 15;
    constexpr size_t FOOBAR_INIT_VALUE = 0x4321dcba;
    constexpr size_t FOOBAR_POST_VALUE = 0x4321dcbb;

    thread_local size_t foobar = FOOBAR_INIT_VALUE;

    extern thread_local NonTrivialCtor foobar_object;

    /**
     *  @brief Spawns a set of tasks and waits on them
     *
     *  @param[in] i_pFnName Name of the function doing the spawning, for
     *      tracing
     *  @param[in] i_pFn Function pointer suitable for passing to a task_create
     *      call
     */
    void spawnTasks(
        const char* const i_pFnName,
                   void*(*i_pFn)(void*))
    {
        std::vector<tid_t> tids;
        for(size_t thread=0;thread<THREADS_PER_TEST;++thread)
        {
            const auto tid = task_create(i_pFn, nullptr);
            TS_INFO("%s: created TID %d",i_pFnName,tid);
            tids.push_back(tid);
        }

        for(const auto tid : tids)
        {
            int status = 0;
            const auto tidWaitedOn = task_wait_tid(tid,&status,nullptr);
            if(tidWaitedOn != tid)
            {
                TS_FAIL("%s: Failed to wait on TID %d; got return "
                    "value of %d",i_pFnName,tid,tidWaitedOn);
            }
            else if(status != TASK_STATUS_EXITED_CLEAN)
            {
                TS_FAIL("%s: TID %d exited with bad status of %d",
                    i_pFnName,tid,status);
            }
            else
            {
                TS_INFO("%s: Waited on TID %d",i_pFnName,tid);
            }

            // Wait on all threads, despite any errors.
        }
    }

    /**
     *  @brief Tests that a simple thread local variable in this translation
     *      unit has the right initial value and right post increment value
     */
    void* test_tls(void* unused)
    {
        TS_INFO(ENTER_MRK "test_tls");

        do {

        decltype(foobar) rc = foobar;
        if(rc != FOOBAR_INIT_VALUE)
        {
            TS_FAIL("test_tls: bad initial value; "
                    "expected 0x%016llX but got 0x%016llX",
                    FOOBAR_INIT_VALUE,rc);
            break;
        }

        task_yield();

        foobar++;

        task_yield();

        rc = foobar;
        if(rc != FOOBAR_POST_VALUE)
        {
            TS_FAIL("test_tls: bad post value; "
                    "expected 0x%016llX but got 0x%016llX",
                    FOOBAR_POST_VALUE,rc);
            break;
        }

        } while(0);

        TS_INFO(EXIT_MRK "test_tls");

        return nullptr;
    }

    /**
     *  @brief Tests that a complex object from another shared library
     *      has the right initial value and right post increment value
     */
    void* test_from_other_module(void* unused)
    {
        TS_INFO(ENTER_MRK "test_from_other_module");

        do {

        char* const thebytes = foobar_object.c_str();

        if(strcmp(thebytes,foobar_object.INIT_VALUE)!=0)
        {
            TS_FAIL("test_from_other_module: bad initial value; "
                "expected %s but got %s", foobar_object.INIT_VALUE, thebytes);
            break;
        }

        task_yield();

        thebytes[0]++;

        task_yield();

        if(strcmp(thebytes,foobar_object.POST_VALUE)!=0)
        {
            TS_FAIL("test_from_other_module: bad post value; "
                "expected %s but got %s", foobar_object.POST_VALUE, thebytes);
            break;
        }

        } while (0);

        TS_INFO(EXIT_MRK "test_from_other_module");

        return nullptr;
    }

    /**
     *  @brief Support a remote shared library invoking a test whereby this
     *      shared library acts as the producer for the foobar variable
     */
    void test_tls_call_other_module_producer()
    {
        TS_INFO(ENTER_MRK "test_tls_call_other_module_producer");
        spawnTasks("test_tls_call_other_module_producer",
                   __tls_test::test_tls);
        TS_INFO(EXIT_MRK "test_tls_call_other_module_producer");
    }

    /**
     *  @brief Support a remote shared library invoking a test whereby this
     *      shared library acts as the consumer for the invoking library's
     *      variable
     */
    void test_tls_call_other_module_consumer()
    {
        TS_INFO(ENTER_MRK "test_tls_call_other_module_consumer");
        spawnTasks("test_tls_call_other_module_consumer",
                   __tls_test::test_from_other_module);
        TS_INFO(EXIT_MRK "test_tls_call_other_module_consumer");
    }

    /**
     *  @brief Return the init value for foobar
     *
     *  @return size_t Foobar's expected init value
     */
    size_t foobarInitValue()
    {
        return FOOBAR_INIT_VALUE;
    }

    /**
     *  @brief Return the post value for foobar
     *
     *  @return size_t Foobar's expected post value
     */
    size_t foobarPostValue()
    {
        return FOOBAR_POST_VALUE;
    }

}; // End __tls_test namespace

// Test TLS within a translation unit
class LibcTlsTest : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Simple test of a locally defined TLS variable
     */
    void testTls()
    {
        TS_INFO(ENTER_MRK "testTls");
        __tls_test::spawnTasks("testTls",__tls_test::test_tls);
        TS_INFO(EXIT_MRK "testTls");
    }
};
#endif
