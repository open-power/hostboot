/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_CentCs.H $                    */
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

#ifndef __TEST_PRDFCENTCSTEST_H
#define __TEST_PRDFCENTCSTEST_H

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

class CentaurCS:public CxxTest::TestSuite
{
    public:

        void TestCentaurCheckstop(void)
        {
            PRDS_BEGIN("Centaur CS");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}:MBA{0}", 0x43F10003);

            // GLOBAL_RE_FIR set bit 1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B , 0x4000000000000000);

            // TP_CHIPLET_RE_FIR set bit 7
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040001, 0x0100000000000000);

            // MCIFIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011840, 0x0008000100000000);
            // MCIFIR_ACT0
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011846, 0x0001c00000000000);
            // MCIFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCS{4}", 0x02011847, 0x8ee80b1018800000);

            // GLOBAL_CS_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x570F001C, 0x1000000000000000);

            // MEM_CHIPLET_CS_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x03040000, 0x8400000000000000);

            // MBAFIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010600, 0x1000000000000000);
            // MBAFIR_ACT0
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010606, 0x0000000000000000);
            // MBAFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010607, 0x0000000000000000);

            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed Centaur CS");
            }
        }

};


#endif
