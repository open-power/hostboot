/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_tp_chiplet_init2.H $ */
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
/// @file cen_tp_chiplet_init2.H
/// @brief Centaur Pervasive Init Phase 2 (FAPI2)
///
/// General Description : Pervasive Init Procedure 2
///                        - first scan0, scom to clock control PRV chiplet
///
/// @author Peng Fei GOU <shgoupf@us.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

#ifndef _CEN_TP_CHIPLET_INIT2_H_
#define _CEN_TP_CHIPLET_INIT2_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*cen_tp_chiplet_init2_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Centaur Pervasive Init Phase 2 (FAPI2)
///
/// @param[in] i_target Reference to Centaur chip target
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode cen_tp_chiplet_init2(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

} // extern "C"

#endif // _CEN_TP_CHIPLET_INIT2_H_
