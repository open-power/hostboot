/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ProcMbsFir.H $                */
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

            PRDS_EXPECTED_SIGNATURE("NODE{0}:MEMBUF{4}", 0xa5a10000);

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
