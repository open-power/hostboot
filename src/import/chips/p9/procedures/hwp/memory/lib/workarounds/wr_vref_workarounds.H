/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/wr_vref_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

///
/// @file wr_vref_workarounds.H
/// @brief Workarounds for the WR VREF calibration logic
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_WR_VREF_H_
#define _MSS_WORKAROUNDS_WR_VREF_H_

#include <fapi2.H>

namespace mss
{

namespace workarounds
{

namespace wr_vref
{

///
/// @brief Executes WR VREF workarounds
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to execute the override on
/// @param[in] i_cal_steps_enabled - cal steps to exectue, used to see if WR VREF needs to be exectued
/// @param[out] o_vrefdq_train_range - training range value
/// @param[out] o_vrefdq_train_value - training value value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
// TODO RTC:166422 update training code to set cal step enable and consume it everywhere locally
fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                           const uint64_t i_rp,
                           const fapi2::buffer<uint16_t>& i_cal_steps_enabled,
                           uint8_t& o_vrefdq_train_range,
                           uint8_t& o_vrefdq_train_value );

} // close namespace wr_vref
} // close namespace workarounds
} // close namespace mss

#endif
