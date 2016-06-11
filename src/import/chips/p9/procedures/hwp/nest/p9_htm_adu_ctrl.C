/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_htm_adu_ctrl.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// ----------------------------------------------------------------------------
/// @file  p9_htm_adu_ctrl.C
///
/// @brief Provides ADU control functions that help with HTM collection actions.
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_htm_adu_ctrl.H>
#include <p9_adu_coherent_utils.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
const uint32_t P9_HTM_START_MAX_STATUS_POLLS = 100;  // Status time-out

///
/// See doxygen in p9_htm_adu_ctrl.H
///
fapi2::ReturnCode aduNHTMControl(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_addr)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    FAPI_DBG("Exiting");
    return fapi2::current_err;
}
