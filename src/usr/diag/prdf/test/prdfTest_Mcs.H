/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_Mcs.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
#ifndef __TEST_PRDFMCSFIRTEST_H
#define __TEST_PRDFMCSFIRTEST_H

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

class MCIFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("MCI23 Recoverable attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);

            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:MCBIST{1}:MCS{0}", 0xc4f70000);

            // GLOBAL_RE_FIR set bit 3
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x500F001B , 0x1000000000000000);
            // Nest --  set MCS23_0 bit
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x03040001, 0x2000000000000000);

            // MCIFIR  0x05010800 / 0x03010800
            // set bit 0 -- MC internal RECOV error
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{1}:MCS{0}", 0x05010800, 0x8000000000000000);

            // MCIFIR  0x05010807 / 0x03010807
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{1}:MCS{0}", 0x05010807, 0xFFFFFFFFFFFFFFFF);

            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MCI23 Recoverable attention");
            }
        }


        void TestCheckstop(void)
        {
            PRDS_BEGIN("MCI23 Chkstop attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::CHECK_STOP);

            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}:MCBIST{1}:MCS{0}", 0xc4f70001);

            // GLOBAL_CS_FIR set bit 3
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x500F001C , 0x1000000000000000);
            // Nest --  set MCS23_0 bit
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x03040000, 0x0800000000000000);

            // NEST CHIPLET_RE_FIR set bit 9
            // MCIFIR  0x05010800 / 0x03010800
            // set bit 1 -- MC internal non-RECOV error
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{1}:MCS{0}", 0x05010800, 0x4000000000000000);

            // MCIFIR  0x05010807 / 0x03010807
            // ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{1}:MCS{0}", 0x05010807, 0x0000000000000000);

            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MCI20 Chkstop attention");
            }
        }


        void TestSpecialAttention(void)
        {
            PRDS_BEGIN("MCI20 Special attention");
            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::HOST_ATTN);
            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}", 0x5993000a);

            // To treat spec attn as HOST attn
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{0}", 0x070123E0 , 0x0000000000000001);
            // GLOBAL HOST Attn_FIR set bit 7
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x50040009 , 0x0100000000000000);

            // MCS chiplet HOST attn_FIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{0}", 0x07040009, 0x8040000000000000);
            // MASK
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{0}", 0x0704001A, 0x0F0FFFFFFFFFFFFF);

            // set bit for maint cmd complete
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{0}", 0x07012300, 0x0020000000000000);
            // ACT0 - spec/host
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{0}", 0x07012306, 0x0020000000000000);
            // MASK
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:MCBIST{0}", 0x07012303, 0xFFDFFFFFFFFFFFFF);


        // Although this will run, PRD code will assert since we are not
        // running in MDIA mode when we get this host/spec attention.
        // Hence, need to skip this for now.
        /*
            PRDS_START_SIM();
            if(!(PRDS_END()))
            {
                TS_FAIL("Expected Signature Failed MCI20 Special attention");
            }
        */
        }
};


#endif
