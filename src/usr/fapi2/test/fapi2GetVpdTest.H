/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetVpdTest.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#ifndef __FAPI2GETVPDTEST_H
#define __FAPI2GETVPDTEST_H

/**
 * @file getVpdTest.H
 * @brief simple testcase for vpd function
 */

#include <stdint.h>

#include <cxxtest/TestSuite.H>
#include <getVpdTest.H>
#include <pnor/pnorif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

class GetVPDTest : public CxxTest::TestSuite
{

public:

void testGetVPD(void)
{
#ifdef CONFIG_SECUREBOOT
    errlHndl_t pError=NULL;
    do
    {
        pError = PNOR::loadSecureSection(PNOR::MEMD);
        if(pError)
        {
            TS_FAIL("testGetVPD:: failed to load MEMD secure section");
            ERRORLOG::errlCommit(pError,PNOR_COMP_ID);
            break;
        }
#endif
        testGetVPD_MR();

        testGetVPD_MT();

        testDecode_MR();

        testDecode_MT();

        testGetVPD_Override();

        testGetVPD_DQ();

        testGetVPD_CK();
#ifdef CONFIG_SECUREBOOT
        pError = PNOR::unloadSecureSection(PNOR::MEMD);
        if(pError)
        {
            TS_FAIL("testGetVPD:: failed to unload MEMD secure section");
            ERRORLOG::errlCommit(pError,PNOR_COMP_ID);
            break;
        }
    } while(0);
#endif

}

}; // GetVPDTest class

#endif
