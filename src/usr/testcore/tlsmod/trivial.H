/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/tlsmod/trivial.H $                           */
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

#ifndef __TLSMOD_TRIVIAL_H
#define __TLSMOD_TRIVIAL_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>
#include "trivialctor.H"
#include <string.h>

namespace __tls_test
{
    extern thread_local TrivialCtor tls_trivial;

    /**
     *  @brief Test a thread local trivial constructor
     */
    void* test_tls_trivial(void* unused)
    {
        TS_INFO(ENTER_MRK "test_tls_trivial");

        do {

        size_t value = tls_trivial.getValue();

        if(TrivialCtor::TRIVIAL_CTOR_INIT_VALUE != value)
        {
            TS_FAIL("test_tls_trivial: bad initial value; "
                    "expected 0x%016llX but got 0x%016llX",
                    TrivialCtor::TRIVIAL_CTOR_INIT_VALUE,value);
            break;
        }

        task_yield();

        tls_trivial.setValue(++value);
        value = 0;

        task_yield();

        value = tls_trivial.getValue();

        if(TrivialCtor::TRIVIAL_CTOR_POST_VALUE != value)
        {
            TS_FAIL("test_tls_trivial: bad post value; "
                    "expected 0x%016llX but got 0x%016llX",
                    TrivialCtor::TRIVIAL_CTOR_POST_VALUE,value);
            break;
        }

        } while(0);

        TS_INFO(EXIT_MRK "test_tls_trivial");

        return nullptr;
    }
};

// Test TLS for trivial constructors
class LibcTlsTestTrivial : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test TLS trivial constructors
     */
    void testTlsTrivial()
    {
        TS_INFO(ENTER_MRK "testTlsTrivial");
        __tls_test::spawnTasks("testTlsTrivial",__tls_test::test_tls_trivial);
        TS_INFO(EXIT_MRK "testTlsTrivial");
    }
};
#endif
