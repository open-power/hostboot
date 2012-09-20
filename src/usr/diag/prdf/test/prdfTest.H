/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __TEST_PRDFTEST_H
#define __TEST_PRDFTEST_H

/**
 *  @file prdfTest.H
 *
 *  @brief prdf unit test
 */

#ifdef __HOSTBOOT_MODULE
  #include <cxxtest/TestSuite.H>
  #include <errl/errlentry.H>
  #include <errl/errlmanager.H>
#else
  #include <cxxtest/TestSuite.h>
  #include <fsp/FipsGlobalFixture.H>
  #include <errlentry.H>
#endif

#include <prdfTrace.H>
#include <prdfMain.H>
#include "prdfsimMacros.H"
#include <targeting/common/targetservice.H>
#include <prdfPlatServices.H>

class prdfTest: public CxxTest::TestSuite
{
  public:

    void testTrace(void)
    {
        /*
        TS_TRACE(ENTER_MRK "testTrace()");
        PRDF_ENTER( "testTrace()" );

        const char * l_testStr = "running testTrace";
        uint64_t l_testHex = 0xDEADBEEF;
        uint64_t l_testDec = 99;
        PRDF_INF( "testTrace() %s - testHex=0x%08X, testDec=%d", l_testStr, l_testHex, l_testDec );
        PRDF_ERR( "testTrace() Please ignore this error trace 0x%08X", l_testHex );
        PRDF_DENTER( "testTrace()" );
        PRDF_DEXIT( "testTrace()" );

        PRDF_EXIT( "testTrace()" );
        TS_TRACE(EXIT_MRK "testTrace()");
        */
    }

    void testPrdInitialize(void)
    {
        using namespace PRDF;
        using namespace TARGETING;

        TS_TRACE(ENTER_MRK "testPrdInitialize()");
        PRDF_ENTER( "testPrdInitialize()" );

        //FIXME: this is a hack in case some other test code
        //deconfigs all PROC and MEMBUF chip targets

        TargetHandle_t l_pMasterProcChip = NULL;
        targetService().masterProcChipTargetHandle(l_pMasterProcChip);

        // first check for any functional PROC targets
        TargetHandleList list = PlatServices::getFunctionalTargetList( TYPE_PROC );
        if(0 == list.size())
        {
            PRDF_TRAC( "testPrdInitialize(): no functional PROC target found" );
            // set master proc state to functional
            getSimServices().setHwasState(l_pMasterProcChip, true);
        }

        // next check for any functional MEMBUF targets
        list = PlatServices::getFunctionalTargetList( TYPE_MEMBUF );
        if(0 == list.size())
        {
            PRDF_TRAC( "testPrdInitialize(): no functional MEMBUF target found" );
            TARGETING::PredicateCTM classTypeMatch(CLASS_CHIP, TYPE_MEMBUF);
            TargetHandle_t l_pMembuf = NULL;
            targetService().getAssociated(list,
                                          l_pMasterProcChip,
                                          TargetService::CHILD_BY_AFFINITY,
                                          TargetService::ALL,
                                          &classTypeMatch);
            if(list.size() > 0)
            {
                l_pMembuf = list[0];
                // set first membuf state to functional
                getSimServices().setHwasState(l_pMembuf, true);
            }
        }
        //end FIXME hack

        errlHndl_t l_pErr = NULL;
        l_pErr = PRDF::initialize();

        if (l_pErr)
        {
            PRDF_ERR( "testPrdInitialize(): PRDF::initialize() returned error" );
            TS_FAIL("testPrdInitialize(): PRDF::initialize returned error");
            PRDF_COMMIT_ERRL(l_pErr, ERRL_ACTION_REPORT);
        }
        else
        {
            PRDF_INF( "testPrdInitialize(): PRDF::initialize completed with no error" );
            TS_TRACE(INFO_MRK "testPrdInitialize(): PRDF::initialize completed with no error");
        }

        PRDF_EXIT( "testPrdInitialize()" );
        TS_TRACE(EXIT_MRK "testPrdInitialize()");
    }

    void testPrdMain(void)
    {

        using namespace PRDF;
        TS_TRACE(ENTER_MRK "testPrdMain()");
        PRDF_ENTER( "testPrdMain()" );

        // ---------------------------------
        // ---------------------------------
/*
        PRDS_BEGIN("PB Centaur Overflow Special attention");

        PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", SPECIAL);

        // ( 0x42410001, "PBCENTFIR[1]", "PB_CENT_OVERFLOW_ERROR" )
        PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}", 0x42410001);
//        PRDS_EXPECTED_CALLOUT(NONE);

        // GLOBAL_SPA
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001A, 0x2000000000000000);

        // PB_CHIPLET_SPA
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x02040004, 0x8000000000000000);

        // PBCENTFIR
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x02010c40, 0x4000000000000000);

        // PBCENTFIR_ACT0
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x02010c46, 0xFFFFFFFFFFFFFFFF);

        PRDS_START_SIM();

        PRDS_END();
*/

        // ---------------------------------

        PRDS_BEGIN("OCC FW2 recoverable attention");

        PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", RECOVERABLE);

        // ( 0x6c290002, "OCCFIR[2]", "OCC_SCOM_OCCFIR_OCC_FW2" )
        PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}", 0x6c290002);
//        PRDS_EXPECTED_CALLOUT(NONE);

        // GLOBAL_RE_FIR
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B, 0x4000000000000000);

        // TP_CHIPLET_RE_FIR
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040001, 0x2000000000000000);

        // OCCFIR
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01010800, 0x2000000000000000);

        // OCCFIR_ACT1
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01010807, 0xFFFFFFFFFFFFFFFF);

        PRDS_START_SIM();

        PRDS_END();

        // ---------------------------------
/*
        PRDS_BEGIN("MCSI recoverable attention");

        PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", RECOVERABLE);

        //( 0xde310007, "MCIFIR[7]", "MCIFIRQ_MCI_CHINIT_STATE_MACHINE_TIMEOUT" )
        PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:MCS{4}", 0xde310007);
//        PRDS_EXPECTED_CALLOUT(NONE);

        // GLOBAL_RE_FIR
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B, 0x4000000000000000);

        // TP_CHIPLET_RE_FIR[5] Attention from MCIFIR (MCS 4)
        PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040001, 0x0100000000000000);

        // MCIFIR[7]: MCIFIRQ_MCI_CHINIT_STATE_MACHINE_TIMEOUT
        PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011840, 0x0100000000000000);

        // MCIFIR_ACT1
        PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011847, 0xFFFFFFFFFFFFFFFF);

        PRDS_START_SIM();

        PRDS_END();
*/
        // ---------------------------------


        PRDF_EXIT( "testPrdMain()" );
        TS_TRACE(EXIT_MRK "testPrdMain()");
    }

    void testPrdIplCleanup(void)
    {
        using namespace PRDF;
        TS_TRACE(ENTER_MRK "testPrdIplCleanup()");
        PRDF_ENTER( "testPrdIplCleanup()" );

        PRDF::iplCleanup();

        PRDF_EXIT( "testPrdIplCleanup()" );
        TS_TRACE(EXIT_MRK "testPrdIplCleanup()");
    }

};

#endif

