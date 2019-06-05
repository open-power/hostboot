/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fabric_dl_pre_trainadv.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_fabric_dl_pre_trainadv.C
/// @brief Stub HWP for pre-training overrides/IO characterization (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

///
/// *HW HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fabric_dl_pre_trainadv.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_fabric_dl_pre_trainadv(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_targetA,
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_targetB)
{
    FAPI_DBG("Start");
    FAPI_DBG("End");
    return fapi2::FAPI2_RC_SUCCESS;
}
