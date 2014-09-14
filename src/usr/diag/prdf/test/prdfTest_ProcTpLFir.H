/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ProcTpLFir.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
            PRDS_BEGIN("PCI PLL");

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


            // ############ PLL regs ###########

            // PCI_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001F,
            //0x0000000000000001);

            // PCI_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001E,
            //0x0008000000000001);

            // PB_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001F,
                           0x0000006000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001F,
            //0x0000000000000001);

            // PB_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001E,
            //0x0008000000000001);

            // ABUS_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001F,
            //0x0000000000000001);

            // ABUS_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001E,
            //0x0008000000000001);

            // EX_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
            //0x0000000000000001);

            // EX_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
            //0x0008000000000001);


            PRDS_START_SIM();

            PRDS_END();
        }

        void TestPllAtThreshold(void)
        {
            PRDS_BEGIN("PCI PLL At Threshold");

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


            // ############ PLL regs ###########

            // PCI_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001F,
            //0x0000000000000001);

            // PCI_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001E,
            //0x0008000000000001);

            // PB_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001F,
                           0x0000006000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001F,
            //0x0000000000000001);

            // PB_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001E,
            //0x0008000000000001);

            // ABUS_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001F,
            //0x0000000000000001);

            // ABUS_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001E,
            //0x0008000000000001);

            // EX_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
            //0x0000000000000001);

            // EX_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
            //0x0008000000000001);


            PRDS_START_SIM();

            PRDS_END();
        }


        // test Proc PLL error -------------------------

        void TestProcPll(void)
        {
            PRDS_BEGIN("Proc PLL");

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


            // ############ PLL regs ###########

            // PCI_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001F,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001F,
            //0x0000000000000001);

            // PCI_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001E,
            //0x0008000000000001);

            // PB_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001F,
                           0x0000006000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001F,
            //0x0000000000000001);

            // PB_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001E,
            //0x0008000000000001);

            // ABUS_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001F,
            //0x0000000000000001);

            // ABUS_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001E,
            //0x0008000000000001);

            // EX_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
            //0x0000000000000001);

            // EX_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
            //0x0008000000000001);


            PRDS_START_SIM();

            PRDS_END();
        }

        void TestProcPllAtThreshold(void)
        {
            PRDS_BEGIN("Proc PLL At Threshold");

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


            // ############ PLL regs ###########

            // PCI_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001F,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001F,
            //0x0000000000000001);

            // PCI_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x090F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x090F001E,
            //0x0008000000000001);

            // PB_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001F,
                           0x0000006000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001F,
            //0x0000000000000001);

            // PB_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x020F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x020F001E,
            //0x0008000000000001);

            // ABUS_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001F,
            //0x0000000000000001);

            // ABUS_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}", 0x080F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}", 0x080F001E,
            //0x0008000000000001);

            // EX_ERROR_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
                           0x0000004000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001F,
            //0x0000000000000001);

            // EX_CONFIG_REG
            PRDS_SCR_WRITE("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
                           0x0000000000000001);
            //PRDS_SCR_EXPECT("NODE{0}:PROC{0}:EX{4}", 0x100F001E,
            //0x0008000000000001);


            PRDS_START_SIM();

            PRDS_END();
        }


};
#endif
