/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_omi_isolation.H $  */
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
/// @file p10_omi_isolation.H
/// @brief Isolate OMI failure to callout proc as needed
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HWSV
///-----------------------------------------------------------------------------
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <p10_io_tdr.H>

//------------------------------------------------------------------------------
// Consts
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
struct TdrStruct
{
    uint32_t  iv_lane;
    TdrResult iv_status;
    uint32_t  iv_length;
};

typedef fapi2::ReturnCode (*p10_omi_isolation_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>&,
    std::vector<TdrStruct>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Isolate OMI failure to callout proc as needed
///
/// @param[in]  i_omi_target    OMI target called out
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_omi_isolation(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
                                        std::vector<TdrStruct>& o_data);


} // extern "C"
