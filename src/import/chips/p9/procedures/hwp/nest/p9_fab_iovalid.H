/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fab_iovalid.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_fab_iovalid.H
/// @brief Manage fabric link iovalid controls (FAPI2)
///
/// Manage fabric X/A link iovalid controls, which control the
/// flow of fabric transactions
///
/// The iovalid controls are intended to be raised in the IPL flow
/// after the underlying PHY/DLL/TL layers are running, to start the
/// broadcast of fabric transactions
///
/// The iovalid controls are intended to be lowered prior to stopping
/// the clocks in the dump process (to provide a clean dump state with
/// the fabric quiesced)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB,FSP
//

#ifndef _P9_FAB_IOVALID_H_
#define _P9_FAB_IOVALID_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_fab_iovalid_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const bool,
    const bool,
    const bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Raise/lower iovalids for all logically enabled links on a single chip
///
/// @param[in] i_target              Reference to processor chip target
/// @param[in] i_set_not_clear       Define iovalid operation (true=set, false=clear)
/// @param[in] i_manage_electrical   Manage electrical links?
/// @param[in] i_manage_optical      Manage optical links?
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fab_iovalid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                     const bool i_set_not_clear,
                                     const bool i_manage_electrical,
                                     const bool i_manage_optical);

} // extern "C"

#endif // _P9_FAB_IOVALID_H_
