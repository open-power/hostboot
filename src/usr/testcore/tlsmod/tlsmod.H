/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/tlsmod/tlsmod.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

#ifndef __TLSMOD_TLSMOD_H
#define __TLSMOD_TLSMOD_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>
#include "nontrivialctor.H"

namespace __tls_test
{

// @note: See src/usr/testcore/lib/tls.H for API definition
void spawnTasks(
    const char* const i_pFnName,
          void*(*i_pFn)(void*));

extern const size_t FOOBAR_INIT_VALUE;
extern const size_t FOOBAR_POST_VALUE;

extern thread_local size_t foobar;

extern thread_local NonTrivialCtor foobar_object;

size_t foobarInitValue();

size_t foobarPostValue();

void test_tls_call_other_module_producer();

void test_tls_call_other_module_consumer();

/***
 *  @brief Test to consume a TLS var from a different library
 */
void* test_tls_module_cons(void* unused)
{
    TS_INFO(ENTER_MRK "test_tls_module_cons");

    do {

    decltype(foobar) rc = foobar;
    if(rc != foobarInitValue())
    {
        TS_FAIL("test_tls_module_cons: bad initial value; "
                "expected 0x%016llX but got 0x%016llX",
                foobarInitValue(),rc);
        break;
    }

    task_yield();

    foobar++;

    task_yield();

    rc = foobar;
    if(rc != foobarPostValue())
    {
        TS_FAIL("test_tls_module_cons: bad post value; "
                "expected 0x%016llX but got 0x%016llX",
                foobarPostValue(),rc);
        break;
    }

    } while(0);

    TS_INFO(EXIT_MRK "test_tls_module_cons");

    return nullptr;
}

/***
 *  @brief Test to consume a TLS var from same library
 */
void* test_tls_module_prod(void* unused)
{
    TS_INFO(ENTER_MRK "test_tls_module_prod");

    do {

    char* const thebytes = foobar_object.c_str();

    if(strcmp(thebytes,NonTrivialCtor::INIT_VALUE)!=0)
    {
        TS_FAIL("test_tls_module_prod: bad initial value; "
                "expected %s but got %s", foobar_object.INIT_VALUE, thebytes);
        break;
    }

    task_yield();

    thebytes[0]++;

    task_yield();

    if(strcmp(thebytes,NonTrivialCtor::POST_VALUE)!=0)
    {
        TS_FAIL("test_tls_module_prod: bad post value; "
                "expected %s but got %s", foobar_object.POST_VALUE, thebytes);
        break;
    }

    } while(0);

    TS_INFO(EXIT_MRK "test_tls_module_prod");

    return nullptr;
}

}; // End __tls_test namespace

// Test TLS between modules
class LibcTlsTestMod : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test TLS var where local library accesses a var in another
     *      library, then call into that other library where it will access
     *      that same var locally.
     */
    void testTlsConsumerFirst()
    {
        TS_INFO(ENTER_MRK "testTlsConsumerFirst");
        __tls_test::spawnTasks("testTlsConsumerFirst",
                               __tls_test::test_tls_module_cons);
        TS_INFO(EXIT_MRK "testTlsConsumerFirst");

        __tls_test::test_tls_call_other_module_producer();
    }

    /**
     *  @brief Test TLS var where the var is accessed from the local library,
     *      then call into a different library and have it access the same var
     *      from this library.
     */
    void testTlsProducerFirst()
    {
        TS_INFO(ENTER_MRK "testTlsProducerFirst");
        __tls_test::spawnTasks("testTlsProducerFirst",
                               __tls_test::test_tls_module_prod);
        TS_INFO(EXIT_MRK "testTlsProducerFirst");

        __tls_test::test_tls_call_other_module_consumer();
    }
};

#endif // End __TLSMOD_TLSMOD_H
