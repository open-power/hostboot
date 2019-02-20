/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2MmioAccessTest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __FAPI2_MMIOACCESSTEST_H
#define __FAPI2_MMIOACCESSTEST_H

/**
 *  @file src/usr/fapi2/test/fapi2MmioAccessTest.H
 *
 *  @brief Test various types of MMIO access with FAPI2 Macros
 */

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <fapi2TestUtils.H>
#include <p9_mmiotests.H>
#include <plat_hwp_invoker.H>
#include <config.h>

using namespace fapi2;

class Fapi2MmioAccessTest : public CxxTest::TestSuite
{
public:
//******************************************************************************
// test_fapi2MmioInvalidTarget
// Try calling mmio operation on invalid targets
//******************************************************************************
void test_fapi2MmioInvalidTarget()
{
    errlHndl_t l_errl = nullptr;
    int numTests = 0;
    int numFails = 0;

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_procTargetList;

    // Get a list of all of the proc chips
    TARGETING::getAllChips(l_procTargetList, TARGETING::TYPE_PROC, true);

    for (auto & l_proc: l_procTargetList)
    {
        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget( l_proc );

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_getmmio_invalid_target, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p9_mmiotest_getmmio_invalid_target !!");
            numFails++;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_putmmio_invalid_target, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p9_mmiotest_putmmio_invalid_target !!");
            numFails++;
        }
    }
    FAPI_INF("test_fapi2MmioInvalidTarget Test Complete. %d/%d fails", numFails, numTests);
}

//******************************************************************************
// test_fapi2MmioInvalidSizes
// Try calling mmio operation with invalid input sizes
//******************************************************************************
void test_fapi2MmioInvalidSizes()
{
    errlHndl_t l_errl = nullptr;
    int numTests = 0;
    int numFails = 0;

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_ocmbTargetList;

    // Get a list of all of the OCMB chips
    TARGETING::getAllChips(l_ocmbTargetList, TARGETING::TYPE_OCMB_CHIP, true);

    for (auto & l_ocmb: l_ocmbTargetList)
    {
        Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapi2_ocmbTarget( l_ocmb );

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_indivisible_by_section_size, fapi2_ocmbTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p9_mmiotest_indivisible_by_section_size !!");
            numFails++;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_invalid_section_size, fapi2_ocmbTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p9_mmiotest_invalid_section_size !!");
            numFails++;
        }
    }

    FAPI_INF("test_fapi2MmioInvalidSizes Test Complete. %d/%d fails", numFails, numTests);
}

//******************************************************************************
// test_fapi2MmioAccess
//******************************************************************************
void test_fapi2MmioAccess()
{
    int numTests = 0;
    int numFails = 0;

#ifndef CONFIG_AXONE_BRING_UP
    errlHndl_t l_errl = nullptr;

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_chipList;

    // Get a list of all of the OCMB chips
    TARGETING::getAllChips(l_chipList, TARGETING::TYPE_OCMB_CHIP, true);

    for (auto & l_ocmb: l_chipList)
    {
        Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi2_target( l_ocmb );

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_getmmio_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p9_mmiotest_getmmio_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                          // a false negative on the next case
            l_errl = nullptr;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_putmmio_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p9_mmiotest_putmmio_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
            l_errl = nullptr;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_double_read_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p9_mmiotest_double_read_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
            l_errl = nullptr;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_mmiotest_write_read_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p9_mmiotest_write_read_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
            l_errl = nullptr;
        }
    }
#endif

    FAPI_INF("fapi2MmioAccessTest Test Complete. %d/%d fails", numFails, numTests);
}


};

#endif // End __FAPI2_MMIOACCESSTEST_H
