/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_Mba.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
