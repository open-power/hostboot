/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/rcSupport.C $                              */
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
//------------------------------------------------------------------------------
/// @file  rcSupport.C
///
/// @brief These procedures provide fapi2 return codes with desired data to
///        support testing from rcTest
//-----------------------------------------------------------------------------

#include <cxxtest/TestSuite.H>
#include <fapi2.H>
#include <rcSupport.H>
#include <plat_hwp_invoker.H>

#include <hwp_error_info.H>
#include <hwp_ffdc_classes.H>

const uint64_t FAPI2_TEST_BUFFER_VALUE = 0x123456789ABCDEF;
const uint32_t FAPI2_TEST_VARIABLE_BUFFER_VALUE[] =
                                                   {
                                                        0x12345678,
                                                        0x23456781,
                                                        0x34567812,
                                                        0x45678123,
                                                        0x56781234,
                                                        0x67812345,
                                                        0x78123456,
                                                        0x81234567,
                                                        0x9ABCDEF,
                                                        0xABCDEF9,
                                                        0xBCDEF9A,
                                                        0xCDEF9AB,
                                                        0xDEF9ABC
                                                   };
const uint32_t VARIABLE_BUFFER_ELEMENTS =
            sizeof(FAPI2_TEST_VARIABLE_BUFFER_VALUE)/
            sizeof(FAPI2_TEST_VARIABLE_BUFFER_VALUE[0]);


//******************************************************************************
// p9_ffdc_fail. Returns a fapi2::ReturnCode with an ffdc entry
//******************************************************************************
fapi2::ReturnCode p9_ffdc_fail(void)
{
    uint8_t thread_id = 4;
    FAPI_INF("Enter p9_ffdc_fail...");
    FAPI_ASSERT(false,
                fapi2::P9_RAM_THREAD_NOT_STOP_ERR()
                .set_THREAD(thread_id),
                "p9_ffdc_fail worked");
 fapi_try_exit:

    FAPI_INF("Exiting p9_ffdc_fail...");

    return fapi2::current_err;
}


//******************************************************************************
// p9_registerFfdc_fail.
// Returns a fapi2::ReturnCode with registery reads of a target
//******************************************************************************
fapi2::ReturnCode p9_registerFfdc_fail(
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target)
{
    FAPI_INF("Enter p9_registerFfdc_fail...");

    FAPI_ASSERT(0, fapi2::TEST_ERROR_A().set_TARGET(i_proc_target));

fapi_try_exit:

    FAPI_INF("Exiting p9_registerFfdc_fail...");
    return fapi2::current_err;
}


//******************************************************************************
// p9_procedureFfdc_fail.
// Cause a failure which calls a procedure that fills in some ffdc into the
// fapi2::ReturnCode
//******************************************************************************
fapi2::ReturnCode p9_procedureFfdc_fail()
{
    FAPI_INF("Enter p9_procedureFfdc_fail...");

    uint32_t pib = 0x0001;
    fapi2::ReturnCode l_rc;

    FAPI_ASSERT(0, fapi2::TEST_PROC_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED,
                                          l_rc).set_parm1(pib));

  fapi_try_exit:

    FAPI_INF("Exiting p9_procedureFfdc_fail...");

    return l_rc;
}


//******************************************************************************
// p9_gardAndDeconfig
// Force a test return code that deconfigures the target and gards it
//******************************************************************************
fapi2::ReturnCode p9_gardAndDeconfig(
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target)
{
    FAPI_INF("Enter p9_gardAndDeconfig...");

    FAPI_ASSERT(0, fapi2::TEST_ERROR_GARD_DECONFIG().set_TARGET(i_proc_target));

  fapi_try_exit:

    FAPI_INF("Exiting p9_gardAndDeconfig...");

    return fapi2::current_err;
}

//******************************************************************************
// p9_deconfig
// Force a test return code that deconfigures the target
//******************************************************************************
fapi2::ReturnCode p9_deconfigCallout(
    fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target)
{
    FAPI_INF("Enter p9_deconfigCallout...");

    FAPI_ASSERT(0, fapi2::TEST_ERROR_DECONFIG().set_TARGET(i_dimm_target));

  fapi_try_exit:

    FAPI_INF("Exiting p9_deconfigCallout...");

    return fapi2::current_err;
}

