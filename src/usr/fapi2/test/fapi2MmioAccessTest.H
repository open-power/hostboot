/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2MmioAccessTest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
#include <p10_mmiotests.H>
#include <plat_hwp_invoker.H>
#include <test/exptest_utils.H>
#include <targeting/odyutil.H>

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
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_getmmio_invalid_target, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p10_mmiotest_getmmio_invalid_target !!");
            numFails++;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_putmmio_invalid_target, fapi2_procTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p10_mmiotest_putmmio_invalid_target !!");
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

    if (!iv_serializeTestMutex)
    {
        TS_FAIL("test_fapi2MmioInvalidSizes(): unable to get test mutex");
        return;
    }
    mutex_lock(iv_serializeTestMutex);

    for (auto & l_ocmb: l_ocmbTargetList)
    {
        if(TARGETING::UTIL::isOdysseyChip(l_ocmb))
        {
            TS_INFO("test_fapi2MmioInvalidSizes() - Odyssey chip detected; skipping the test");
            continue; // TODO JIRA: PFHB-477 re-enable this test for Odyssey
        }
        Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapi2_ocmbTarget( l_ocmb );
        auto first_ocmb_info = l_ocmb->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        if (!first_ocmb_info.useInbandScom)
        {
            TS_FAIL("test_fapi2MmioInvalidSizes() - scom access is not using inband");
            continue;
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_indivisible_by_section_size, fapi2_ocmbTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p10_mmiotest_indivisible_by_section_size !!");
            numFails++;
        }
        auto second_ocmb_info = l_ocmb->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        if (!second_ocmb_info.useInbandScom)
        {
            TS_FAIL("p9_mmiotest_indivisible_by_section_size turned off mmio operations");
            l_ocmb->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(first_ocmb_info);
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_invalid_section_size, fapi2_ocmbTarget);
        if(l_errl != nullptr)
        {
            delete l_errl; // delete expected error log
            l_errl = nullptr;
        }
        else
        {
            TS_FAIL("No error from p10_mmiotest_invalid_section_size !!");
            numFails++;
        }
        auto third_ocmb_info = l_ocmb->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        if (!third_ocmb_info.useInbandScom)
        {
            TS_FAIL("p9_mmiotest_invalid_section_size turned off mmio operations");
            l_ocmb->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(first_ocmb_info);
        }
    }
    mutex_unlock(iv_serializeTestMutex);

    FAPI_INF("test_fapi2MmioInvalidSizes Test Complete. %d/%d fails", numFails, numTests);
}

//******************************************************************************
// test_fapi2MmioAccess
//******************************************************************************
void test_fapi2MmioAccess()
{
    int numTests = 0;
    int numFails = 0;

    errlHndl_t l_errl = nullptr;

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_chipList;

    // Get a list of all of the OCMB chips
    TARGETING::getAllChips(l_chipList, TARGETING::TYPE_OCMB_CHIP, true);

    if (!iv_serializeTestMutex)
    {
        TS_FAIL("test_fapi2MmioAccess(): unable to get test mutex");
        return;
    }
    mutex_lock(iv_serializeTestMutex);
    for (auto & l_ocmb: l_chipList)
    {
        if(TARGETING::UTIL::isOdysseyChip(l_ocmb))
        {
            TS_INFO("test_fapi2MmioAccess() - Odyssey chip detected; skipping the test");
            continue; // TODO JIRA: PFHB-477 re-enable this test for Odyssey
        }

        Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi2_target( l_ocmb );

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_getmmio_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p10_mmiotest_getmmio_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                          // a false negative on the next case
            l_errl = nullptr;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_putmmio_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p10_mmiotest_putmmio_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
            l_errl = nullptr;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_double_read_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p10_mmiotest_double_read_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
            l_errl = nullptr;
        }

        numTests++;
        FAPI_INVOKE_HWP(l_errl, p10_mmiotest_write_read_pass, l_fapi2_target);
        if(l_errl)
        {
            TS_FAIL("Error from p10_mmiotest_write_read_pass !!");
            numFails++;
            errlCommit(l_errl,FAPI2_COMP_ID);
            delete l_errl; // delete unexpected error log so we dont get
                           // a false negative on the next case
            l_errl = nullptr;
        }
    }
    mutex_unlock(iv_serializeTestMutex);

    FAPI_INF("fapi2MmioAccessTest Test Complete. %d/%d fails", numFails, numTests);
}

/**
 * @brief Constructor
 */
Fapi2MmioAccessTest() : CxxTest::TestSuite()
{
    // All modules are loaded by runtime,
    // so testcase loading of modules is not required
#ifndef __HOSTBOOT_RUNTIME
    errlHndl_t err = nullptr;
    err = exptest::loadModule(exptest::MSS_LIBRARY_NAME);
    if(err)
    {
        TS_FAIL("Fapi2MmioAccessTest() - Constuctor: failed to load MSS module");
        errlCommit( err, TARG_COMP_ID );
    }
#endif
    iv_serializeTestMutex = exptest::getTestMutex();
};

/**
 * @brief Deconstructor
 */
~Fapi2MmioAccessTest()
{
}


private:
  // This is used for tests that need to not run operations at the same time
  TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR iv_serializeTestMutex;

};

#endif // End __FAPI2_MMIOACCESSTEST_H
