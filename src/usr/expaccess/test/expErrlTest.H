/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/expErrlTest.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#ifndef __expErrlTest_H
#define __expErrlTest_H

/**
 *  @file ExpErrorLogTest.H
 *
 *  @brief Test case for explorer error log grabbing/adding
*/

#include <cxxtest/TestSuite.H>
#include <fapi2.H>
#include "expErrlTest.C"
#include <exptest_utils.H>

using namespace fapi2;

class test_expErrorLog: public CxxTest::TestSuite
{
public:

    /**
     * @brief Test adding Explorer error logs via RC
     */
    void testExpErrorLogRc(void)
    {
        // @todo RTC 214629 - disabled until simics implements exp_error_log
        return;

        if (!iv_serializeTestMutex)
        {
            TS_FAIL("iv_serializedTestMutex is not setup, unable to continue");
        }
        else
        {
            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);
            uint32_t l_res = expErrorLogRc();
            if (l_res != 0)
            {
                TS_FAIL("rcTestExpErrorLogRc. Fail l_res=%d", l_res);
            }
            // atomic section <<
            mutex_unlock(iv_serializeTestMutex);
        }
    }

    /**
     * @brief  Test hostboot side of adding Explorer error log to errl
     */
    void testExpErrorLogHb(void)
    {
        // @todo RTC 214629 - disabled until simics implements exp_error_log
        return;

        if (!iv_serializeTestMutex)
        {
            TS_FAIL("iv_serializedTestMutex is not setup, unable to continue");
        }
        else
        {
            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);
            uint32_t l_res = expErrorLogHb();

            if (l_res != 0)
            {
                TS_FAIL("testExpErrorLogHb. Fail l_res=%d", l_res);
            }
            // atomic section <<
            mutex_unlock(iv_serializeTestMutex);
        }
    }

    /**
     * @brief Constructor
     */
    test_expErrorLog() : CxxTest::TestSuite()
    {
        // All modules are loaded by runtime,
        // so testcase loading of modules is not required
#ifndef __HOSTBOOT_RUNTIME
        errlHndl_t err = nullptr;

        // For testing, just load the library needed and don't bother with
        // unloading to avoid pulling the rug from under other tests that need
        // the loaded library
        err = exptest::loadModule(exptest::MSS_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("OCMBCommTest() - Constuctor: failed to load MSS module");
            errlCommit( err, TARG_COMP_ID );
        }
#endif
        iv_serializeTestMutex = exptest::getTestMutex();
    };

    private:
      // This is used for tests that need to not run operations at the same time
      TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR iv_serializeTestMutex;

};

#endif
