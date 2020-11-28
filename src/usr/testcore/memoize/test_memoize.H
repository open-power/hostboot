/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/memoize/test_memoize.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __TEST_MEMOIZE_H
#define __TEST_MEMOIZE_H

/**
 *  @file test_memoize.H
 *  @brief Tests memoize utility
 */

#include <cxxtest/TestSuite.H>

#include <errl/errlmanager.H>
#include <util/memoize.H>
#include <runtime/runtime_reasoncodes.H>

int g_accesses = 0;

errlHndl_t _incrementer(int in, int& out)
{
    errlHndl_t pError = NULL;

    g_accesses++;

    if(in > 2)
    {
        // A junk error log, this combination never occurs elsewhere
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            RUNTIME::MOD_CUST_CONF_HBRT_HYP_IDS,
            RUNTIME::RT_NO_PROC_TARGET,
            0,0 );
    }
    else
    {
        out = in + 1;
    }

    return pError;
}

errlHndl_t incrementer(int in, int& out)
{
    return Util::Memoize::memoize<errlHndl_t>(_incrementer,in,out);
}

class MemoizerTest: public CxxTest::TestSuite
{
  public:

    void testMemoizer(void)
    {
        TS_TRACE( ENTER_MRK
            "testMemoizer> start" );

        errlHndl_t pError = NULL;

        do {

        int test = 1;
        int accesses = g_accesses;
        int result = 0;

        // Should get no error
        pError = incrementer(test,result);
        if(pError)
        {
            TS_FAIL("testMemoizer> call to memoizer returned error");
            break;
        }

        // Should get input + 1 as result
        if(result != (test+1))
        {
            TS_FAIL("testMemoizer> memoizer did not increment the input");
            break;
        }

        // Should register an access
        if(g_accesses != (accesses+1))
        {
            TS_FAIL("testMemoizer> real function did not dispatch");
            break;
        }

        accesses = g_accesses;
        test = 1;
        result = 0;
        // Should be able to repeat same request with no error
        pError = incrementer(test,result);
        if(pError)
        {
            TS_FAIL("testMemoizer> call to memoizer returned error");
            break;
        }

        // ... and same answer
        if(result != (test+1))
        {
            TS_FAIL("testMemoizer> memoizer did not increment the input");
            break;
        }

        // ... and no additional accesses
        if(g_accesses != accesses)
        {
            TS_FAIL("testMemoizer> real function dispatched unexpectedly");
            break;
        }

        accesses = g_accesses;
        test = 3;
        result = 0;
        int origResult = 0;

        // Should get an error as using a bad input value
        pError = incrementer(test,result);
        if(pError == NULL)
        {
            TS_FAIL("testMemoizer> call to memoizer did not return error");
            break;
        }

        delete pError;
        pError = NULL;

        // ... and should register an access
        if(g_accesses != (accesses+1))
        {
            TS_FAIL("testMemoizer> real function did not dispatch");
            break;
        }

        // ... and result should have been left as is
        if(result != origResult)
        {
            TS_FAIL("testMemoizer> memoize changed the output unexpectedly");
            break;
        }

        accesses = g_accesses;
        test = 3;
        result = 0;
        origResult = 0;

        // Should be able to make same bad request and get an error
        pError = incrementer(test,result);
        if(pError == NULL)
        {
            TS_FAIL("testMemoizer> call to memoizer did not return error");
            break;
        }

        delete pError;
        pError = NULL;

        // ... and should still register an access (i.e. nothing
        // got accidentally cached in error path)
        if(g_accesses != (accesses+1))
        {
            TS_FAIL("testMemoizer> real function did not dispatch");
            break;
        }

        // ... and result should have been left as is
        if(result != origResult)
        {
            TS_FAIL("testMemoizer> memoize changed the output unexpectedly");
            break;
        }

        } while(0);

        if(pError)
        {
            errlCommit(pError,UTIL_COMP_ID);
        }

        TS_TRACE( EXIT_MRK
            "testMemoizer> finish" );
    }

}; // End class MemoizerTest

#endif

