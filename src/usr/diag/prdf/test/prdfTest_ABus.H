/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ABus.H $                      */
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
#ifndef __TEST_PRDFABUSTEST_H
#define __TEST_PRDFABUSTEST_H

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

class PBESFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("PBESFIR Recoverable attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}", 0xa0570000);
            // GLOBAL_RE_FIR set bit 8
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B , 0x0080000000000000);
            // ABUS_CHIPLET_RE_FIR set bit 2
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x08040001, 0x2000000000000000);
            // set bit 0
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x08010800, 0x8000000000000000);
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x08010807, 0xFFFFFFFFFFFFFFFF);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed PBESFIR Recoverable attention");
            }
        }

        void TestCheckstop(void)
        {
            /*
            PRDS_BEGIN("PBESFIR Checkstop attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::CHECK_STOP);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:ABUS{1}", 0xa0570003);
            // GLOBAL_RE_FIR set bit 8
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001C , 0x0080000000000000);
            // ABUS_CHIPLET_RE_FIR set bit 4
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:ABUS{1}", 0x08040000, 0x0800000000000000);
            // set bit 3
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:ABUS{1}", 0x08010800, 0x1000000000000000);
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:ABUS{1}", 0x08010807, 0x0000000000000000);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed PBESFIR Checkstop attention");
            }
            */
        }
};
#endif
