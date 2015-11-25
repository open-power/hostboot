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

namespace __tls_test
{
    thread_local size_t foobar = 0xabcd1234;

    void* test_tls(void* unused)
    {
        decltype(foobar) rc;

        rc = foobar;
        if(rc != 0xabcd1234)
        {
            TS_FAIL("TLS not initialized correctly: %ld", rc);
        }

        task_yield();

        foobar++;

        task_yield();

        rc = foobar;
        if(rc != 0xabcd1235)
        {
            TS_FAIL("TLS increment not operating correctly: %ld", rc);
        }

        return nullptr;
    }
};

class LibcTlsTest : public CxxTest::TestSuite
{
    public:
        void testTls()
        {
            auto t1 = task_create(__tls_test::test_tls, nullptr);
            auto t2 = task_create(__tls_test::test_tls, nullptr);
            auto t3 = task_create(__tls_test::test_tls, nullptr);
            task_wait_tid(t1, nullptr, nullptr);
            task_wait_tid(t2, nullptr, nullptr);
            task_wait_tid(t3, nullptr, nullptr);
        }

};
#endif
