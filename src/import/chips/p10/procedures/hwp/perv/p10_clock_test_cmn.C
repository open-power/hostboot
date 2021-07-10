/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_clock_test_cmn.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file  p10_clock_test_cmn.C
///
/// @brief Shared code for clock testing
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joachim Fenkes <fenkes@de.ibm.com>
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : SBE/HB/FSP
// EKB-Mirror-To: hw/ppe, hostboot, hwsv
//------------------------------------------------------------------------------

#include <p10_clock_test_cmn.H>

fapi2::ReturnCode p10_clock_test_check_error(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const uint8_t i_cp_refclock_select,
    const bool set_rcs_clock_test_in,
    const fapi2::buffer<uint32_t> i_sns1lth_value)
{
    /* Check that the output of the clock detection latch matches the input value
     * we just set - indicating that there is a clock present which makes the
     * latch transport its input to its output.
     */
    const bool clockA_functional = i_sns1lth_value.getBit<4>() == set_rcs_clock_test_in;
    const bool clockB_functional = i_sns1lth_value.getBit<5>() == set_rcs_clock_test_in;

    /* Find out for each clock whether it is required or merely optional
     * according to the refclock_select value.
     */
    const bool clockA_required = i_cp_refclock_select != fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC1 &&
                                 i_cp_refclock_select != fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_BOTH_OSC1_NORED;
    const bool clockB_required = i_cp_refclock_select != fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC0 &&
                                 i_cp_refclock_select != fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_BOTH_OSC0_NORED;

    const bool clockA_ok = clockA_functional || !clockA_required;
    const bool clockB_ok = clockB_functional || !clockB_required;

    const uint8_t callout_clock = clockA_ok ? fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC1 :
                                  fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC0;
    FAPI_ASSERT(clockA_ok && clockB_ok,
                fapi2::RCS_CLOCK_TEST_OUT_ERR()
                .set_MASTER_CHIP(i_target_chip)
                .set_READ_SNS1LTH(i_sns1lth_value)
                .set_ATTR_CP_REFCLOCK_SELECT_VALUE(i_cp_refclock_select)
                .set_RCS_CLOCK_TEST_IN(set_rcs_clock_test_in)
                .set_CLOCK_A_OK(clockA_ok)
                .set_CLOCK_B_OK(clockB_ok)
                .set_CLOCK_POS(callout_clock),
                "Bad reference clock: A functional/required: %d/%d  B functional/required: %d/%d",
                clockA_functional, clockA_required, clockB_functional, clockB_required
               );

fapi_try_exit:
    return fapi2::current_err;
}
