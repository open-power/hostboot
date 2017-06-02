/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2HwpErrorBufferTest.H $                */
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
#ifndef __FAPI2_TEST_FAPI2HWPERRORBUFFERTEST_H
#define __FAPI2_TEST_FAPI2HWPERRORBUFFERTEST_H

#include <cxxtest/TestSuite.H>
#include "rcSupport.H"

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <error_info.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <targeting/common/targetservice.H>

#include <hwp_error_info.H>
#include <hwp_ffdc_classes.H>

namespace fapi2
{

class Fapi2HwpErrorBufferTest:public CxxTest::TestSuite
{

public:

    //Test that caller supplied error data is collected for Error Handling
    //by the FAPI_ASSERT macro when called with the PROC_EXAMPLE_ERROR
    //generated class. The FAPI_ASSERT macro does not commit information
    //to the error log
    //-----------------------------------------------------------------
    void testU64BufferAddedToHwpErrorNoLog()
    {
        //setup enter and exit messages
        FAPI_INF("Entering testU64BufferAddedToHwpErrorNoLog");

        int l_result = -1;

        do
        {
            //Setup buffer for caller supplied information.
            fapi2::buffer<uint64_t> l_userBuffer{FAPI2_TEST_BUFFER_VALUE};

            //Parameter type for the p9_collect_some_ffdc function.
            //Can be 0x01 or 0x02. Has relevence for ErrorInfo objects
            //not related to this test
            uint32_t l_paramValue = 0x01;

            //Setup return code values
            fapi2::ReturnCode l_rc{FAPI2_RC_INVALID_PARAMETER};
            fapi2::errlSeverity_t l_sev = FAPI2_ERRL_SEV_UNRECOVERABLE;

            //get a PROC target for this test.
            TARGETING::Target *l_procTarget = getProcTarget();

            if(!l_procTarget)
            {
                TS_FAIL("Unable to get a Proc target for test.");
                l_result=1;
                break;
            }

            Target<TARGET_TYPE_PROC_CHIP> l_testTarget{l_procTarget};

            //Create error class and do FAPI_ASSERT.
            //The FAPI_ASSERT will collect error data but will
            //not commit the data to the error log.
            PROC_EXAMPLE_ERROR l_testError{l_sev, l_rc};

            FAPI_ASSERT(false,
                        l_testError.set_BUFFER(l_userBuffer)
                                   .set_parm1(l_paramValue)
                                   .set_UNIT_TEST_CHIP_TARGET(l_testTarget),
                        "testU64BufferAddedToHwpErrorNoLog Unit Test"
                        );

//Label required by the FAPI_ASSERT Macro
fapi_try_exit:

            //check results

            //Since the error data was not logged, no errlHandl_t pointer
            //should have been placed in the ReturnCode object.
            if(nullptr != l_rc.getPlatDataPtr())
            {
                TS_FAIL("l_rc contains a non-null platform pointer.");
                l_result = 2;
                break;
            }
            FAPI_INF("l_rc did not contain a errlHndl_t pointer (expected)");


            //The caller suppiled buffer should not have been modified.
            if(nullptr == l_testError.BUFFER.ptr())
            {
                TS_FAIL("l_testError.BUFFER.ptr was set to NULL during test!");
                l_result = 3;
                break;
            }

            //Ensure that the BUFFER object contains the same value.
            if(FAPI2_TEST_BUFFER_VALUE !=
                *(reinterpret_cast<const uint64_t*>(l_testError.BUFFER.ptr())))
            {
                FAPI_INF("l_testError.BUFFER.ptr() contains the value %X",
                 *(reinterpret_cast<const uint64_t*>(l_testError.BUFFER.ptr()))
                        );
                TS_FAIL("l_testError.BUFFER data was changed during the test");
                l_result = 4;
                break;
            }
            FAPI_INF("BUFFER data was not modified during test (expected)");

            //Check that ErrorInfo was generated during the FAPI_ASSERT call.
            if(nullptr == l_rc.getErrorInfo())
            {
                TS_FAIL("Did not generate ErrorInfo data during test!");
                l_result = 5;
                break;
            }
            else if(l_rc.getErrorInfo()->iv_ffdcs.empty())
            {
                TS_FAIL("Did not generate ErrorInfoFFDC data during test!");
                l_result = 6;
                break;
            }
            else
            {
                FAPI_INF("Test Generated ErrorInfoFFDC data (expected)");
            }

            //The processing for the fapi2::PROC_EXAMPLE_ERROR class will
            //place an ErrorInfoFfdc object representing the BUFFER data as the
            //last ErrorInfoFfdc obect in a vector of ErrorInfoFfdc's in
            //the ReturnCode.
            const std::shared_ptr<ErrorInfoFfdc>& l_lastFFDC =
                                        l_rc.getErrorInfo()->iv_ffdcs.back();

            if(!l_lastFFDC)
            {
                TS_FAIL("ErrorInfoFfdc pointer "
                        "returned from last FFDC is NULL.");
                l_result = 7;
                break;
            }

            //Check that the last ErrorInfoFfdc's ffdc id is as expected
            FAPI_INF("Checking that last ErrorInfoFFDC ffdcid has value %X",
                     RC_PROC_EXAMPLE_ERROR_BUFFER);

            if(RC_PROC_EXAMPLE_ERROR_BUFFER != l_lastFFDC->getFfdcId())
            {
                FAPI_ERR("Last ErrorInfoFFDC ffdcid actual value %X, "
                         "expected value %X",
                         l_lastFFDC->getFfdcId(),
                         RC_PROC_EXAMPLE_ERROR_BUFFER
                        );
                TS_FAIL("ErrorInfoFFDC ffdc id does not match expected value "
                         "fapi2::RC_PROC_EXAMPLE_ERROR_BUFFER."
                       );
                l_result = 8;
                break;
            }

            FAPI_INF("Last ErrorInfoFFDC ffdcid was equal to %X (expected)",
                     l_lastFFDC->getFfdcId());

            //Check that the last ErrorInfoFfdc data and size
            //match fapi2::PROC_EXAMPLE_ERROR::BUFFER
            uint32_t l_ffdc_data_size{};
            const void* l_ffdc_data = l_lastFFDC->getData(l_ffdc_data_size);

            if(nullptr == l_ffdc_data)
            {
                TS_FAIL("ErrorInfoFFDC buffer is NULL");
                l_result = 9;
                break;
            }

            if(l_ffdc_data_size != getErrorInfoFfdcSize(l_testError.BUFFER))
            {
                FAPI_ERR("ErrorInfoFFDC size: %X, l_testError.BUFFER size: %X",
                         l_ffdc_data_size,
                         getErrorInfoFfdcSize(l_testError.BUFFER)
                        );
                TS_FAIL("ErrorInfoFFDC size does not match BUFFER size");
                l_result = 10;
                break;
            }

            FAPI_INF("ErrorInfoFFDC buffer vlaue: %X, "
                     "PROC_EXAMPLE_ERROR::BUFFER: %X",
                     *(reinterpret_cast<const uint64_t*>(l_ffdc_data)),
                 *(reinterpret_cast<const uint64_t*>(l_testError.BUFFER.ptr()))
                    );

            if(*(reinterpret_cast<const uint64_t*>(l_ffdc_data)) !=
               *(reinterpret_cast<const uint64_t*>(l_testError.BUFFER.ptr())))
            {
               TS_FAIL("ErrorInfoFFDC buffer value does not match"
                        " fapi2::PROC_EXAMPLE_ERROR::BUFFER.");
                l_result = 11;
                break;
            }

            //Test passed. Log information
            FAPI_INF("Last ErrorInfoFFDC data matches BUFFER passed to "
                     "the test PROC_EXAMPLE_ERROR object. (expected)"
                     "Data value: %X, FFDC id: %X",
                      *(reinterpret_cast<const uint64_t*>(l_ffdc_data)),
                      l_lastFFDC->getFfdcId()
                    );

            l_result = 0;

        }
        while(0);

        FAPI_INF("Exiting "
                "testU64BufferAddedToHwpErrorNoLog "
                 "Result (%d) - %s",
                 l_result,
                 (0x00 == l_result)?"Passed":"Failed"
                );
    }

