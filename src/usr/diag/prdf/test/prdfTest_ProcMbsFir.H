/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ProcMbsFir.H $                */
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

#ifndef __TEST_PRDFMBSFIR_H
#define __TEST_PRDFMBSFIR_H

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

class MBSFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("Centaur Nest MBS Recoverable attention");

            PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{4}", PRDF::RECOVERABLE);

            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}", 0x776c0000);

            //GLOBAL_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x570F001B, 0x2000000000000000);

            //NEST_CHIPLET_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x02040001, 0x0400000000000000);

            //MBSFIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x02011400, 0x8000000000000000);

            //MBSFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x02011407, 0xFFFFFFFFFFFFFFFF);

            //MBSFIR_mask
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x02011405, 0x8000000000000000);

            //MBSFIR_reset
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x02011401, 0x7FFFFFFFFFFFFFFF);

            PRDS_START_SIM();

            PRDS_END();

        }

};
#endif
