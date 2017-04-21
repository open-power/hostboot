/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_cen_framelock.H $  */
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
/// @file p9_cen_framelock.C
/// @brief Enable transmission of the logical protocol (frame) layer over the DMI link(FAPI2)
///
/// @author Jin Song Jiang <jjsjiang@cn.ibm.com>
///

//
// *HWP HWP Owner: Jin Song Jiang <jjsjiang@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 3
// *HWP Consumed by: HB,FSP
//

#ifndef _P9_CEN_FRAMELOCK_H_
#define _P9_CEN_FRAMELOCK_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// enum to represent supported channel init timeout values
enum p9_cen_framelock_channel_init_timeout
{
    CHANNEL_INIT_TIMEOUT_NO_TIMEOUT = 0,
    CHANNEL_INIT_TIMEOUT_3US = 1,
    CHANNEL_INIT_TIMEOUT_7US = 2,
    CHANNEL_INIT_TIMEOUT_14US = 3
};

// structure to represent HWP arguments
struct p9_cen_framelock_args
{
    p9_cen_framelock_channel_init_timeout channel_init_timeout;
    // channel init timeout value to program for framelock/
    // auto/FRTL
    bool frtl_auto_not_manual; // set FRTL mode (true = auto-calculation via HW,
    // false = manually-programmed via SW)
    uint8_t frtl_manual_pu; // in manual FRTL mode, P9 MCI FRTL value to be
    // programmed
    uint8_t frtl_manual_mem; // in manual FRTL mode, Centaur MBI FRTL value to
    // be programmed
};

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_cen_framelock_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_DMI>&,
                         const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&,
                         const p9_cen_framelock_args&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/// @brief      FAPI p9_cen_framelock HWP entry point, execute P9/Centaur
///             framelock and FRTL operations
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @param[in]  i_args       => p9_cen_framelock HWP argumemt structure
/// @return     FAPI2_RC_SUCCESS if framelock/FRTL sequence completes successfully,
///             or error from p9_cen_framelock_errors.xml
///             else FAPI getscom/putscom return code for failing operation
    fapi2::ReturnCode p9_cen_framelock(const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
                                       const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
                                       const p9_cen_framelock_args& i_args);

} // extern "C"

#endif // _PROC_CEN_FRAMELOCK_H_
