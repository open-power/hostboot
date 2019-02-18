/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/tlsmod/nontrivial.H $                        */
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

#ifndef __TLSMOD_NONTRIVIAL_H
#define __TLSMOD_NONTRIVIAL_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>
#include "nontrivialctor.H"
#include <string.h>

namespace __tls_test
{

    // @note: See src/usr/testcore/lib/tls.H for API definition
    void spawnTasks(
        const char* const i_pFnName,
              void*(*i_pFn)(void*));

    extern thread_local NonTrivialCtor tls_nontrivial;

    /**
     *  @brief Test which validates a non-trivial TLS variable
     */
    void* test_tls_nontrivial(void* unused)
    {
        TS_INFO(ENTER_MRK "test_tls_nontrivial");

        do {

        char* const thebytes = tls_nontrivial.c_str();

        if(strcmp(thebytes,NonTrivialCtor::INIT_VALUE)!=0)
        {
            TS_FAIL("test_tls_nontrivial: bad initial value; "
                    "expected %s but got %s",
                    NonTrivialCtor::INIT_VALUE, thebytes);
            break;
        }

        task_yield();

        thebytes[0]++;

        task_yield();

        if(strcmp(thebytes,NonTrivialCtor::POST_VALUE)!=0)
        {
            TS_FAIL("test_tls_nontrivial: bad post value; "
                    "expected %s but got %s",
                    NonTrivialCtor::POST_VALUE, thebytes);
            break;
        }

        } while(0);

        TS_INFO(EXIT_MRK "test_tls_nontrivial");

        return nullptr;
    }

}; // End __tls_test namespace

// Test TLS for non trivial constructors
class LibcTlsTestNonTrivial : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Tests a non-trivial constructor TLS variable
     */
    void testTlsNonTrivial()
    {
        TS_INFO(ENTER_MRK "testTlsNonTrivial");
        __tls_test::spawnTasks("testTlsNonTrivial",
                               __tls_test::test_tls_nontrivial);
        TS_INFO(EXIT_MRK "testTlsNonTrivial");
    }
};

#endif // End __TLSMOD_NONTRIVIAL_H