    //Test that caller supplied Error information (fapi::buffer<>)
    //is propagated to the error log through a call to FAPI_INVOKE_HWP
    //-----------------------------------------------------------------------
    void testU64BufferAddedToInvokeHWPError()
    {
        FAPI_INF("Entering testU64BufferAddedToInvokeHWPError");

        int l_result = -1;

        //prepare test data

        do
        {
            //get a PROC target for this test.
            TARGETING::Target *l_procTarget = getProcTarget();

            if(!l_procTarget)
            {
                TS_FAIL("Unable to get a Proc target for test.");
                l_result=1;
                break;
            }

            Target<TARGET_TYPE_PROC_CHIP> l_testTarget{l_procTarget};

            errlHndl_t l_err{};

            //invoke the simulated hardware function.
            FAPI_INVOKE_HWP(l_err, p9ErrorWithBuffer, l_testTarget);

            if(!l_err)
            {
                TS_FAIL("FAPI_INVOKE_HWP did not return error information.");
                l_result = 2;
                break;
            }

            //Find the caller supplied information in the error log.
            bool l_found_ud_section{false};

            std::vector<void*> ud_sections =
                l_err->getUDSections(HWPF_COMP_ID, HWPF_FAPI2_UDT_HWP_FFDC);

            if(ud_sections.empty())
            {
                TS_FAIL("err_ptr->getUDSections did not return any data.");
                l_result = 3;
                break;
            }

            FAPI_INF("err_ptr->getUDSections returned %d sections",
                     ud_sections.size());

            //The buffer we are looking for has the following format:
            // |-- fapi2::RC_PROC_EXAMPLE_ERROR_BUFFER uint32_t --|
            // | -- uint64_t (BUFFER val) --|
            for(const void* ptr: ud_sections)
            {
                if(ptr)
                {
                    const char* l_ptrBuf = reinterpret_cast<const char*>(ptr);
                    uint32_t l_u32val{};

                    //copy data to ensure alignment
                    memcpy(&l_u32val, l_ptrBuf, sizeof(l_u32val));
                    if(RC_PROC_EXAMPLE_ERROR_BUFFER == l_u32val)
                    {
                        l_ptrBuf += sizeof(l_u32val);
                        uint64_t l_u64val{};
                        memcpy(&l_u64val, l_ptrBuf, sizeof(l_u64val));
                        if(FAPI2_TEST_BUFFER_VALUE == l_u64val)
                        {
                            l_found_ud_section = true;
                            FAPI_INF("Found UD section with expected values. "
                                     "ffdc id: %X, "
                                     "user data: %X",
                                     l_u32val,
                                     l_u64val
                                    );
                            break;
                        }
                    }
                }
            }

            if(!l_found_ud_section)
            {
                TS_FAIL("Did not find the error log UD section that contained "
                        "caller suppiled buffer.");
                l_result = 4;
                break;
            }

            //Test data is in the log, now commit the error log.
            errlCommit(l_err, HWPF_COMP_ID);

            if(l_err)
            {
                delete l_err;
                l_err = nullptr;

                TS_FAIL("Failed to commit error log!");
                l_result = 5;
                break;
            }

            l_result = 0;
        }
        while(0);

        FAPI_INF("Exiting "
                 "testU64BufferAddedToInvokeHWPError "
                 "Result (%d) - %s",
                 l_result,
                 (0x00 == l_result)?"Passed":"Failed");
    }


