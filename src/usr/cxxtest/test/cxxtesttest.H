/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/cxxtest/test/cxxtesttest.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

#ifndef __TEST_CXXTESTTEST_H
#define __TEST_CXXTESTTEST_H

/**
 *  @file cxxtesttest.H
 *
 *  unit tests for TS_TRACE, TS_WARN, and TS_FAIL macros
 *
 */

/**
 *  @class  cxxtest
 *
 *  - test TS_TRACE, TS_WARN and TS_FAIL macros
 *
 */

#include <cxxtest/TestSuite.H>

class CxxTestTest: public CxxTest::TestSuite
{
public:


    /**
     * @test TS_TRACE macro
     *
     */
    void testCxxTestTrace(void)
    {
        int32_t     l_dec   =   1234567890;
        l_dec--; l_dec++;
        uint32_t    l_hex    =  0x12345678;
        l_hex--; l_hex++;
        uint64_t    l_bighex =  0x1234567890abcdef;
        l_bighex--; l_bighex++;

        TS_TRACE( "CxxTest Trace" );
        TS_TRACE( "CxxTest Trace dec=%d",      l_dec );
        TS_TRACE( "CxxTest Trace hex=0x%x",    l_hex );
        TS_TRACE( "CxxTest Trace bighex=0x%llx",  l_bighex );
        TS_TRACE( "CxxTest Trace pointer=%p",  &l_bighex );
        TS_TRACE( "CxxTest Trace string=%s",   "testing...\n" );

        // all-in one.
        TS_TRACE( "CxxTest Trace dec=%d, hex=0x%x, bighex=0x%llx, ptr=%p, str=%s",
                l_dec, l_hex, l_bighex, &l_bighex, "testing..." );
    }


    /**
     * @test TS_WARN will run if the testExampleWarn_function FAILS
     *
     * @note:   please leave this here, but disabled.  It is useful for
     *          sandbox testing.
     */
//    void testCxxTestWarn(void)
//    {
//        int32_t     l_dec   =   1234567890;
//        uint32_t    l_hex    =  0x12345678;
//        uint64_t    l_bighex =  0x1234567890abcdef;
//
//        TS_WARN( "CxxTest Warning dec=%d",      l_dec );
//        TS_WARN( "CxxTest Warning hex=0x%x",    l_hex );
//        TS_WARN( "CxxTest Warning bighex=0x%llx",  l_bighex );
//        TS_WARN( "CxxTest Warning pointer=%p",  &l_bighex );
//        TS_WARN( "CxxTest Warning string=%s",   "testing...\n" );
//
//        // all-in one.
//        TS_WARN( "CxxTest Warn dec=%d, hex=0x%x, bighex=0x%llx, ptr=%p, str=%s",
//                l_dec, l_hex, l_bighex, &l_bighex, "testing..." );
//
//    }



    /**
     * @test TS_FAIL will run if the testExampleFail function FAILS
     *
     * @note:   please leave this here, but disabled.  It is useful for
     *          sandbox testing.
     */
//    void testCxxTestFail(void)
//   {
//        int32_t     l_dec   =   1234567890;
//        uint32_t    l_hex    =  0x12345678;
//        uint64_t    l_bighex =  0x1234567890abcdef;
//
//        TS_FAIL( "CxxTest Fail dec=%d",      l_dec );
//        TS_FAIL( "CxxTest Fail hex=0x%x",    l_hex );
//        TS_FAIL( "CxxTest Fail bighex=0x%llx",  l_bighex );
//        TS_FAIL( "CxxTest Fail pointer=%p",  &l_bighex );
//        TS_FAIL( "CxxTest Fail string=%s",   "testing...\n" );
//
//        // all-in one.
//        TS_FAIL( "CxxTest FAIL dec=%d, hex=0x%x, bighex=0x%llx, ptr=%p, str=%s",
//                l_dec, l_hex, l_bighex, &l_bighex, "testing..." );
//
//    }




};  // end class

#endif

