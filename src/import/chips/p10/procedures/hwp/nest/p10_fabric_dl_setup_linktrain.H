/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fabric_dl_setup_linktrain.H $ */
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
/// @file p10_fabric_dl_setup_linktrain.C
/// @brief Setup DL training
///-----------------------------------------------------------------------------
///
/// *HW HW Maintainer: Ben Gass <bgass@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///

#ifndef _P10_FABRIC_DL_SETUP_LINKTRAIN_H_
#define _P10_FABRIC_DL_SETUP_LINKTRAIN_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*p10_fabric_dl_setup_linktrain_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&);

extern "C"
{

///
/// @brief Setup IOHS fir mask and start DL training
///
/// @param[in] i_target Reference to IOHS endpoint target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_fabric_dl_setup_linktrain(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target);

} // extern "C"

#endif // _P10_FABRIC_DL_SETUP_LINKTRAIN_H_
