/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_xgpe_init.H $   */
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
/// @file  p10_pm_xgpe_init.H
/// @brief Initialize the XGPE GPE (gpe3) Engine in the OCC
///
// *HWP HWP Owner           :   Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *HWP Backup Owner        :   Rahul Batra <rbatra@us.ibm.com>
// *HWP FW Owner            :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team                :   PM
// *HWP Level               :   3
// *HWP Consumed by         :   HS
///
/// High-level procedure flow:
/// @verbatim
///   if PM_HALT
///   - Halt the XGPE
///   if PM_START
///   - Read the XGPE IVPR value, the address of boot copier in HOMER region.
///   - clear OCC Scratch3 flag indicating HCode init completion.
///   - Write to XCR to activate the XGPE
///   - Poll OCC Scratch 3 flag for HCode init completion
///   - Call p10_pm_pba_init in PM_INIT mode to activate the PBA channels for
///     runtime configuration.
/// @endverbatim

#ifndef _P10_XGPEINIT_H_
#define _P10_XGPEINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pm.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_xgpe_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const pm::PM_FLOW_MODE);

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------
extern "C" {

/// @addtogroup pm_fapi
/// @{

/// @brief Initialize the XGPE GPE Engine in the OCC
///
/// @param [in] i_target    Chip target
/// @param [in] i_mode      Control mode PM_INIT, PM_RESET
///
/// @retval FAPI2_RC_SUCCESS on success, else error RC
///
    fapi2::ReturnCode p10_pm_xgpe_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const pm::PM_FLOW_MODE i_mode);

/// @}  end addtogroup

} // extern "C"

#endif // _P10_XGPEINIT_H_
