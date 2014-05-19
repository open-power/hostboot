/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ProcCentFir.H $               */
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

#ifndef __TEST_PRDFPCENTFIR_H
#define __TEST_PRDFPCENTFIR_H

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

class PCENTFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("PCENTFIR Recoverable attention");

            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);

            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}",0x42410004 );

            //GLOBAL_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B, 0x2000000000000000);

            //PB_CHIPLET_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x02040001, 0x0200000000000000);

            //PBCENTFIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x02010C40, 0x0800000000000000);

            //PBCENTFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x02010C47, 0xFFFFFFFFFFFFFFFF);

            PRDS_START_SIM();

            PRDS_END();

        }

};
#endif
