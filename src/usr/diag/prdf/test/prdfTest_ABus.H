/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ABus.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#include <prdfTargetServices.H>
#include "prdfsimMacros.H"

class PBESFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            // @todo RTC 178802 Enable test cases turned off during bring up
            if ( TARGETING::MODEL_CUMULUS != PRDF::PlatServices::getChipModel(
                    PRDF::PlatServices::getMasterProc() ) )
            {
                PRDS_BEGIN("PBIOOFIR Recoverable attention");
                PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);
                PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}", 0x720C0014);
                // GLOBAL_RE_FIR set bit 5
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x500F001B , 0x0400000000000000);
                // NEST Chiplet (recov error)  set bit 14
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x05040001, 0x0002000000000000);
                // set bit 20  (A0 link framer  error)
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x05013800, 0x0000080000000000);
                // ACT1
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x05013807, 0xFFFFFFFFFFFFFFFF);
                PRDS_START_SIM();
                if(!(PRDS_END()))
                {
                    TS_FAIL("Expected Signature Failed PBIOOFIR Recoverable attention");
                }
            }
        }

        void TestCheckstop(void)
        {
            // @todo RTC 178802 Enable test cases turned off during bring up
            if ( TARGETING::MODEL_CUMULUS != PRDF::PlatServices::getChipModel(
                    PRDF::PlatServices::getMasterProc() ) )
            {
                PRDS_BEGIN("PBESFIR Checkstop attention");
                PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::CHECK_STOP);
                PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}", 0x720c001c);
                // GLOBAL_RE_FIR set bit 8
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x500F001C , 0x0400000000000000);
                // NEST Chiplet (chkstop error)  set bit 16
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x05040000,  0x0000800000000000);


                // set bit 28  (PSR  A0 even link down error)
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x05013800, 0x0000000800000000);
                // ACT1
                PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x05013807, 0x0000000000000000);
                PRDS_START_SIM();
                if(!(PRDS_END()))
                {
                    TS_FAIL("Expected Signature Failed PBESFIR Checkstop attention");
                }
            }
        }
};
#endif
