/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_getidec.H $ */
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
/// @file exp_getidec.H
/// @brief Contains function to lookup Chip ID and EC values of Explorer Chip
///
/// *HWP HWP Owner: Christian Geddes <crgeddes@us.ibm.com>
/// *HWP HWP Backup: <none>
/// *HWP Team: Hostboot
/// *HWP Level: 3
/// *HWP Consumed by: Hostboot / Cronus

#ifndef __EXP_GETIDEC_H_
#define __EXP_GETIDEC_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*exp_getidec_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        uint16_t&, uint8_t&);

extern "C"
{

///
/// @brief Lookup the Chip ID and EC level values for this explorer chip
/// @param[in]   i_target Explorer OCMB chip
/// @param[out]  o_chipId Explorer Chip ID
/// @param[out]  o_chipEc Explorer Chip EC
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode exp_getidec(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  uint16_t& o_chipId,
                                  uint8_t& o_chipEc);

} // extern "C"

#endif
