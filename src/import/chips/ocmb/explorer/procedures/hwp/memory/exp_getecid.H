/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_getecid.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_getecid.H
/// @brief Contains the explorer ECID setup
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef __EXP_GETECID_H_
#define __EXP_GETECID_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*exp_getecid_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{

///
/// @brief getecid procedure for explorer chip
/// @param[in] i_target Explorer OCMB chip
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code.
/// @note Sets ocmb_ecid, enterprise, half-dimm mode attributes. exp_omi_setup configures the chip with these attributes
///
    fapi2::ReturnCode exp_getecid(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // extern "C"

#endif
