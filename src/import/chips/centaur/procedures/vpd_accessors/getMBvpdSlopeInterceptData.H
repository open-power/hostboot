/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdSlopeInterceptData.H $ */
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
///  @file getMBvpdSlopeInterceptData.H
///  @brief get master and supplier power slope and intercept from MBvpd
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef    _HWP_MBVPDSLOPEINTERCEPTDATA_
#define    _HWP_MBVPDSLOPEINTERCEPTDATA_

#include   <fapi2.H>

namespace fapi2
{

enum MBvpdSlopeIntercept
{
    MASTER_POWER_SLOPE =                0x00,
    MASTER_POWER_INTERCEPT =            0x01,
    SUPPLIER_POWER_SLOPE =              0x02,
    SUPPLIER_POWER_INTERCEPT =          0x03,
    MASTER_TOTAL_POWER_SLOPE =          0x04,
    MASTER_TOTAL_POWER_INTERCEPT =      0x05,
    SUPPLIER_TOTAL_POWER_SLOPE =        0x06,
    SUPPLIER_TOTAL_POWER_INTERCEPT =    0x07,
};
}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*getMBvpdSlopeInterceptData_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&, const fapi2::MBvpdSlopeIntercept,  uint32_t&);

extern "C"
{
///
/// @brief Return power slope and intercept data from cvpd record VSPD
///        keyword MW and MV
///
/// The Master power slope and intercept data is in the MW keyword.
/// The Supplier power slope and intercept data is in the MV keyword.
/// The #I keyword has the Module ID for this CDIMM. The MV keyword
///  has the supplier power slope and intercept for multiple vendors.
///  The list in MV is searched for the Module ID in the #I keyword.
///  Values for the matching vendor are returned.
///
/// @param[in]  i_mbTarget   -   membuf chip target
/// @param[in]  i_attr       -   enumerator to select requested value
/// @param[out] o_val        -   master/supplier slope/intercept value
/// @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success, relevant error code for failure.
///
///
    fapi2::ReturnCode getMBvpdSlopeInterceptData(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        const fapi2::MBvpdSlopeIntercept i_attr,
        uint32_t& o_val);

}

#endif
