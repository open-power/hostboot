/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/adr32s_workarounds.H $ */
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

///
/// @file workarounds/adr32s_workarounds.H
/// @brief Workarounds for the ADR32s logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_ADR32S_H_
#define _MSS_WORKAROUNDS_ADR32S_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors_manual.H>

namespace mss
{

namespace workarounds
{

namespace adr32s
{

///
/// @brief Clears the FIRs mistakenly set by the DCD calibration
/// @param[in] i_target MCBIST target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
///
fapi2::ReturnCode clear_dcd_firs( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Perform ADR DCD calibration - Nimbus Only
/// @param[in] i_target the MCBIST (controler) to perform calibration on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode duty_cycle_distortion_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Retries to clear the cal update bit, as it has been seen that the bit can be "sticky" in hardware
/// @param[in] i_target MCA target on which to operate
/// @param[in] i_reg the register on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode setup_dll_control_regs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_reg );

} // close namespace adr32s
} // close namespace workarounds
} // close namespace mss

#endif
