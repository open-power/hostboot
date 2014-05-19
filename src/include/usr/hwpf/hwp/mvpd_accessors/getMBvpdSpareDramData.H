/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdSpareDramData.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getMBvpdSpareDramData.H,v 1.2 2013/10/03 20:40:52 dedahle Exp $
#ifndef GETMBVPDSPAREDRAMDATA_H_
#define GETMBVPDSPAREDRAMDATA_H_

#include <fapi.H>
#include <dimmConsts.H>

typedef fapi::ReturnCode (*getMBvpdSpareDramData_FP_t)(
    const fapi::Target &,
    uint8_t (&)[DIMM_DQ_MAX_MBA_PORTS][DIMM_DQ_MAX_MBAPORT_DIMMS]
                                         [DIMM_DQ_MAX_DIMM_RANKS]);
extern "C"
{

/**
 * @brief FW Team HWP that handles the ATTR_VPD_DIMM_SPARE attribute
 * by querying MBvpd to determine spare DRAM availability for C-DIMMs.
 *
 * This HWP should be called through the VPD_DIMM_SPARE attribute.
 *
 * @param[in]  i_mba       Reference to MBA Target.
 * @param[out] o_data      Reference to spare DRAM data.
 *
 * @return ReturnCode
 */
fapi::ReturnCode getMBvpdSpareDramData(
    const fapi::Target & i_mba,
    uint8_t (&o_data)[DIMM_DQ_MAX_MBA_PORTS][DIMM_DQ_MAX_MBAPORT_DIMMS]
                                               [DIMM_DQ_MAX_DIMM_RANKS]);
}

#endif
