/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2HwAccessTest.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <p10_hwtests.H>
#include <plat_hwp_invoker.H>



using namespace fapi2;

//This function does nothing, it is used to call FAPI_INVOKE on
fapi2::ReturnCode empty_function(void)
{
    return fapi2::current_err;
}


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
    errlHndl_t l_errl = nullptr;
    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        numTests++;
        if(l_chipList.size() == 0)
        {
            TS_FAIL("FAPI2_fapi2HwAccess:: could not find any procs, skipping tests");
            numFails++;
            break;
        }

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_chipList[0]);

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_scomtest_getscom_fail, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p10_scomtest_getscom_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_scomtest_putscom_fail, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p10_scomtest_putscom_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_cfamtest_putcfam_fail, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p10_cfamtest_putcfam_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_cfamtest_getcfam_fail, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
        }
        else
        {
            TS_FAIL("No error from p10_cfamtest_getcfam_fail !!");
            numFails++;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_scomtest_getscom_pass, fapi2_procTarget);
        if(l_errl)
        {
            TS_FAIL("Error from p10_scomtest_getscom_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                          // a false negative on the next case
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_scomtest_putscom_pass, fapi2_procTarget);
        if(l_errl)
        {
            TS_FAIL("Error from p10_scomtest_putscom_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                          // a false negative on the next case (future?)
        }

        numTests++;
        uint8_t failed = 0;
        FAPI_INVOKE_HWP(l_errl,
                        p10_opmodetest_ignorehwerr,
                        fapi2_procTarget,
                        failed );

        if(l_errl || failed)
        {
            TS_FAIL("p10_opmodetest_ignorehwerr returned an error!!");
            numFails++;
            if(l_errl)
            {
                errlCommit(l_errl,FAPI2_COMP_ID);
            }
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_piberrmask_masktest, fapi2_procTarget);
        if(l_errl)
        {
            TS_FAIL("p10_piberrmask_masktest returned an error!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
        }

    }while(0);

    FAPI_INF("fapi2HwAccessTest Test Complete. %d/%d fails",  numFails , numTests);
}

void test_piberrmask()
{
    FAPI_INF("Entering test_piberrmask...");
    FAPI_INF("Ensure that getPIBErrorMask return 0 initially");

    errlHndl_t l_errl = nullptr;

    do
    {
        uint8_t mask = fapi2::getPIBErrorMask();
        if(mask != 0)
        {
            TS_FAIL("test_piberrmask>> Expected fapi2::getPIBErrorMask to return (0x0) but instead returned 0x%x", mask);
            break;
        }

        FAPI_INF("Setting pib_err_mask to PIB_CHIPLET_OFFLINE (0x2) and checking that we get it back with getPIBErrorMask");

        fapi2::setPIBErrorMask((uint8_t)PIB::PIB_CHIPLET_OFFLINE);
        mask = fapi2::getPIBErrorMask();
        if(mask != PIB::PIB_CHIPLET_OFFLINE)
        {
            TS_FAIL("test_piberrmask>> Expected fapi2::getPIBErrorMask to return 0x2 but instead returned 0x%x", mask);
            break;
        }

        //Call FAPI_INVOKE on an empty function to test if
        //it resets the pib err mask
        FAPI_INVOKE_HWP(l_errl,empty_function);
        if( l_errl )
        {
            TS_FAIL("test_piberrmask got an error !!");
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
        }

        mask = fapi2::getPIBErrorMask();
        if(mask != 0)
        {
            TS_FAIL("test_piberrmask>> Expected fapi2::getPIBErrorMask to return PIB_NO_ERROR (0x0) but instead returned %x , FAPI_INVOKE failed to reset pib_err_mask", mask);
            break;
        }

    }while(0);

    FAPI_INF("Exiting test_piberrmask...");
}


void test_getsetopmode()
{
    FAPI_INF("Enter test_getsetopmode");
    FAPI_INF("Ensure that getOpMode return NORMAL initially");

    do
    {
        fapi2::OpModes mode = fapi2::getOpMode();
        if(mode != fapi2::NORMAL)
        {
            TS_FAIL("test_getsetopmode>> Expected fapi2::getOpMode to return fapi2::NORMAL (0x0) but instead returned %x", mode);
            break;
        }

        FAPI_INF("Setting opMode to IGNORE_HW_ERROR (0x1) and checking that we get it back with getOpMode");

        fapi2::setOpMode(fapi2::IGNORE_HW_ERROR);
        mode = fapi2::getOpMode();
        if(mode != fapi2::IGNORE_HW_ERROR)
        {
            TS_FAIL("test_getsetopmode>> Expected fapi2::getOpMode to return fapi2::IGNORE_HW_ERROR (0x1) but instead returned %x", mode);
            break;
        }

        //Call FAPI_INVOKE on an empty function to test if it resets the opMode
        errlHndl_t l_errl = nullptr;
        FAPI_INVOKE_HWP(l_errl,empty_function);
        if( l_errl )
        {
            TS_FAIL("test_getsetopmode got an error !!");
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
        }

        mode = fapi2::getOpMode();
        if(mode != fapi2::NORMAL)
        {
            TS_FAIL("test_getsetopmode>> Expected fapi2::getOpMode to return fapi2::NORMAL (0x0) but instead returned %x , FAPI_INVOKE failed to reset opmode", mode);
            break;
        }

    }while(0);

    FAPI_INF("Exiting test_getsetopmode");
}


};

#endif // End __FAPI2_HWACCESSTEST_H
