/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/test/DmiScomWorkaround_test.H $                  */
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
#ifndef __SCOM_DMI_SCOM_WORKAROUND_TEST_H
#define __SCOM_DMI_SCOM_WORKAROUND_TEST_H

#include "DmiScomWorkaround_for_test.H"
#include "retryWorkaroundTestData.H"

#include <cxxtest/TestSuite.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/target.H>
#include <trace/interface.H>

#include <vector>

// Tracing is disabled by default.
// To turn on tracing, build the tests as shown below:
// TRACE_SCOM_UNIT_TEST=1 make -j32
#ifdef TRACE_SCOM_UNIT_TEST
extern trace_desc_t* g_trac_scom;
#define SCOM_DMI_WORKAROUND_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_scom,"DMI_WRKAROUND_TEST::" printf_string,##args)
#else
#define SCOM_DMI_WORKAROUND_TRACF(printf_string,args...)
#endif

//Package the TS_FAIL macro with TRACFCOMP error reporting.
//The TS_FAIL macro output seems to be separated from
//TRACFCOMP output. This can be confusing when adding
//trace statements to the tests while debugging. The failure
//message from the SCOM_DMI_WORKAROUND_TRACF macro will
//appear inline and in the proper context to other trace
//statements which may be added during debugging.
#define FAIL_DMIWKRD_TEST(printf_string,args...) \
    SCOM_DMI_WORKAROUND_TRACF(printf_string, ##args); \
    TS_FAIL("DMI_WRKAROUND_TEST::" printf_string, ##args)

using namespace SCOM;
using namespace ERRORLOG;

class DMI_WRKAROUND_TEST: public CxxTest::TestSuite
{
public:

    //-------------------------------------------------------------------
    // The DmiScomWorkaround will request a
    // retry based upon the following conditions
    //
    // requestRetry parameters retry Conditions
    //   1) errlHndl_t - Not used.
    //   2) uint32_t i_retryCount - Must be 0.
    //   3) DeviceFW::OperationType - Must be a read operation.
    //   4) TARGETING::Target* i_target - Must be a PROC or DMI target
    //   5) void* i_buffer - Not Used
    //   6) size_t i_buflen - Not Used
    //   7) int64_t i_accessType - Not Used
    //   8) uint64_t i_addr - Address must be in a list of addresses
    //                        defined in DmiScomWorkaround. There is
    //                        a list for each DMI 0-7, and a list for
    //                        DMI SCOM addresses accessed by a PROC
    //                        target.


    //-----------------------------------------------------------------------
    // Test Cumulus Proc Target with addresses that do not require retries.
    // All requestRetry calls should return false.
    void test_cumulus_proc_with_no_retry_addr()
    {
        bool l_result{true};
        populateMockTargets();

        do
        {
            std::shared_ptr<const PostOpRetryCheck>
                                  l_workaround(new DmiScomWorkaround_for_test);


            if(not l_workaround)
            {
                FAIL_DMIWKRD_TEST("test_cumulus_proc_with_no_retry_addr: "
                                  "Unable to create a "
                                  "DmiScomWorkaround_for_test "
                                  "object."
                                 );

                l_result = false;
                break;
            }

            //iterate through the list of addresses that do not
            //require retries.
            for(uint64_t addr: g_always_no_retry_addrs)
            {
                bool l_rc{false};

                l_rc = l_workaround->requestRetry(nullptr,
                                                  0,
                                                  DeviceFW::READ,
                                                  iv_cumulus_proc_target,
                                                  nullptr,
                                                  0,
                                                  0,
                                                  addr
                                                 );
                if(l_rc)
                {
                    FAIL_DMIWKRD_TEST("test_cumulus_proc_with_no_retry_addr: "
                                      "requestRetry unexpectedly "
                                      "returned true for a cumulus proc "
                                      "target and address 0x%016X", addr
                                     );

                    l_result = false;
                    break;
                }
            }
        }
        while(0);

        if(l_result)
        {
            SCOM_DMI_WORKAROUND_TRACF("test_cumulus_proc_with_no_retry_addr: "
                                                               "Test Passed!");
        }
        else
        {
            SCOM_DMI_WORKAROUND_TRACF("test_cumulus_proc_with_no_retry_addr: "
                                                               "Test Failed!");
        }
    }

    //-----------------------------------------------------------------------
    // Test Nimbus Proc Target with addresses that do not require retries.
    // All requestRetry calls should return false as the workaround is not
    // required on Nimbus systems.
    void test_nimbus_proc_with_no_retry_addr()
    {
        bool l_result{true};
        populateMockTargets();

        do
        {
            std::shared_ptr<const PostOpRetryCheck>
                                  l_workaround(new DmiScomWorkaround_for_test);

            if(not l_workaround)
            {
                FAIL_DMIWKRD_TEST("test_nimbus_proc_with_no_retry_addr: "
                                  "Unable to create a "
                                  "DmiScomWorkaround_for_test "
                                  "object."
                                 );

                l_result = false;
                break;
            }

            //iterate through the list of addresses that do not
            //require retries.
            for(uint64_t addr: g_always_no_retry_addrs)
            {
                bool l_rc{false};

                l_rc = l_workaround->requestRetry(nullptr,
                                                  0,
                                                  DeviceFW::READ,
                                                  iv_nimbus_proc_target,
                                                  nullptr,
                                                  0,
                                                  0,
                                                  addr
                                                 );
                if(l_rc)
                {
                    FAIL_DMIWKRD_TEST("test_nimbus_proc_with_no_retry_addr: "
                                      "requestRetry unexpectedly "
                                      "returned true for a nimbus "
                                      "proc target and address "
                                      "0x%016X",
                                      addr
                                     );

                    l_result = false;
                    break;
                }
            }
        }
        while(0);

        if(l_result)
        {
            SCOM_DMI_WORKAROUND_TRACF("test_nimbus_proc_with_no_retry_addr: "
                                                               "Test Passed!");
        }
        else
        {
            SCOM_DMI_WORKAROUND_TRACF("test_nimbus_proc_with_no_retry_addr: "
                                                               "Test Failed!");
        }
    }

    //---------------------------------------------------------------------
    // Test Cumulus Proc Target with addresses that require retries.
    // All requestRetry calls should return true.
    void test_cumulus_proc_with_retry_addr()
    {
        bool l_result{true};
        populateMockTargets();

        uint8_t l_ecLevel{};
        TARGETING::Target* l_target{};

        do
        {
            std::shared_ptr<const PostOpRetryCheck>
                                  l_workaround(new DmiScomWorkaround_for_test);


            if(not l_workaround)
            {
                FAIL_DMIWKRD_TEST("test_cumulus_proc_with_retry_addr: "
                                  "Unable to create a "
                                  "DmiScomWorkaround_for_test "
                                  "object"
                                 );

                l_result = false;
                break;
            }

            //Do Tests with default EC Level = 0x10
            getTargetECLevel(iv_cumulus_proc_target, l_ecLevel);

            l_result = do_proc_test(l_workaround,
                                    iv_cumulus_proc_target,
                                    "cumulus",
                                    true, //expected result of retryRequest
                                    l_ecLevel
                                   );

            //Do Tests with EC Level = 0x00
            l_target = setTargetEcLevel(iv_cumulus_proc_target,
                                                      0x00
                                                     );

            l_result = do_proc_test(l_workaround,
                                    l_target,
                                    "cumulus",
                                    true, //expected result of retryRequest
                                    0x00
                                   );

            //Do Tests with EC Level = 0x11
            l_target = setTargetEcLevel(iv_cumulus_proc_target,
                                                      0x11
                                                     );

            l_result = do_proc_test(l_workaround,
                                    l_target,
                                    "cumulus",
                                    false, //expected result of retryRequest
                                    0x11
                                   );

        }
        while(0);

        if(l_result)
        {
            SCOM_DMI_WORKAROUND_TRACF("test_cumulus_proc_with_retry_addr: "
                                                               "Test Passed!");
        }
        else
        {
            SCOM_DMI_WORKAROUND_TRACF("test_cumulus_proc_with_retry_addr: "
                                                               "Test Failed!");
        }
    }

    //---------------------------------------------------------------------
    // Test NIMBUS Proc Target with addresses that require retries.
    // All requestRetry calls should return false since the workaround
    // is not required on NIMBUS systems.
    void test_nimbus_proc_with_retry_addr()
    {
        bool l_result{true};
        populateMockTargets();
        uint8_t l_ecLevel{};

        do
        {
            std::shared_ptr<const PostOpRetryCheck>
                                  l_workaround(new DmiScomWorkaround_for_test);


            if(not l_workaround)
            {
                FAIL_DMIWKRD_TEST("test_nimbus_proc_with_retry_addr: "
                                  "Unable to create a "
                                  "DmiScomWorkaround_for_test "
                                  "object."
                                 );

                l_result = false;
                break;
            }

            getTargetECLevel(iv_cumulus_proc_target, l_ecLevel);
            l_result = do_proc_test(l_workaround,
                                    iv_nimbus_proc_target,
                                    "nimbus",
                                    false, //expected result of retryRequest
                                    l_ecLevel
                                    );
        }
        while(0);

        if(l_result)
        {
            SCOM_DMI_WORKAROUND_TRACF("test_nimbus_proc_with_retry_addr: "
                                                               "Test Passed!");
        }
        else
        {
            SCOM_DMI_WORKAROUND_TRACF("test_nimbus_proc_with_retry_addr: "
                                                               "Test Failed!");
        }
    }

    //--------------------------------------------------------------------
    // The above tests were based upon addresses and targets. This test
    // uses the other relevant parameters to the requestRetry method.
    void test_other_args_for_false()
    {
        bool l_result{true};
        bool l_rc{false};

        do
        {
             std::shared_ptr<const PostOpRetryCheck>
                                 l_workaround(new DmiScomWorkaround_for_test);


             if(not l_workaround)
             {
                FAIL_DMIWKRD_TEST("test_other_args_for_false: "
                                  "Unable to create a "
                                  "DmiScomWorkaround_for_test "
                                  "object."
                                 );

                l_result = false;
                break;
             }

             std::shared_ptr<ErrlEntry> l_errl;
             l_errl.reset(new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                       ERRL_TEST_MOD_ID,
                                       ERRL_TEST_REASON_CODE,
                                       0,
                                       0,
                                       false
                                      )
                           );

             if(not l_errl)
             {
                FAIL_DMIWKRD_TEST("test_other_args_for_false: "
                                  "Unable to create ErrlEntry object."
                              );

                l_result=false;
                break;
             }

             //TEST 1
             //
             //CUMULUS Proc Target.
             //ErrorEntry Valid.
             //Address requires retry for CUMULUS dmi/proc targets.
             //
             //Expected Result: TRUE
             //
             //Ensures that the result is not effected by a valid
             //errHndl_t parameter.

             // requestRetry parameters retry Conditions
             //   1) errlHndl_t - Not NULL.
             //   2) uint32_t i_retryCount - 0.
             //   3) DeviceFW::OperationType - READ
             //   4) TARGETING::Target* i_target - PROC
             //   8) uint64_t i_addr - In Retry List.
             l_rc = l_workaround->requestRetry(l_errl.get(),
                                               0,
                                               DeviceFW::READ,
                                               iv_cumulus_proc_target,
                                               nullptr,
                                               0,
                                               0,
                                               g_always_retry_addrs.front()
                                              );

             if(not l_rc)
             {
                FAIL_DMIWKRD_TEST("test_other_args_for_false: "
                                  "requestRetry unexpectedly returned "
                                  "false when called with a non-null "
                                  "ErrlEntry pointer"
                                 );

                 l_result=false;
                 break;
             }

             //TEST 2
             //
             //CUMULUS Proc Target
             //Address requires retry for CUMULUS dmi/proc targets.
             //Retry Count non-zero indicating a multiple
             //retry request.
             //
             //Expected Result: FALSE
             //
             //Ensures that the result is false for a multiple retry request.

             // requestRetry parameters retry Conditions
             //   1) errlHndl_t - NULL.
             //   2) uint32_t i_retryCount - 1. <---- causes false return.
             //   3) DeviceFW::OperationType - READ
             //   4) TARGETING::Target* i_target - PROC
             //   8) uint64_t i_addr - In Retry List.
             l_rc = l_workaround->requestRetry(nullptr,
                                               1,
                                               DeviceFW::READ,
                                               iv_cumulus_proc_target,
                                               nullptr,
                                               0,
                                               0,
                                               g_always_retry_addrs.front()
                                              );

             if(l_rc)
             {
                FAIL_DMIWKRD_TEST("test_other_args_for_false: "
                                  "requestRetry unexpectedly returned "
                                  "true when called with a retry count "
                                  "of 1."
                                 );

                 l_result=false;
                 break;
             }

             //TEST 3
             //Address requires retry for CUMULUS dmi/proc targets.
             //CUMULUS Proc Target
             //
             //Operation was a WRITE. Workaround only enabled for READ.
             //
             //Expected Result: FALSE
             //
             //Ensures that the result is false for a write operation.
             //
             // requestRetry parameters retry Conditions
             //   1) errlHndl_t - NULL.
             //   2) uint32_t i_retryCount - 0.
             //   3) DeviceFW::OperationType - WRITE <---- causes false return.
             //   4) TARGETING::Target* i_target - PROC
             //   8) uint64_t i_addr - In Retry List.
             //
             l_rc = l_workaround->requestRetry(nullptr,
                                               0,
                                               DeviceFW::WRITE,
                                               iv_cumulus_proc_target,
                                               nullptr,
                                               0,
                                               0,
                                               g_always_retry_addrs.front()
                                             );

             if(l_rc)
             {
                FAIL_DMIWKRD_TEST("test_other_args_for_false: "
                                  "requestRetry unexpectedly returned "
                                  "true when called with a "
                                  "Write command. "
                                 );

                 l_result=false;
                 break;
             }
        }
        while(0);

        if(l_result)
        {
            SCOM_DMI_WORKAROUND_TRACF("test_other_args_for_false: "
                                                               "Test Passed!");
        }
        else
        {
            SCOM_DMI_WORKAROUND_TRACF("test_other_args_for_false: "
                                                               "Test Failed!");
        }
    }

private:

    TARGETING::Target* iv_nimbus_proc_target{};
    TARGETING::Target* iv_cumulus_proc_target{};
    TARGETING::Target* iv_proc_target{};

    void populateMockTargets()
    {
        //Encodings for mock targets
        // 0x4000000000000000 DMI Target
        // 0x8000000000000000 PROC Target
        // 0x0200000000000000 NIMBUS
        // 0x0100000000000000 CUMULUS
        // 0x00000000000000XX Chip Unit

        uint64_t addr = 0x8200000000000010;
        iv_nimbus_proc_target = reinterpret_cast<TARGETING::Target*>(addr);

        addr = 0x8100000000000010;
        iv_cumulus_proc_target = reinterpret_cast<TARGETING::Target*>(addr);

        addr = 0x8000000000000010;
        iv_proc_target = reinterpret_cast<TARGETING::Target*>(addr);
    }

    //------------------------------------------------------------------------
    bool do_proc_test(std::shared_ptr<const PostOpRetryCheck>& i_workaround,
                     TARGETING::Target* i_target,
                     const char* i_model,
                     const bool i_expected,
                     const uint8_t i_eclevel
                     )
    {
        bool l_result{true};
        bool l_rc{false};
        const char* l_oppositeExpString = i_expected?"false":"true";

        do
        {
            //iterate through the complete list of retry addresses
            for(uint64_t addr: g_always_retry_addrs)
            {

                l_rc = i_workaround->requestRetry(nullptr,
                                                  0,
                                                  DeviceFW::READ,
                                                  i_target,
                                                  nullptr,
                                                  0,
                                                  0,
                                                  addr
                                                 );
                if(i_expected != l_rc)
                {
                    FAIL_DMIWKRD_TEST("test_%s_proc_with_retry_addr: "
                                      "requestRetry unexpectedly "
                                      "returned %s for a %s proc "
                                      "target with EC Level 0x%0X "
                                      "and address 0x%016llX",
                                      i_model,
                                      l_oppositeExpString,
                                      i_model,
                                      i_eclevel,
                                      addr
                                     );

                    l_result = false;
                    break;
                }
            }
        }
        while(0);

        return l_result;
    }

    //----------------------------------------------------------------------
    TARGETING::Target* setTargetEcLevel(TARGETING::Target* i_target,
                                        uint8_t i_ecLevel
                                        )
    {
        constexpr uint64_t ECLevelMask{0x00000000000000FF};

        uint64_t l_targetAddr = reinterpret_cast<uint64_t>(i_target);
        l_targetAddr &= ~ECLevelMask;
        l_targetAddr |= (ECLevelMask & i_ecLevel);

        return reinterpret_cast<TARGETING::Target*>(l_targetAddr);
    }

    //-----------------------------------------------------------------------
    void getTargetECLevel(TARGETING::Target* i_target,
                                                    uint8_t& o_ecLevel) const
    {
        constexpr uint64_t ECLevelMask{0x00000000000000FF};

        uint64_t l_targetAddr = reinterpret_cast<uint64_t>(i_target);

        const uint64_t l_ecLevel = l_targetAddr & ECLevelMask;
        o_ecLevel = static_cast<uint8_t>(l_ecLevel);
    }
};

#endif
