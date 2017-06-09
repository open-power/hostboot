/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdSpareDramData.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file getMBvpdSpareDramData.H
/// @brief queries the MBvpd to determine spare DRAM availability
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef GETMBVPDSPAREDRAMDATA_H_
#define GETMBVPDSPAREDRAMDATA_H_

#include <fapi2.H>
#include <dimmConsts.H>

typedef fapi2::ReturnCode (*getMBvpdSpareDramData_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>&,
    uint8_t (&)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]
    [MAX_RANKS_PER_DIMM]);
extern "C"
{

///
/// @brief FW Team HWP that handles the ATTR_VPD_DIMM_SPARE attribute
/// by querying MBvpd to determine spare DRAM availability for C-DIMMs.
///
/// @note This HWP should be called through the VPD_DIMM_SPARE attribute.
/// @param[in]  i_mba       Reference to MBA Target.
/// @param[out] o_data      Reference to spare DRAM data.
/// @return ReturnCode
///
    fapi2::ReturnCode getMBvpdSpareDramData(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
        uint8_t (&o_data)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]
        [MAX_RANKS_PER_DIMM]);
}

#endif
