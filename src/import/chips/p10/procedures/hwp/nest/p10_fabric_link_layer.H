/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fabric_link_layer.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_fabric_link_layer.H
/// @brief Start SMP link layer (FAPI2)
///
/// Train fabric Data Link Layer (DLL) and Transaction Layer (TL).
///
/// High level sequence:
/// - HWP engages DLL training via SCOM.
/// - HW fires DLL link up FIR bit when finished.
/// - Link up FIR bit launches TL training, in HW.
/// - HW fires TL training done FIR bit when finished.
///   Mailbox registers should be accessible for HWP/FW use.
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB,FSP
///

#ifndef _P10_SMP_LINK_LAYER_H_
#define _P10_SMP_LINK_LAYER_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_fabric_link_layer_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const bool,
    const bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Train fabric DLL/TL layers
///
/// @param[in] i_target             Reference to processor chip target
/// @param[in] i_train_intranode    Train intranode links (X)?
/// @param[in] i_train_internode    Train internode links (X,A)?
///
/// @return fapi::ReturnCode        FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fabric_link_layer(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_train_intranode,
        const bool i_train_internode);

} // extern "C"

#endif // _P10_SMP_LINK_LAYER_H_
