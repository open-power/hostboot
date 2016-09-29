/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_arrayinit.H $ */
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
/// @file cen_arrayinit.H
/// @brief Centaur array init (FAPI2)
///
/// General Description : PRV Array Init Procedure
///                       - Array Init for all good chiplets except PRV
///                       - Scan0 cleanup for all good chiplets except PRV
///
/// Procedure Prereq :    Pervasive Init Procedure 1 & 2 completed
///                       Pervasive Array Init Procedure completed
///                       Pervasive Init Procedure 3 completed
///                       Chiplet Init Procedure completed
//
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

#ifndef _CEN_arrayinit_H_
#define _CEN_arrayinit_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*cen_arrayinit_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Centaur array init (FAPI2)
///
/// @param[in] i_target Reference to Centaur chip target
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode cen_arrayinit(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

} // extern "C"

#endif // _cen_arrayinit_H_
