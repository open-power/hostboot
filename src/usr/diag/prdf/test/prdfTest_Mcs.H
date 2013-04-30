/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_Mcs.H $                       */
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
#ifndef __TEST_PRDFMCSFIRTEST_H
#define __TEST_PRDFMCSFIRTEST_H

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

class MCIFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("MCI20 Recoverable attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:MCS{4}", 0x2f270000);
            // GLOBAL_RE_FIR set bit 1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B , 0x4000000000000000);
            // TP_CHIPLET_RE_FIR set bit 7
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040001, 0x0100000000000000);
            // set bit 0
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011840, 0x8000000000000000);
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011847, 0xFFFFFFFFFFFFFFFF);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MCI20 Recoverable attention");
            }
        }

        void TestCheckstop(void)
        {
            /*
            PRDS_BEGIN("MCI20 Checkstop attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::CHECK_STOP);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:MCS{4}", 0x2f270003);
            // GLOBAL_RE_FIR set bit 1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001C , 0x4000000000000000);
            // TP_CHIPLET_RE_FIR set bit 9
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040000, 0x0080000000000000);
            // set bit 3
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011840, 0x1000000000000000);
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011847, 0x0000000000000000);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MCI20 Checkstop attention");
            }
            */
        }

        void TestSpecialAttention(void)
        {
            PRDS_BEGIN("MCI20 Special attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::SPECIAL);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:MCS{4}", 0x2f270001);
            // GLOBAL_SPA_FIR set bit 1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001A , 0x4000000000000000);
            // TP_CHIPLET_RE_FIR set bit 5
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040004, 0x0400000000000000);
            // set bit 1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011840, 0x4000000000000000);
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011846, 0xFFFFFFFFFFFFFFFF);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MCI20 Special attention");
            }
        }

};


#endif
