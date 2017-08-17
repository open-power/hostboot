/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/test/ibscom_retry_test.H $                       */
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
#ifndef __SCOM_IBSCOM_RETRY_TEST
#define __SCOM_IBSCOM_RETRY_TEST

#include "../ibscom_retry.H"
#include <ibscom/ibscomreasoncodes.H>
#include <errl/errlreasoncodes.H>

#include <cxxtest/TestSuite.H>
#include <trace/interface.H>

// Tracing is disabled by default.
// To turn on tracing, build the tests as shown below:
// TRACE_SCOM_UNIT_TEST=1 make -j32
#ifdef TRACE_SCOM_UNIT_TEST
extern trace_desc_t* g_trac_scom;
#define SCOM_IBSCOM_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_scom,"IbScomRetryTest::" printf_string,##args)
#else
#define SCOM_IBSCOM_TRACF(printf_string,args...)
#endif

//Package the TS_FAIL macro with TRACFCOMP error reporting.
//The TS_FAIL macro output seems to be separated from
//TRACFCOMP output. This can be confusing when adding
//trace statements to the tests while debugging. The failure
//message from the SCOM_IBSCOM_TRACF macro will
//appear inline and in the proper context to other trace
//statements which may be added during debugging.
#define FAIL_IBSCOM_TEST(printf_string,args...) \
    SCOM_IBSCOM_TRACF(printf_string, ##args); \
    TS_FAIL("IbScomRetryTest::" printf_string, ##args)

using namespace SCOM;
using namespace ERRORLOG;

class IbScomRetryTest: public CxxTest::TestSuite
{
public:

    //--------------------------------------------
    // The IbscomRetry workaround will request a
    // retry if an error occurred with a result code
    // of IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR.
    //
    // requestRetry parameters retry Conditions
    //   1)  errlHndl_t - Not Null and Reason Code is
    //                    IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR
    //   2) uint32_t i_retryCount - Must be 0.
    //   3) DeviceFW::OperationType - Not Used
    //   4) TARGETING::Target* i_target - Not Used
    //   5) void* i_buffer - Not Used
    //   6) size_t i_buflen - Not Used
    //   7) int64_t i_accessType - Not Used
    //   8) uint64_t i_addr - Not Used
    //
    void test_lbscom_retry()
    {
        bool l_result{true};

        do
        {
            //Get the single IbscomRetry instance.
            std::shared_ptr<const PostOpRetryCheck> l_wrkaround =
                                                IbscomRetry::theInstance();

            if(not l_wrkaround)
            {
                FAIL_IBSCOM_TEST("test_lbscom_retry: "
                                 "IbscomRetry::theInstance returned a "
                                 "nullptr!"
                                );

                l_result = false;
                break;
            }

            uint16_t l_reasonCodeForTrue{IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR};
            uint16_t l_reasonCodeForFalse{
                               static_cast<uint16_t>(l_reasonCodeForTrue + 1)};

            uint32_t l_retryCount{0};
            std::shared_ptr<ErrlEntry> l_errl;

            // Test 1
            // Use a successful error entry (nullptr).
            //
            // 1) errlHndl_t - NULL <--- causes false result
            //
            // 2) uint32_t i_retryCount - 0.
            //
            // Expected return: FALSE.
            //
            bool l_retval = l_wrkaround->requestRetry(l_errl.get(),
                                                      l_retryCount,
                                                      DeviceFW::READ,
                                                      nullptr,
                                                      nullptr,
                                                      0,
                                                      0,
                                                      0
                                                     );
            if(l_retval)
            {
                FAIL_IBSCOM_TEST("test_lbscom_retry: "
                                 "requestRetry unexpectedly returned true "
                                 "for a nullptr errlHndl_t."
                                );

                l_result = false;
                break;
            }

            l_errl.reset(new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                       ERRL_TEST_MOD_ID,
                                       l_reasonCodeForTrue,
                                       0,
                                       0,
                                       false
                                      )
                       );

            // Test 2
            // A non-nullptr error with reason code
            // IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR and
            // Retry Count equal to 0.
            //
            // 1)  errlHndl_t - Not Null and Reason Code is
            //                  IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR
            // 2) uint32_t i_retryCount - 0.
            //
            // Expected result: TRUE
            //
            l_retval = l_wrkaround->requestRetry(l_errl.get(),
                                                 l_retryCount,
                                                 DeviceFW::READ,
                                                 nullptr,
                                                 nullptr,
                                                 0,
                                                 0,
                                                 0
                                                );

            if(not l_retval)
            {
                FAIL_IBSCOM_TEST("test_lbscom_retry: "
                                 "requestRetry unexpectedly returned false "
                                 "for reson code "
                                 "IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR and retry "
                                 "attempts %d.",
                                 l_retryCount
                                );

                l_result = false;
                break;
            }

            // Test 3
            // A non-nullptr error with reason code
            // IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR and
            // Retry Count equal to 1.
            //
            // 1) errlHndl_t - Not Null and Reason Code is
            //                 IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR
            // 2) uint32_t i_retryCount - 1 <--- Causes False Result
            //
            // Expected result: FALSE
            //
            ++l_retryCount;
            l_retval = l_wrkaround->requestRetry(l_errl.get(),
                                                 l_retryCount,
                                                 DeviceFW::READ,
                                                 nullptr,
                                                 nullptr,
                                                 0,
                                                 0,
                                                 0
                                                );


            if(l_retval)
            {
                FAIL_IBSCOM_TEST("test_lbscom_retry: "
                                 "requestRetry unexpectedly returned true "
                                 "for reson code "
                                 "IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR and retry "
                                 "attempts %d. The requestRetry should not "
                                 "request more than one retry.",
                                 l_retryCount
                                );

                l_result = false;
                break;
            }

            l_retryCount = 0;
            l_errl.reset(new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                       ERRL_TEST_MOD_ID,
                                       l_reasonCodeForFalse,
                                       0,
                                       0,
                                       false
                                      )
                       );

            // Test 4
            // A non-nullptr error with reason code NOT
            // IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR and
            // Retry Count equal to 0.
            //
            // 1) errlHndl_t - Not Null and Reason Code is NOT <-- Causes False
            //                 IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR
            // 2) uint32_t i_retryCount - 0.
            //
            // Expected result: FALSE
            //
            l_retval = l_wrkaround->requestRetry(l_errl.get(),
                                                 l_retryCount,
                                                 DeviceFW::READ,
                                                 nullptr,
                                                 nullptr,
                                                 0,
                                                 0,
                                                 0
                                                );

            if(l_retval)
            {
                FAIL_IBSCOM_TEST("test_lbscom_retry: "
                                 "requestRetry unexpectedly returned true "
                                 "for reson code NOT equal to "
                                 "IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR. "
                                 "A retry should only happen if the reason "
                                 "code for the passed in error is equal to "
                                 "IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR."
                              );

                l_result = false;
                break;
            }

        }
        while(0);

        if(l_result)
        {
            SCOM_IBSCOM_TRACF("IbScomRetryTest: Test Passed!");
        }
        else
        {
            SCOM_IBSCOM_TRACF("IbScomRetryTest: Test Failed!");
        }
    }
};



#endif
