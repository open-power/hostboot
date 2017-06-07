/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_htm_adu_ctrl.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file  p9_htm_adu_ctrl.H
///
/// @brief Provides ADU control functions that help with HTM collection actions.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 3
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

#ifndef _P9_HTM_ADU_CTRL_H_
#define _P9_HTM_ADU_CTRL_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
///
/// @brief Use ADU to globally trigger start/stop NHTM engines
///
/// @param[in] i_target        Reference to target
/// @param[in] i_addr          Address of PMISC command that should have
///                            the start/stop/pause bits set accordingly.
///
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode aduNHTMControl(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_addr);

#endif  // _P9_HTM_ADU_CTRL_H_
