/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfTest_ScomAccessInterface.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef __TEST_PRDFSCOMACCESS_H
#define __TEST_PRDFSCOMACCESS_H

/**
 *  @file prdfTest_ScomAccessInterface.H
 *
 *  @brief prdf unit test for scom access interfaces
 */

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

#include <prdfPlatServices.H>
#include <prdfBitString.H>
#include <prdfScomRegister.H>

using namespace PRDF;


class ScomAccessInterface: public CxxTest::TestSuite
{
public:

    void TestScomInterfaces(void)
    {
        TS_TRACE(ENTER_MRK "-Scom Access Interface Test 1 - Put Scom - Start-");

        uint32_t rc = SUCCESS;
        TARGETING::TargetHandle_t target;

        //we will be using bit 61 of this address which is a spare bit in the
        //OCC fir, which shouldn't generate an attention
        uint64_t address = 0x01010800;
        CPU_WORD l_cpuWord[(64)/(sizeof(CPU_WORD)*8)] = {0};
        BIT_STRING_CLASS exp(64, l_cpuWord);
        BIT_STRING_CLASS bs(64, l_cpuWord);

        TARGETING::TargetHandleList targetList =
            PRDF::PlatServices::getFunctionalTargetList(TARGETING::TYPE_PROC);

        do
        {

            if (0 == targetList.size())
            {
                TS_FAIL("List of functional procs is empty");
                break;
            }
            else
            {
                target = targetList[0];
            }

            //spare bit in OCC fir
            bs.Set(61);

            rc = PRDF::PlatServices::putScom(target, bs, address);

            exp.SetBits(bs);

            if (SUCCESS != rc)
            {
                TS_FAIL("Unexpected error calling PRDF::PlatServices::putScom");
                break;
            }
            bs.Clear();

            rc = PRDF::PlatServices::getScom(target, bs, address);

            if (SUCCESS != rc)
            {
                TS_FAIL("Unexpected error calling PRDF::PlatServices::getScom");
                break;
            }

            if (!(exp == bs))
            {
                TS_FAIL("Unexpected data from getScom");
                break;
            }
        }while(0);

        TS_TRACE(EXIT_MRK "- Scom Access Interface Test 1 - Put Scom - End -");
    }

};
#endif
