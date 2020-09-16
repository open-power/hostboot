/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/rcExpLog.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/**
 *  @file rcExpLog.C
 *  @brief Call fapi2::ReturnCode functions for explorer logs
 */
#include <cxxtest/TestSuite.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <hwp_error_info.H>
#include <hwp_ffdc_classes.H>

#include <rcExpLog.H>

fapi2::ReturnCode exp_error_rc(
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const uint32_t i_active_log_size,
    const uint32_t i_saved_log_size)
{
    FAPI_INF("Enter exp_error_rc (active %d, saved %d)...",
      i_active_log_size, i_saved_log_size);
/* TODO RTC:205128 - reenable after EKB update to interface
    FAPI_ASSERT(0, fapi2::COLLECT_EXPLORER_ERROR()
                   .set_OCMB_CHIP_TARGET(i_ocmb_target)
                   .set_EXP_ACTIVE_LOG_SIZE(i_active_log_size)
                   .set_EXP_SAVED_LOG_SIZE(i_saved_log_size),
                   "Testcase exp_error_rc assert");

fapi_try_exit:
*/
    FAPI_INF("Exiting exp_error_rc...");
    return fapi2::current_err;
}
