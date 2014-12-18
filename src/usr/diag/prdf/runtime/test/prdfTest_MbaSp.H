/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/runtime/test/prdfTest_MbaSp.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __TEST_PRDFMBASPTEST_H
#define __TEST_PRDFMBASPTEST_H

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <prdfTrace.H>
#include <prdfMain.H>
#include "prdfsimMacros.H"

class MBAFIRSP:public CxxTest::TestSuite
{
    public:

        void TestSpl(void)
        {
            PRDS_BEGIN("MBAFIR01 special attention");
            PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{4}", PRDF::SPECIAL);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}:MBA{0}", 0x9e8b0001);
            // GLOBAL_SP_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x570F001A, 0x1000000000000000);
            // MEM_CHIPLET_SPA_FIR[0] Attention from MBAFIR01
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x03040004, 0x8000000000000000);
            // set MBASPA
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}:MBA{0}", 0x03010611,
                            0x4000000000000000);
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MBAFIR01 "
                        "recoverable attention");
            }
        }
};
#endif
