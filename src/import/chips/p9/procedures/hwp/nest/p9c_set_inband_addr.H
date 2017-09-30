/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9c_set_inband_addr.H $ */
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
///
/// @file p9c_set_inband_addr.H
/// @brief configure Cumulus inband address
///
/// Set the inband base address in the MC
/// driven by attributes representing system memory map.
///

// *HWP HWP Owner: Yang Fan Liu shliuyf@cn.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB

#ifndef _P9C_SET_INBAND_ADDR_H_
#define _P9C_SET_INBAND_ADDR_H_


//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9c_set_inband_addr_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

extern "C" {

///
/// @brief configure Cumulus inband address
///
/// @param[in] i_target => Processor chip target
///
/// @return FAPI_RC_SUCCESS if the setup completes successfully, else error
//
    fapi2::ReturnCode p9c_set_inband_addr(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} //extern"C"

#endif //_P9C_SET_INBAND_ADDR_H_
