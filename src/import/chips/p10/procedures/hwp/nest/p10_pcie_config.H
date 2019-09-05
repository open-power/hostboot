/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_config.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
//------------------------------------------------------------------------------------
//
/// @file p10_pcie_config.H
/// @brief Initialize the PEC
///
/// *HWP HW Maintainer : Ricardo Mata Jr. (ricmata@us.ibm.com)
/// *HWP FW Maintainer : Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by   : HB
// ----------------------------------------------------------------------------------
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *! The purpose of this procedure is to initialize the PEC (PCI Express Controller).
// *!
// *! Successful operation assumes that:
// *!
// *! High-level procedure flow:
// *!
// *!
// *!---------------------------------------------------------------------------------

#ifndef _P10_PCIE_CONFIG_H_
#define _P10_PCIE_CONFIG_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pcie_config_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

extern "C" {

/// @brief Perform PCIE Phase2 init sequence
/// @param[in] i_target P10 chip target
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
//
    fapi2::ReturnCode p10_pcie_config(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
} //extern"C"

#endif //_P10_PCIE_CONFIG_H_
