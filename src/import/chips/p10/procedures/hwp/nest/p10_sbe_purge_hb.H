/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_purge_hb.H $ */
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
/// @file p10_sbe_purge_hb.H
/// @brief Purges active/backing caches and resets contained mode
///        configuration, as part of HB cache contained
///        exit sequence

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by  : SBE
//

#ifndef _P10_SBE_PURGE_HB_H_
#define _P10_SBE_PURGE_HB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_sbe_purge_hb_FP_t)(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>&,
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

///
/// @brief Purges active/backing caches and resets contained mode
///        configuration, as part of HB cache contained
///        exit sequence
///
/// @param[in] i_active_core_targets   Set of targets to process which are
///                                    associated with active cores
///                                    (running HB code)
/// @param[in] i_backing_cache_targets Set of targets to process which are
///                                    associated with backing caches
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_sbe_purge_hb(
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& i_active_core_targets,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& i_backing_cache_targets);

} // extern "C"

#endif // _P10_SBE_PURGE_HB_H_
