/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_determine_eco_mode.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file p10_determine_eco_mode.H
///
/// @brief Query core partial good information to determine if it supports
///        instruction execution or should be used as an L3 cache tank only,
///        set ATTR_ECO_MODE
///
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Dan Crowell <dcrowell@us.ibm.com>
/// *HWP Consumed by: HB,SBE,HWSV
///

// EKB-Mirror-To: hw/ppe, hostboot, hwsv

#ifndef _P10_DETERMINE_ECO_MODE_H_
#define _P10_DETERMINE_ECO_MODE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_determine_eco_mode_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Query core partial good information to determine if it supports
///        instruction execution or should be used as an L3 cache tank only,
///        set ATTR_ECO_MODE
///
/// @param[in] i_target       Reference to core target
/// @return fapi::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_determine_eco_mode(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target);

} // extern "C"

#endif // _P10_SBE_SCOMINIT_H_
