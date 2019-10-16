/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_adu_ctrl.H $ */
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
/// @file  p10_htm_adu_ctrl.H
///
/// @brief Provides ADU control functions that help with HTM collection actions.
///
/// ----------------------------------------------------------------------------
//
// *HWP HW Owner: Nicholas Landi <nlandi@ibm.com>
// *HWP FW Owner: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by: HB
//
/// ----------------------------------------------------------------------------

#ifndef _P10_HTM_ADU_CTRL_H_
#define _P10_HTM_ADU_CTRL_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
extern "C"
{
    // pMisc address constants
    const uint64_t PMISC_GLOBAL_HTM_MARK_DROPPED = 0x000000000080000ull;
    const uint64_t PMISC_GLOBAL_HTM_VALID        = 0x000000000040000ull;
    const uint64_t PMISC_GLOBAL_HTM_START        = 0x000000000020000ull;
    const uint64_t PMISC_GLOBAL_HTM_STOP         = 0x000000000010000ull;
    const uint64_t PMISC_GLOBAL_HTM_PAUSE        = 0x000000000008000ull;
    const uint64_t PMISC_GLOBAL_HTM_RESET        = 0x000000000004000ull;
} // extern "C"

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

#endif  // _P10_HTM_ADU_CTRL_H_
