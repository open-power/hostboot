/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

    void testPrdMain(void)
    {
        using namespace PRDF;
        TS_TRACE(ENTER_MRK "testPrdMain()");
        PRDF_ENTER( "testPrdMain()" );

        // ---------------------------------
/*
        PRDS_BEGIN("Maintenance Command Complete Special Attention");

        PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{0}", SPECIAL);

        // ( 0x9e8b0000, "MBASPA[0]", "MBSPAQ_COMMAND_COMPLETE_WO_ENA_ERR_ATTN" )
//        PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:MCS{4}:MEMBUF{0}:MBS{0}:MBA{0}", 0x9e8b0000);
        PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{0}:MBS{0}:MBA{0}", 0x9e8b0000);
//        PRDS_EXPECTED_CALLOUT(NONE);

        // GLOBAL_SPA
        PRDS_SCR_WRITE("NODE{0}:MEMBUF{0}", 0x570F001A, 0x1000000000000000);

        // MEM_CHIPLET_SPA
        PRDS_SCR_WRITE("NODE{0}:MEMBUF{0}", 0x03040004, 0x8000000000000000);

        // MBASPA
        PRDS_SCR_WRITE("NODE{0}:MEMBUF{0}:MBS{0}:MBA{0}", 0x03010611, 0x8000000000000000);

        PRDS_START_SIM();

        PRDS_END();
*/
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

