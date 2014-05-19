/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/accessMBvpdL4BankDelete.H $ */
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
// $Id: accessMBvpdL4BankDelete.H,v 1.2 2013/11/21 17:17:30 whs Exp $
/**
 *  @file accessMBvpdL4BankDelete.H
 *
 *  @brief MBvpd accessor for the ATTR_L4_BANK_DELETE_VPD attribute
 */

#ifndef _HWP_ACCESSMBVPDL4BANKDELETE_
#define _HWP_ACCESSMBVPDL4BANKDELETE_

#include <fapi.H>

namespace fapi
{

// mode
    enum MBvpdL4BankDeleteMode
    {
        GET_L4_BANK_DELETE_MODE = 0,      // retrieve value from vpd
        SET_L4_BANK_DELETE_MODE = 1,      // update value in vpd
    };
}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*accessMBvpdL4BankDelete_FP_t)
    (const fapi::Target &,
     uint32_t &,
     const fapi::MBvpdL4BankDeleteMode);

extern "C"
{
/**
 * @brief MBvpd accessor for the ATTR_L4_BANK_DELETE_VPD attribute
 *
 * Access L4 Bank Delete value in MBvpd record VSPD keyword MX.
 *
 * @param[in] i_mbTarget  - Reference to mb Target
 * @param[in,out] io_val  - retrived MX value or value to use to update MX vpd
 * @param[in] i_mode      - set or get mode
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode accessMBvpdL4BankDelete(
    const fapi::Target & i_mbTarget,
    uint32_t & io_val,
    const fapi::MBvpdL4BankDeleteMode i_mode );
}

#endif
