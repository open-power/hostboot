/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/test/postopchecks_test.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SCOM_POSTOPCHECKS_TEST_H
#define __SCOM_POSTOPCHECKS_TEST_H

#include "../DmiScomWorkaround.H"
#include "../ibscom_retry.H"
#include "../postopchecks.H"

#include "retryWorkaroundTestData.H"

#include <devicefw/userif.H>
#include <errl/errlreasoncodes.H>
#include <ibscom/ibscomreasoncodes.H>
#include <targeting/common/utilFilter.H>
#include <trace/interface.H>

#include <cxxtest/TestSuite.H>

//To enable tracing of SCOM Unit Tests
// TRACE_SCOM_UNIT_TEST=1 make -j32
#ifdef TRACE_SCOM_UNIT_TEST
extern trace_desc_t* g_trac_scom;
#define __TRACE_USE_ONLY__
#define SCOM_POSTOP_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_scom,"PostOPChecks_TEST::" printf_string,##args)
#else
#define __TRACE_USE_ONLY__ __attribute__((unused))
#define SCOM_POSTOP_TRACF(printf_string,args...)
#endif

//Package the TS_FAIL macro with TRACFCOMP error reporting.
//The TS_FAIL macro output seems to be separated from
//TRACFCOMP output. This can be confusing when adding
//trace statements to the tests while debugging. The failure
//message from the SCOM_POSTOP_TRACF macro will
//appear inline and in the proper context to other trace
//statements which may be added during debugging.
#define FAIL_POSTOP_TEST(printf_string,args...) \
    SCOM_POSTOP_TRACF(printf_string, ##args); \
    TS_FAIL("PostOPChecks_TEST::" printf_string, ##args)

using namespace SCOM;
using namespace ERRORLOG;

// PostOpChecks_for_test used for unit testing
// PostOpChecks. PostOpChecks_for_test allows us to
// insert test workarounds instead of the singleton which
// uses non-test workarounds.
class PostOpChecks_for_test: public PostOpChecks
{
public:
     PostOpChecks_for_test(
       std::initializer_list<std::shared_ptr<const PostOpRetryCheck>>
                                  i_retrychecks): PostOpChecks(i_retrychecks){}

     virtual ~PostOpChecks_for_test() = default;
};

//Create a publicly constructable version of IbscomRetry for testing.
class IbscomRetry_for_test: public IbscomRetry
{
public:
    IbscomRetry_for_test() = default;
    virtual ~IbscomRetry_for_test() = default;
};

class PostOPChecks_TEST: public CxxTest::TestSuite
{
public:

    //-----------------------------------------
    // Test the PostOPChecks composite.
    void test_postOpRetry()
    {
        bool l_result{true};
        bool l_rc{};

        do
        {
            //Create a testable instance of IbscomRetry.
            std::shared_ptr<const PostOpRetryCheck>
                                l_IbscomPtr{new IbscomRetry_for_test};

            if(not l_IbscomPtr)
            {
                FAIL_POSTOP_TEST("test_postOpRetry: "
                                 "IbscomRetry::theInstance returned a "
                                 "nullptr!"
                                );


                l_result = false;
                break;
            }

            //Create a DmiScomWorkaround_for_test object
            std::shared_ptr<const PostOpRetryCheck>
                               l_dmiptr(new DmiScomWorkaround_for_test);


             if(not l_dmiptr)
             {
                FAIL_POSTOP_TEST("test_postOpRetry: "
                                 "Unable to create a "
                                 "DmiScomWorkaround_for_test "
                                 "object."
                                );

                l_result = false;
                break;
             }

             //Create PostOpChecks_for_test object
             std::shared_ptr<const PostOpRetryCheck>
                         l_postopcheck(new PostOpChecks_for_test{
                                                                 l_IbscomPtr,
                                                                 l_dmiptr
                                                                });

             if(not l_postopcheck)
             {
                FAIL_POSTOP_TEST("test_postOpRetry: "
                                 "Unable to create a "
                                 "PostOpChecks_for_test "
                                 "object."
                                );

                l_result = false;
                break;
             }

             //initialize and check retry counts. Retry counts are used
             //to determine which workaround requested a retry.
             uint64_t l_total_retry_count{};
             uint64_t l_ibscom_retry_count{};
             uint64_t l_dmi_retry_count{};
             uint64_t l_no_retry_addr{0x22334455}; //Address that does not
                                                   //need a retry.
             uint16_t l_reasonCodeForTrue{IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR};
             uint32_t l_retryCount{0};

             l_postopcheck->resetRetryCount();
             l_total_retry_count = l_postopcheck->getRetryCount();
             l_ibscom_retry_count = l_IbscomPtr->getRetryCount();
             l_dmi_retry_count = l_dmiptr->getRetryCount();

             l_rc = checkExpectedRetryCounts("Pre Test",
                                             l_total_retry_count,
                                             l_ibscom_retry_count,
                                             l_dmi_retry_count,
                                             0,
                                             0,
                                             0
                                            );

             if(not l_rc)
             {
                l_result = false;
                break;
             }

             //Setup errlHndl_t pointer
             std::shared_ptr<ErrlEntry> l_errl;
             l_errl.reset(new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                        ERRL_TEST_MOD_ID,
                                        l_reasonCodeForTrue,
                                        0,
                                        0,
                                        false
                                       )
                         );

             if(not l_errl)
             {
                 FAIL_POSTOP_TEST("test_postOpRetry: "
                                  "Unable to create a ErrlEntry object."
                                 );

                 l_result = false;
                 break;
             }

             //Test 1
             //
             // Ensure that the PostOpRetry composite returns false when
             // its contained children return false.
             //
             // No Errl pointer - IBSCOM will not request retry.
             // Address not in the list of addresses that require a DMI retry.
             //                        - DmiWorkaround will not request retry.
             //
             //Expected Result: FALSE
             //
             l_rc = l_postopcheck->requestRetry(nullptr,
                                                l_retryCount,
                                                DeviceFW::READ,
                                                iv_cumulus_proc_target,
                                                nullptr,
                                                0,
                                                0,
                                                l_no_retry_addr
                                                );

             if(l_rc)
             {
                 FAIL_POSTOP_TEST("test_postOpRetry: "
                                  "requestRetry unexpectedly returned true "
                                  "for a cumulus proc target, null "
                                  "errlHndl_t pointer and address 0x%016X",
                                  l_no_retry_addr
                                 );

                l_result = false;
                break;
             }

             l_total_retry_count = l_postopcheck->getRetryCount();
             l_ibscom_retry_count = l_IbscomPtr->getRetryCount();
             l_dmi_retry_count = l_dmiptr->getRetryCount();

             l_rc = checkExpectedRetryCounts("Test 1",
                                             l_total_retry_count,
                                             l_ibscom_retry_count,
                                             l_dmi_retry_count,
                                             0,
                                             0,
                                             0
                                            );

             if(not l_rc)
             {
                l_result = false;
                break;
             }

             //=============================================
             // IBSCOM Retry test(s)
             //=============================================

             //Test 2
             //
             // Ensure that the PostOpRetry composite returns true when the
             // contained IbscomRetry instance requests a retry and that
             // the retry counts for both the children and composite are as
             // expected.
             //
             // Errl pointer should trigger IBSCOM Retry.
             // Address not in the list of addresses that require a DMI retry.
             //                        - DmiWorkaround will not request retry.
             //
             //Expected Result: TRUE.
             //
             l_rc = l_postopcheck->requestRetry(l_errl.get(),
                                                l_retryCount,
                                                DeviceFW::READ,
                                                iv_cumulus_proc_target,
                                                nullptr,
                                                0,
                                                0,
                                                l_no_retry_addr
                                                );

             if(not l_rc)
             {
                FAIL_POSTOP_TEST("test_postOpRetry: "
                                 "requestRetry unexpectedly returned false "
                                 "for a cumulus proc target, valid "
                                 "errlHndl_t pointer and address 0x%016X",
                                 l_no_retry_addr
                                );

                l_result = false;
                break;
             }

             l_total_retry_count = l_postopcheck->getRetryCount();
             l_ibscom_retry_count = l_IbscomPtr->getRetryCount();
             l_dmi_retry_count = l_dmiptr->getRetryCount();

             l_rc = checkExpectedRetryCounts("Test 2",
                                             l_total_retry_count,
                                             l_ibscom_retry_count,
                                             l_dmi_retry_count,
                                             1, //total expected
                                             1, //ibscom expected
                                             0  //dmi retry expected
                                            );

             if(not l_rc)
             {
                l_result = false;
                break;
             }

             //=============================================
             // DMI Retry test(s)
             //============================================

             //Test 3
             //
             // Ensure that the PostOpRetry composite returns true when the
             // contained DmiScomWorkaround instance requests a retry and that
             // the retry counts for both the children and composite are as
             // expected.
             //
             // Errl pointer is NULL and should not trigger a IBSCOM Retry.
             // Address is in the list of addresses that require a DMI retry.
             //                        - DmiWorkaround will request a retry.
             // Expected Result: TRUE.
             //
             l_rc = l_postopcheck->requestRetry(nullptr,
                                                l_retryCount,
                                                DeviceFW::READ,
                                                iv_cumulus_proc_target,
                                                nullptr,
                                                0,
                                                0,
                                                g_always_retry_addrs.front()
                                                );
             if(not l_rc)
             {
                FAIL_POSTOP_TEST("test_postOpRetry: "
                                 "requestRetry unexpectedly returned false "
                                 "for a cumulus proc target, null "
                                 "errlHndl_t pointer and address 0x%016X",
                                 g_always_retry_addrs.front()
                                );

                l_result = false;
                break;
             }

             l_total_retry_count = l_postopcheck->getRetryCount();
             l_ibscom_retry_count = l_IbscomPtr->getRetryCount();
             l_dmi_retry_count = l_dmiptr->getRetryCount();

             l_rc = checkExpectedRetryCounts("Test 3",
                                             l_total_retry_count,
                                             l_ibscom_retry_count,
                                             l_dmi_retry_count,
                                             2, //total expected
                                             1, //ibscom expected
                                             1  //dmi retry expected
                                            );
             if(not l_rc)
             {
                l_result = false;
                break;
             }
        }
        while(0);

        if(l_result)
        {
            SCOM_POSTOP_TRACF("test_postOpRetry: Test Passed!");
        }
        else
        {
            SCOM_POSTOP_TRACF("test_postOpRetry: Test Failed!");
        }
    }

    //-----------------------------------------------------------
    // Integration test for Scom workarounds
    void test_scom_workaround_integration_test()
    {
        populateRealTargets();
        bool l_result{true};

        do
        {
            //integration test valid on CUMULUS system only
            if(TARGETING::MODEL_CUMULUS != iv_model)
            {
                __TRACE_USE_ONLY__ const char* model_name = "";
                if(TARGETING::MODEL_NIMBUS == iv_model)
                {
                    model_name = "NIMBUS";
                }

                SCOM_POSTOP_TRACF("test_integration_test: "
                                  "Not a Cumulus system. "
                                  "Model: %s, "
                                  "Aborting integration test.",
                                   model_name
                                 );

                break;
            }
            else if(0x00 != iv_ecLevel && 0x10 != iv_ecLevel)
            {
                SCOM_POSTOP_TRACF("test_integration_test: "
                                  "EC Level not valid for Test"
                                  "EC Level: 0x%0x, "
                                  "Aborting integration test.",
                                   iv_ecLevel
                                 );
                break;
            }
            else
            {
                SCOM_POSTOP_TRACF("test_scom_workaround_integration_test: "
                                  "CUMULUS System Detected."
                                 );
            }

            //Ensure that we have a real target for testing.
            if(nullptr == iv_proc_target)
            {
                FAIL_POSTOP_TEST("test_scom_workaround_integration_test: "
                                 "No Targets for test were found!"
                                );

                l_result = false;
                break;
            }

            const PostOpChecks* l_postopptr = PostOpChecks::theInstance();
            if(nullptr == l_postopptr)
            {
                FAIL_POSTOP_TEST("test_scom_workaround_integration_test: "
                                 "PostOpChecks::theInstance "
                                 "returned a nullptr!"
                                );

                l_result = false;
                break;
            }

            l_postopptr->resetRetryCount();

            //STEP 1
            //
            //Test Workarounds on Proc Targets
            //
            //Integration Test of Proc target and all
            //retry addresses.
            //
            //TEST strategy. Iterate through all retry addresses and
            //perform a deviceRead on that address. The retry count
            //for the DmiScomWorkaround should increment for each retry.
            //
            if(iv_proc_target)
            {
                uint64_t l_retryCount{0};
                uint64_t l_expected_retryCount{0};

                //iterate over all retry addresses
                for(uint64_t l_addr: g_always_retry_addrs)
                {
                    uint64_t l_buffer{0};
                    size_t l_bufsize = sizeof(uint64_t);
                    l_expected_retryCount = l_postopptr->getRetryCount();
                    errlHndl_t l_errl = DeviceFW::deviceRead(
                                                  iv_proc_target,
                                                  &l_buffer,
                                                  l_bufsize,
                                                  DEVICE_SCOM_ADDRESS(l_addr)
                                                );
                    if(l_errl)
                    {
                        delete l_errl;
                        l_errl = nullptr;
                        SCOM_POSTOP_TRACF(
                                    "test_scom_workaround_integration_test: "
                                    "Failed to read address "
                                    "0x%016llX for processor target.",
                                    l_addr
                                          );
                    }
                    else
                    {
                        //read succeeded, check that a retry occurred.
                        ++l_expected_retryCount;
                        l_retryCount = l_postopptr->getRetryCount();

                        //Because tests are run concurrently we cannot
                        //use equality to check the retry count. A test
                        //running in another thread may have read a
                        //register that requires a retry and thus bump
                        //the retry count up in addition to this test.
                        if(l_expected_retryCount > l_retryCount)
                        {
                            FAIL_POSTOP_TEST(
                                    "test_scom_workaround_integration_test: "
                                     "retry count not as expected. "
                                     "Expected %d, Actual %d. "
                                     "Target - Proc. Addr: 0x%016llX",
                                     l_expected_retryCount,
                                     l_retryCount,
                                     l_addr
                                           );

                            l_result = false;
                            break;
                        }
                    }
                }

                if(not l_result)
                {
                    break;
                }
            }
        }
        while(0);

        if(l_result)
        {
            SCOM_POSTOP_TRACF("test_scom_workaround_integration_test: "
                                                               "Test Passed!");
        }
        else
        {
            SCOM_POSTOP_TRACF("test_scom_workaround_integration_test: "
                                                               "Test Failed!");
        }
    }

private:

    //Mock target, cumulus proc target.
    const uint64_t iv_proc_addr{0x8100000000000010};

    TARGETING::Target*
    iv_cumulus_proc_target{reinterpret_cast<TARGETING::Target*>(iv_proc_addr)};

    //Real Target
    TARGETING::Target* iv_proc_target{};

    TARGETING::MODEL iv_model{TARGETING::MODEL_NA};
    uint8_t iv_ecLevel{0xFF};

    //-------------------------------------------------------------------------
    bool checkExpectedRetryCounts(
                                    const char* i_test,
                                    uint64_t i_total,
                                    uint64_t i_ibscom,
                                    uint64_t i_dmi,
                                    uint64_t i_expected_total,
                                    uint64_t i_expected_ibscom,
                                    uint64_t i_expected_dmi,
                                    bool i_exactMatch = true
                                 )
    {
        bool l_result{true};

        do
        {
             // For integration tests an exact match is not desirable
             // because tests are run concurrently and retry counts
             // may be influenced by tests running on other threads.
             // For Unit Tests we use dedicated derived test classes
             // whose retry count is unaffected by other tests.
             if((i_exactMatch && (i_expected_total != i_total)) ||
                (!i_exactMatch && (i_expected_total > i_total))
               )
             {

                FAIL_POSTOP_TEST("test_postOpRetry: "
                                 "Unexpected retry count for l_postopcheck. "
                                 "Test: %s, Actual %d. Expected %d",
                                 i_test,
                                 i_total,
                                 i_expected_total
                                );

                l_result = false;
                break;
             }
             else if((i_exactMatch && (i_expected_ibscom != i_ibscom)) ||
                     (!i_exactMatch && (i_expected_ibscom > i_ibscom))
                    )
             {
                FAIL_POSTOP_TEST("test_postOpRetry: "
                                 "Unexpected retry count for l_IbscomPtr. "
                                 "Test: %s, Actual %d. Expected %d",
                                 i_test,
                                 i_ibscom,
                                 i_expected_ibscom
                               );

                l_result = false;
                break;
             }
             else if((i_exactMatch && (i_expected_dmi != i_dmi)) ||
                     (!i_exactMatch && (i_expected_dmi > i_dmi))
                    )
             {
                 FAIL_POSTOP_TEST("test_postOpRetry: "
                                  "Unexpected retry count for l_dmiptr. "
                                  "Test: %s, Actual %d. Expected %d",
                                  i_test,
                                  i_dmi,
                                  i_expected_dmi
                                 );

                l_result = false;
                break;
             }
        }
        while(0);

        return l_result;
    }

    //------------------------------------------------------
    void populateRealTargets()
    {
        do
        {
            iv_ecLevel = 0xFF;
            iv_model = TARGETING::MODEL_NA;
            iv_proc_target = nullptr;

            uint8_t l_ecLevel{};

            TARGETING::TargetHandleList l_targetList;
            TARGETING::getAllChips(l_targetList, TARGETING::TYPE_PROC, false);

            for(int i=0; l_targetList.size(); ++i)
            {
                TARGETING::Target* l_target = l_targetList[i];
                if(nullptr != l_target &&
                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL != l_target)
                {
                    iv_proc_target = l_target;
                    break;
                }
            }

            if(nullptr != iv_proc_target)
            {
                if(iv_proc_target->tryGetAttr<TARGETING::ATTR_EC>(l_ecLevel))
                {
                    iv_ecLevel = l_ecLevel;
                }

                iv_proc_target->tryGetAttr<TARGETING::ATTR_MODEL>(iv_model);
            }
        }
        while(0);
    }

};

#endif
