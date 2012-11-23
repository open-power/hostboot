/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_Ex.H $                        */
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
#ifndef __TEST_PRDFEXTEST_H
#define __TEST_PRDFEXTEST_H

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

class ExLFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("EXLFIR recoverable attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:EX{5}", 0xb53a0007);
            // GLOBAL_RE_FIR set bit 21
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B, 0x0000040000000000);
            // EX_CHIPLET_RE_FIR[1] Attention from EXLFIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{5}", 0x10040001, 0x4000000000000000);
            // set EXLFIR[7]
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{5}", 0x1004000a, 0x0100000000000000);
            // EXLFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{5}", 0x10040011, 0xFFFFFFFFFFFFFFFF);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed EXLFIR recoverable attention");
            }
        }

        void TestCheckstop(void)
        {
           /*
            PRDS_BEGIN("EXLFIR Checkstop attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::CHECK_STOP);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:EX{5}", 0xb53a0003);
            // GLOBAL_RE_FIR bit 21
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001C, 0x0000040000000000);
            // EX_CHIPLET_CS_FIR[3] Attention from EXLFIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{5}", 0x10040000, 0x1000000000000000);
            // set EXLFIR[3]
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{5}", 0x1004000a, 0x1000000000000000);
            // EXLFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{5}", 0x10040011, 0x0000000000000000);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed EXLFIR Checkstop attention");
            }
            */
        }
};
#endif
