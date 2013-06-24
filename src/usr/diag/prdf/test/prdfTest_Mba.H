/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_Mba.H $                       */
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
#ifndef __TEST_PRDFMBATEST_H
#define __TEST_PRDFMBATEST_H

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

class MBAFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("MBAFIR01 recoverable attention");
            PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{4}", PRDF::RECOVERABLE);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}:MBA{0}", 0x43f10003);
            //        PRDS_EXPECTED_CALLOUT(NONE);
            // GLOBAL_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x570F001B, 0x1000000000000000);
            // MEM_CHIPLET_RE_FIR[3] Attention from MBAFIR01
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x03040001, 0x1000000000000000);
            // set MBAFIR01[3]
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010600, 0x1000000000000000);
            // MBAFIR01_ACT1
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010607, 0xFFFFFFFFFFFFFFFF);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MBAFIR01 recoverable attention");
            }
        }

        void DISABLED_TestCheckstop(void)
        {
            PRDS_BEGIN("MBAFIR01 Checkstop attention");
            PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{4}", PRDF::CHECK_STOP);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}:MBA{0}", 0x43f10002);
            //        PRDS_EXPECTED_CALLOUT(NONE);
            // GLOBAL_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x570F001C, 0x1000000000000000);
            // MEM_CHIPLET_CS_FIR[5] Attention from MBAFIR01
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x03040000, 0x0400000000000000);
            // set MBAFIR01[0]
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010600, 0x2000000000000000);
            // MBAFIR01_ACT1
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010607, 0x0000000000000000);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MBAFIR01 Checkstop attention");
            }
        }

};
#endif
