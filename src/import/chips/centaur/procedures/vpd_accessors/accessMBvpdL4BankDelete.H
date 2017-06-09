/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/accessMBvpdL4BankDelete.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
/// @file accessMBvpdL4BankDelete.H
/// @brief MBvpd accessor for the ATTR_CEN_L4_BANK_DELETE_VPD attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef _HWP_ACCESSMBVPDL4BANKDELETE_
#define _HWP_ACCESSMBVPDL4BANKDELETE_

#include <fapi2.H>

namespace fapi2
{

/// mode
enum MBvpdL4BankDeleteMode
{
    GET_L4_BANK_DELETE_MODE = 0,      ///< retrieve value from vpd
    SET_L4_BANK_DELETE_MODE = 1,      ///< update value in vpd
};
}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*accessMBvpdL4BankDelete_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&,
 uint32_t&,
 const fapi2::MBvpdL4BankDeleteMode);

extern "C"
{
///
/// @brief MBvpd accessor for the ATTR_L4_BANK_DELETE_VPD attribute
/// @param[in] i_mbTarget  - Reference to mb Target
/// @param[in,out] io_val  - retrived MX value or value to use to update MX vpd
/// @param[in] i_mode      - set or get mode
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode accessMBvpdL4BankDelete(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        uint32_t& io_val,
        const fapi2::MBvpdL4BankDeleteMode i_mode );
}

#endif
