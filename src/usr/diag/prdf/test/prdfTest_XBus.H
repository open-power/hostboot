/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_XBus.H $                      */
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
#ifndef __TEST_PRDFXBUSTEST_H
#define __TEST_PRDFXBUSTEST_H

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

class XBUSFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("XBUSFIR Recoverable attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}", 0xdb010000);
            // GLOBAL_RE_FIR set bit 4
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B , 0x0800000000000000);
            // XBUS_CHIPLET_RE_FIR set bit 1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x04040001, 0x4000000000000000);
            // set bit 0
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x0404000a, 0x8000000000000000);
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x04040011, 0xFFFFFFFFFFFFFFFF);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed XBUSFIR Recoverable attention");
            }

        }


        void TestCheckstop(void)
        {
            /*
            PRDS_BEGIN("XBUSFIR Checkstop attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::CHECK_STOP);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:XBUS{1}", 0xdb010002);
            // GLOBAL_RE_FIR set bit 4
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001C , 0x0800000000000000);
            // XBUS_CHIPLET_RE_FIR set bit 3
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:XBUS{1}", 0x04040000, 0x1000000000000000);
            // set bit 2
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:XBUS{1}", 0x0404000a, 0x2000000000000000);
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:XBUS{1}", 0x04040011, 0x0000000000000000);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed XBUSFIR Checkstop attention");
            }
            */
        }
};
#endif
