/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_CenTpLFir.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#ifndef __TEST_PRDFCTPLFIR_H
#define __TEST_PRDFCTPLFIR_H

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

class CTPLFIR:public CxxTest::TestSuite
{
    public:

        void TestCenPll(void)
        {
            PRDS_BEGIN("Centaur PLL test");

            PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{4}", PRDF::RECOVERABLE);

            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}",0x00ed0000 );

            //GLOBAL_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x570F001B, 0x4000000000000000);

            //TP_CHIPLET_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x01040001, 0x4000000000000000);

            //TP_LFIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x0104000a, 0x0000180000000000);

            //TP_LFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x01040011, 0xFFFFFFFFFFFFFFFF);

            PRDS_START_SIM();

            PRDS_END();
        }

        void TestCenPllAtThreshold(void)
        {
            PRDS_BEGIN("Centaur PLL test At Threshold");

            PRDS_ERROR_ENTRY("NODE{0}:MEMBUF{4}", PRDF::RECOVERABLE);

            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}",0x00ed0000 );

            //GLOBAL_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x570F001B, 0x4000000000000000);

            //TP_CHIPLET_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x01040001, 0x4000000000000000);

            //TP_LFIR
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x0104000a, 0x0000180000000000);

            //TP_LFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:MEMBUF{4}", 0x01040011, 0xFFFFFFFFFFFFFFFF);

            PRDS_START_SIM();

            PRDS_END();
        }

};
#endif
