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
