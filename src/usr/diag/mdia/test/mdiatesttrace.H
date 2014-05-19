/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatesttrace.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __TEST_MDIATESTTRACE_H
#define __TEST_MDIATESTTRACE_H

/**
 * @file mdiatesttrace.H
 * @brief mdia trace unit test
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include <targeting/common/attributes.H>
#include "../mdiatrace.H"

class MdiaTraceTest : public CxxTest::TestSuite
{
    public:

        void testTrace(void)
        {
            using namespace MDIA;

            TS_TRACE(ENTER_MRK "testTrace");

            MDIA_FAST("mdia trace unit test");
            MDIA_FAST("mdia trace unit test: %p", 0);
            MDIA_FAST("mdia trace unit test: %d", 1234);

            MDIA_DBG("mdia trace unit test");
            MDIA_DBG("mdia trace unit test: %p", 0);
            MDIA_DBG("mdia trace unit test: %d", 1234);

            MDIA_ERR("mdia trace unit test");
            MDIA_ERR("mdia trace unit test: %p", 0);
            MDIA_ERR("mdia trace unit test: %d", 1234);

            MDIA_SLOW("mdia trace unit test");
            MDIA_SLOW("mdia trace unit test: %p", 0);
            MDIA_SLOW("mdia trace unit test: %d", 1234);

            TS_TRACE(EXIT_MRK "testTrace");
        }
};
#endif
