/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ProcTpLFir.H $                */
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

#ifndef __TEST_PRDFPTPLFIR_H
#define __TEST_PRDFPTPLFIR_H

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

class PTPLFIR:public CxxTest::TestSuite
{
    public:

        void TestRecoverable(void)
        {
            PRDS_BEGIN("PLL in MNFG mode");

            PRDS_ERROR_ENTRY("NODE{0}:PROC{0}", PRDF::RECOVERABLE);

            PRDS_EXPECTED_SIGNATURE("NODE{0}:PROC{0}",0x00ed0000 );

            //GLOBAL_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x570F001B, 0x4000000000000000);

            //TP_CHIPLET_RE_FIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040001, 0x4000000000000000);

            //TP_LFIR
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x0104000a, 0x0000100000000000);

            //TP_LFIR_ACT1
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x01040011, 0xFFFFFFFFFFFFFFFF);

            PRDS_START_SIM();

            PRDS_END();

        }

};
#endif
