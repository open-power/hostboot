/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_fir_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2025                             */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_fir_workarounds.H
/// @brief Workarounds for Odyssey FIR related issues
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _ODY_FIR_WORKAROUNDS_H_
#define _ODY_FIR_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace ody
{
namespace fir
{
namespace workarounds
{

///
/// @brief Mask SRQ0_SM_1HOT_ERR
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_unmasked will be set to TRUE if either of the FIR bits were initially unmasked
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note this avoids unnecessary checkstop caused by state machine glitches
/// during scominit and standalone CCS at high memory frequency
///
fapi2::ReturnCode mask_srq_one_hot( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    bool& o_unmasked );

///
/// @brief Clear and Re-unmask SRQ0_SM_1HOT_ERR
/// @param[in] i_target the fapi2::Target
/// @param[in] i_unmasked set to TRUE if either of the FIR bits were initially unmasked
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note this avoids unnecessary checkstop caused by state machine glitches
/// during scominit and standalone CCS at high memory frequency
///
fapi2::ReturnCode clear_and_unmask_srq_one_hot( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const bool i_unmasked );

} // ns workarounds
} // ns fir
} // ns ody
} // ns mss

#endif
