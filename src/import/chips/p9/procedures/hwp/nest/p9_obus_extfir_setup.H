/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_obus_extfir_setup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9_obus_extfir_setup.H
/// @brief Manage FBC EXTFIR setup (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//

#ifndef _P9_OBUS_EXTFIR_SETUP_H_
#define _P9_OBUS_EXTFIR_SETUP_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_obus_extfir_setup_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const bool,
    const bool,
    const bool,
    const bool);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Setup FBC EXTFIR for selected obus links
///
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_o0_smp_active  OBUS0 active as fabric link?
/// @param[in] i_o1_smp_active  OBUS1 active as fabric link?
/// @param[in] i_o2_smp_active  OBUS2 active as fabric link?
/// @param[in] i_o3_smp_active  OBUS3 active as fabric link?
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_obus_extfir_setup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                           const bool i_o0_smp_active,
                                           const bool i_o1_smp_active,
                                           const bool i_o2_smp_active,
                                           const bool i_o3_smp_active);

} // extern "C"

#endif // _P9_OBUS_EXTFIR_SETUP_H_
