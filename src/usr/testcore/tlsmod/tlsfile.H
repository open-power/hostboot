/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/tlsmod/tlsfile.H $                           */
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

#ifndef __TLSMOD_TLSFILE_H
#define __TLSMOD_TLSFILE_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>

namespace __tls_test
{

// @note: see src/usr/testcore/lib/tls.H for API definition
void spawnTasks(
     const char* const i_pFnName,
           void*(*i_pFn)(void*));

extern size_t INTERFILE_INIT_VALUE;
extern size_t INTERFILE_POST_VALUE;

extern thread_local size_t tls_interfile;

/**
 *  @brief Test a TLS variable defined in a different file
 */
void* test_tls_interfile(void* unused)
{
    TS_INFO(ENTER_MRK "test_tls_interfile");

    do {

    decltype(tls_interfile) rc = tls_interfile;
    if(rc != INTERFILE_INIT_VALUE)
    {
        TS_FAIL("test_tls_interfile: bad initial value; "
                "expected 0x%016llX but got 0x%016llX",
                INTERFILE_INIT_VALUE,rc);
        break;
    }

    task_yield();

    tls_interfile++;

    task_yield();

    rc = tls_interfile;
    if(rc != INTERFILE_POST_VALUE)
    {
        TS_FAIL("test_tls_interfile: bad post value; "
                "expected 0x%016llX but got 0x%016llX",
                INTERFILE_POST_VALUE,rc);
        break;
    }

    } while(0);

    TS_INFO(EXIT_MRK "test_tls_interfile");

    return nullptr;
}

}; // End __tls_test namespace

// Test TLS between translation units (i.e. between files)
class LibcTlsTestFile : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test as bunch of TLS vars in a different file
     */
    void testTlsInterfile()
    {
        TS_INFO(ENTER_MRK "testTlsInterfile");
        __tls_test::spawnTasks("testTlsInterfile",
                               __tls_test::test_tls_interfile);
        TS_INFO(EXIT_MRK "testTlsInterfile");
    }

};

#endif // End __TLSMOD_TLSFILE_H