    //Test that caller supplied Error information (fapi2::buffer_variable)
    //is propagated to the Error Log through a call to FAPI_INVOKE_HWP
    //-----------------------------------------------------------------------
    void testVariableBufferAddedToInvokeHWPError()
    {
        FAPI_INF("Entering testVariableBufferAddedToInvokeHWPError");

        int l_result = -1;

//The generated classes in hwp_ffdc_classes.H are not produced to support
//fapi2::variable_buffer.In order to enable the following test the
//parseErrorInfo.pl script must be configured to use variable buffers.
//To enable variable buffer support ensure that the parseErrorInfo_RUN
//macro in import/hwpf/fapi2/tools/parseErrorInfo.mk is defined to
//include the --use-variable-buffers option as shown below.
//$(C1) $$< --use-variable-buffers --output-dir=$$($(GENERATED)_PATH) ...

//Disable unless parseErrorInfo.pl --use-variable-buffers invoked to
//generate hwp_ffdc_classes.H.

        do
        {
#if 0
            //get a PROC target for this test.
            TARGETING::Target *l_procTarget = getProcTarget();

            if(!l_procTarget)
            {
                TS_FAIL("Unable to get a Proc target for test.");
                l_result=1;
                break;
            }

            Target<TARGET_TYPE_PROC_CHIP> l_testTarget{l_procTarget};

            errlHndl_t l_err{};
            //Call the simulated hardware function to generate an error.
            FAPI_INVOKE_HWP(l_err,
                            p9ErrorWithVariableBuffer,
                            l_testTarget
                           );

            if(!l_err)
            {
                TS_FAIL("FAPI_INVOKE_HWP did not return error information.");
                l_result = 2;
                break;
            }

            //Find the caller supplied information in the error log.
            bool l_found_ud_section{false};

            std::vector<void*> ud_sections =
                l_err->getUDSections(HWPF_COMP_ID, HWPF_FAPI2_UDT_HWP_FFDC);

            if(ud_sections.empty())
            {
                TS_FAIL("err_ptr->getUDSections did not return any data.");
                l_result = 3;
                break;
            }

            FAPI_INF("err_ptr->getUDSections returned %d sections",
                     ud_sections.size());

            //The buffer we are looking for has the following format:
            // |-- fapi2::RC_PROC_EXAMPLE_ERROR_BUFFER uint32_t --|
            // | -- uint32_t (BUFFER val[0])--|
            // | -- uint32_t (BUFFER val[1])--|
            //  .....
            for(const void* ptr: ud_sections)
            {
                if(ptr)
                {
                    const char* l_ptrBuffer =
                                        reinterpret_cast<const char*>(ptr);
                    uint32_t l_u32val{};
                    memcpy(&l_u32val, l_ptrBuffer, sizeof(l_u32val));
                    int l_hitCount{};
                    if(RC_PROC_EXAMPLE_ERROR_BUFFER == l_u32val)
                    {
                        for(unsigned int i=0;
                                i < VARIABLE_BUFFER_ELEMENTS; ++i)
                        {
                            l_ptrBuffer += sizeof(l_u32val);
                            memcpy(&l_u32val, l_ptrBuffer, sizeof(l_u32val));
                            if(FAPI2_TEST_VARIABLE_BUFFER_VALUE[i] == l_u32val)
                            {
                                ++l_hitCount;
                            }
                            else
                            {
                                break;
                            }
                        }

                        //print buffer values for information.
                        if(VARIABLE_BUFFER_ELEMENTS ==
                                        static_cast<uint32_t>(l_hitCount))
                        {
                            int l_remain{};
                            int l_ct{};
                            char l_infoString[256] = {0};
                            char* l_ptr = l_infoString;

                            l_found_ud_section = true;
                            l_remain = static_cast<int>(sizeof(l_infoString));
                            l_ct = snprintf(
                                       l_ptr,
                                       l_remain,
                                       "Found UD section with expected values."
                                       " ffdc id: %X ",
                                       RC_PROC_EXAMPLE_ERROR_BUFFER
                                          );

                            for(int i = 0; i < l_hitCount; ++i)
                            {
                                if(l_ct > 0 && l_ct < l_remain)
                                {
                                    l_remain -= l_ct;

                                    if(l_remain <= 0)
                                    {
                                        break;
                                    }

                                    l_ptr += l_ct;
                                    l_ct = snprintf(
                                              l_ptr,
                                              l_remain,
                                              ", Data[%d]: %X ",
                                              i,
                                            FAPI2_TEST_VARIABLE_BUFFER_VALUE[i]
                                             );
                                }
                                else
                                {
                                    break;
                                }
                            }

                            FAPI_INF("%s", l_infoString);

                            //found our user data section.
                            break;
                        }
                    }
                }
            }

            if(!l_found_ud_section)
            {
                TS_FAIL("Did not find the error log UD section that contained "
                        "caller suppiled buffer."
                        );
                l_result = 4;
                break;
            }

            //test data was in the log, commit error log.
            errlCommit(l_err, HWPF_COMP_ID);

            if(l_err)
            {
                delete l_err;
                l_err = nullptr;

                TS_FAIL("Failed to commit error log!");
                l_result = 5;
                break;
            }

#endif
            l_result = 0;

        }
        while(0);

        FAPI_INF("Exiting "
         "testVariableBufferAddedToInvokeHWPError"
         "Result (%d) - %s",
         l_result,
         (0x00 == l_result)?"Passed":"Failed");
    }

private:
    TARGETING::Target * iv_procTarget = nullptr;

    //cache a proc chip for all the tests
    TARGETING::Target* getProcTarget()
    {
        if(!iv_procTarget)
        {
            TARGETING::TargetHandleList l_targetList;
            TARGETING::getAllChips(l_targetList, TARGETING::TYPE_PROC, false);

            if(l_targetList.empty())
            {
                FAPI_ERR("Unable to get a Proc target for test.");
            }
            else
            {
                FAPI_INF("getAllChips returned %X processor chips.",
                                                l_targetList.size());
                iv_procTarget = l_targetList[0];
            }
        }

        return iv_procTarget;
    }
};

}

//CxxTest does not use the enclosing namespace for a test class.
//Place this here in case we are the first or only unit test.
//If no unit test defines the namespace declaration CxxTest
//runner will fail to compile.
using namespace fapi2;

#endif
