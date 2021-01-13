/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_clock_test_cmn.H $ */
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
/// @file  p10_clock_test_cmn.H
///
/// @brief Shared code for clock testing
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joachim Fenkes <fenkes@de.ibm.com>
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : SBE/HB/FSP
// EKB-Mirror-To: hw/ppe, hostboot, hwsv
//------------------------------------------------------------------------------

#ifndef _P10_CLOCK_TEST_CMN_H_
#define _P10_CLOCK_TEST_CMN_H_

#include <fapi2.H>

/**
 * @brief Common clock test check for proc_clock_test and proc_sbe_rcs_setup
 *
 * Check the results of a single clock test iteration according to the specified
 * refclock selection, raise a FAPI error with FFDC if the check fails.
 *
 * @param[in] i_target_chip         Target chip to call out in FFDC in case of failure
 * @param[in] i_cp_refclock_select  Value of ATTR_CP_REFCLOCK_SELECT
 * @param[in] set_rcs_clock_test_in Bit value to expect in the clock test latches
 * @param[in] i_sns1lth_value       Raw sense value read out of SNS1LTH
 *
 * @return FAPI2_RC_SUCCESS if no error was detected
 *         FAPI2_RC_RCS_CLOCK_TEST_OUT_ERR if a required clock failed the test
 */
fapi2::ReturnCode p10_clock_test_check_error(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const uint8_t i_cp_refclock_select,
    const bool set_rcs_clock_test_in,
    const fapi2::buffer<uint32_t> i_sns1lth_value);

#endif
