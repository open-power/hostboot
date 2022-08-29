/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_byte_swizzle_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file exp_byte_swizzle_workarounds.H
/// @brief Workarounds for explorer byte swizzle
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup:  Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef _EXP_BYTE_SWIZZLE_WORKAROUNDS_H_
#define _EXP_BYTE_SWIZZLE_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Swizzles from the MCBIST to the DFI byte perspectives
/// @param[in] i_mcbist_byte the byte number in the MCBIST perspective
/// @return the byte number in the DFI perspective
///
uint8_t mcbist_to_dfi_byte_swizzle(const uint8_t i_mcbist_byte);

} // workarounds
} // exp
} // mss

#endif