//******************************************************************************
// p9_deconfig_callout_none
// Force a test return code that deconfigures the target
//******************************************************************************
fapi2::ReturnCode p9_deconfigCalloutNone(
    fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target)
{
    FAPI_INF("Enter p9_deconfigCalloutNone...");

    FAPI_ASSERT(0,
            fapi2::TEST_ERROR_DECONFIG_NO_CALLOUT().set_TARGET(i_dimm_target));

  fapi_try_exit:

    FAPI_INF("Exiting p9_deconfigCalloutNone...");

    return fapi2::current_err;
}

//******************************************************************************
// p9_procedureCallout
// Force a test return code that creates a procedure callout
//******************************************************************************
fapi2::ReturnCode p9_procedureCallout()
{
    FAPI_INF("Enter p9_procedureCallout...");

    FAPI_ASSERT(0, fapi2::TEST_ERROR_PROCEDURE_CALLOUT());

  fapi_try_exit:

    FAPI_INF("Exiting p9_procedureCallout...");

    return fapi2::current_err;
}

//******************************************************************************
// p9_hwCallout
// Force a test return code that creates a hw callout
//******************************************************************************
fapi2::ReturnCode p9_hwCallout(
    fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target)
{
    FAPI_INF("Enter p9_hwCallout...");

    FAPI_ASSERT(0, fapi2::TEST_ERROR_HW_CALLOUT().set_TARGET(i_core_target));

  fapi_try_exit:

    FAPI_INF("Exiting p9_hwCallout...");

    return fapi2::current_err;
}


//****************************************************************************
// p9ErrorWithBuffer
// Force an error that will use a caller populated fapi2::buffer<>
//****************************************************************************
fapi2::ReturnCode p9ErrorWithBuffer(
                    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Entering p9ErrorWithBuffer");

    fapi2::buffer<uint64_t> l_userBuffer{FAPI2_TEST_BUFFER_VALUE};

    //Parameter type for the p9_collect_some_ffdc function.
    //Can be 0x01 or 0x02. Has relevence for ErrorInfo objects
    //not related to this test.
    uint32_t l_paramValue = 0x01;

    fapi2::current_err = fapi2::FAPI2_RC_INVALID_PARAMETER;

    FAPI_ASSERT(false,
                fapi2::PROC_EXAMPLE_ERROR().set_BUFFER(l_userBuffer)
                                    .set_parm1(l_paramValue)
                                    .set_UNIT_TEST_CHIP_TARGET(i_target),
                "p9ErrorWithBuffer Unit Test"
               );

fapi_try_exit:
    FAPI_INF("Exiting p9ErrorWithBuffer");
    return fapi2::current_err;
}

//****************************************************************************
// p9ErrorWithVariableBuffer
// Force an error that will use a caller populated fapi2::variable_buffer
//****************************************************************************
fapi2::ReturnCode p9ErrorWithVariableBuffer(
                    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Entering p9ErrorWithVariableBuffer");

    fapi2::variable_buffer l_userBuffer(FAPI2_TEST_VARIABLE_BUFFER_VALUE,
                                        VARIABLE_BUFFER_ELEMENTS,
                                        VARIABLE_BUFFER_ELEMENTS*32
                                        );

    //Parameter type for the p9_collect_some_ffdc function.
    //Can be 0x01 or 0x02. Has relevence for ErrorInfo objects
    //not related to this test
    uint32_t l_paramValue = 0x01;

    fapi2::current_err = fapi2::FAPI2_RC_INVALID_PARAMETER;

    FAPI_ASSERT(false,
                fapi2::PROC_EXAMPLE_ERROR().set_BUFFER(l_userBuffer)
                                    .set_parm1(l_paramValue)
                                    .set_UNIT_TEST_CHIP_TARGET(i_target),
                "p9ErrorWithVariableBuffer Unit Test"
               );

fapi_try_exit:
    FAPI_INF("Exiting p9ErrorWithVariableBuffer");
    return fapi2::current_err;
}


