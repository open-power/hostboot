//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/prdf/test/prdfTest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef __TEST_PRDFTEST_H
#define __TEST_PRDFTEST_H

/**
 *  @file prdfTest.H
 *
 *  @brief prdf unit test
 */

#include <cxxtest/TestSuite.H>
#include <prdfTrace.H>
#include <prdf_proto.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>


class prdfTest: public CxxTest::TestSuite
{
  public:

    void testTrace(void)
    {
        TS_TRACE(ENTER_MRK __FUNCTION__);

        PRDF_ENTER( "%s", __FUNCTION__  );

        const char * l_testStr = "running testTrace";
        uint64_t l_testHex = 0xDEADBEEF;
        uint64_t l_testDec = 99;
        PRDF_INF( "testTrace() %s - testHex=0x%08X, testDec=%d", l_testStr, l_testHex, l_testDec );

        uint64_t l_chip = 0xFFFFFFFF;
        uint64_t l_sig = 0x12345678;
        PRDF_SIG( "%08X %08X", l_chip, l_sig);

        PRDF_ERR( "testTrace() Please ignore this error trace 0x%08X", l_testHex );

        PRDF_EXIT( "%s", __FUNCTION__ );

        PRDF_DENTER( "testTrace()" );

        PRDF_DINF( "testTrace() running testTrace" );

        PRDF_DEXIT( "testTrace()" );

        TS_TRACE(EXIT_MRK __FUNCTION__);
    }

    void testPrdInitialize(void)
    {
        using namespace PRDF;
        TS_TRACE(ENTER_MRK __FUNCTION__);
        PRDF_ENTER( "testPrdInitialize()" );

        errlHndl_t l_pErr = NULL;
        l_pErr = PrdInitialize();

        if (l_pErr)
        {
            PRDF_ERR( "testPrdInitialize(): PrdInitialize returned error" );
            TS_FAIL("testPrdInitialize(): PrdInitialize returned error");
            errlCommit(l_pErr,PRDF_COMP_ID);
        }
        else
        {
            PRDF_INF( "testPrdInitialize(): PrdInitialize completed with no error" );
            TS_TRACE(INFO_MRK "testPrdInitialize(): PrdInitialize completed with no error");
        }

        PRDF_EXIT( "testPrdInitialize()" );
        TS_TRACE(EXIT_MRK __FUNCTION__);
    }

    void testPrdMain(void)
    {
        using namespace PRDF;
        TS_TRACE(ENTER_MRK __FUNCTION__);
        PRDF_ENTER( "testPrdMain()" );

        errlHndl_t l_pErr = NULL;
        //l_pErr = PrdMain();

        if (l_pErr)
        {
            PRDF_ERR( "testPrdMain(): PrdMain returned error" );
            TS_FAIL("testPrdMain(): PrdMain returned error");
            errlCommit(l_pErr,PRDF_COMP_ID);
        }
        else
        {
            PRDF_INF( "testPrdMain(): PrdMain completed with no error" );
            TS_TRACE(INFO_MRK "testPrdMain(): PrdMain completed with no error");
        }

        PRDF_EXIT( "testPrdMain()" );
        TS_TRACE(EXIT_MRK __FUNCTION__);
    }

    void testPrdIplCleanup(void)
    {
        using namespace PRDF;
        TS_TRACE(ENTER_MRK __FUNCTION__);
        PRDF_ENTER( "testPrdIplCleanup()" );

        PrdIplCleanup();

        PRDF_EXIT( "testPrdIplCleanup()" );
        TS_TRACE(EXIT_MRK __FUNCTION__);
    }

};

#endif

