/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_utils.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p10_pcie_utils.H
/// @brief Common utility functions to support PCIE related HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///

#ifndef _P10_PCIE_UTILS_H_
#define _P10_PCIE_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
const uint8_t NUM_PHB_PER_PEC = 3;

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//

///
/// @brief Check attributes to determine if PHB target is enabled
/// @param[in]   i_target    Reference PHB target
/// @param[out]  o_enabled   True: PHB is enabled; False: PHB is disabled.
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode isPHBEnabled(const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
                               bool& o_enabled);

#endif //_P10_PCIE_UTILS_H_
