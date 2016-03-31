/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2HwAccessTest.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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


#ifndef __FAPI2_HWACCESSTEST_H
#define __FAPI2_HWACCESSTEST_H

/**
 *  @file src/usr/fapi2/test/fapi2HwAccessTest.H
 *
 *  @brief Test various types of HW access with FAPI2 Macros
 */




#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2TestUtils.H>
#include <p9_hwtests.H>



using namespace fapi2;


class Fapi2HwAccessTest : public CxxTest::TestSuite
{
public:
//******************************************************************************
// test_fapi2HwAccess
//******************************************************************************
void test_fapi2HwAccess()
{
    int numTests = 0;
    int numFails = 0;
    errlHndl_t l_errl = NULL;
    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        TARGETING::Target * l_nimbusProc = NULL;

        //Take the first NIMBUS proc and use it
        for(uint32_t i = 0; i < l_chipList.size(); i++)
        {
            if(TARGETING::MODEL_NIMBUS ==
            l_chipList[i]->getAttr<TARGETING::ATTR_MODEL>())
            {
                l_nimbusProc = l_chipList[i];
                break;
            }
        }

        numTests++;
        if(l_nimbusProc == NULL)
        {
            // Send an errorlog because we cannot find any NIMBUS procs.
            TS_FAIL("FAPI2_GETPARENT:: could not find Nimbus proc, skipping tests");
            numFails++;
            break;
        }

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(
                l_nimbusProc);

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_scomtest_getscom_fail, fapi2_procTarget);
        if(l_errl != NULL)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p9_scomtest_getscom_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_scomtest_putscom_fail, fapi2_procTarget);
        if(l_errl != NULL)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p9_scomtest_putscom_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_cfamtest_putcfam_fail, fapi2_procTarget);
        if(l_errl != NULL)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p9_cfamtest_putcfam_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_cfamtest_getcfam_fail, fapi2_procTarget);
        if(l_errl != NULL)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p9_cfamtest_getcfam_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_scomtest_getscom_pass, fapi2_procTarget);
        if(l_errl)
        {
            TS_FAIL("Error from p9_scomtest_getscom_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                          // a false negative on the next case
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_scomtest_putscom_pass, fapi2_procTarget);
        if(l_errl)
        {
            TS_FAIL("Error from p9_scomtest_putscom_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                          // a false negative on the next case (future?)
        }
    }while(0);

    FAPI_INF("fapi2HwAccessTest Test Complete. %d/%d fails",  numFails , numTests);

}

};

#endif // End __FAPI2_HWACCESSTEST_H