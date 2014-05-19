/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_CentCs.H $                    */
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
            PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{4}", PRDF::RECOVERABLE);
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
