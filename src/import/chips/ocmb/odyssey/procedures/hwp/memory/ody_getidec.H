/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_getidec.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/// @brief Contains function to lookup Chip ID and EC values of Odyssey Chip
///
/// *HWP HWP Owner: Thi Tran thi@us.ibm.com
/// *HWP HWP Backup: <none>
/// *HWP Team: VBU
/// *HWP Level: 2
/// *HWP Consumed by: Hostboot / Cronus

#ifndef _ODY_GETIDEC_H_
#define _ODY_GETIDEC_H_
#include <fapi2.H>

typedef fapi2::ReturnCode (*ody_getidec_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        uint16_t&, uint8_t&);

extern "C"
{

///
/// @brief Lookup the Chip ID and EC level values for this Odyssey chip
/// @param[in]   i_target     Reference to OCMB (Odyssey) chip target
/// @param[out]  o_chipId     Odyssey Chip ID
/// @param[out]  o_chipEc     Odyssey Chip EC
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode ody_getidec(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  uint16_t& o_chipId,
                                  uint8_t& o_chipEc);

} // extern "C"

#endif
