/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_attr_update.H $ */
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
/// @file p10_mss_attr_update.H
/// @brief Placeholder for attribute overrides
///
/// *HW HW Maintainer: Joseph McGill <jmcgill@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB

#ifndef __P10_MSS_ATTR_UPDATE__
#define __P10_MSS_ATTR_UPDATE__

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*p10_mss_attr_update_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_MI>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Placeholder for attribute overrides
///
/// @param[in] i_target, the controller (e.g., MI)
/// @return FAPI2_RC_SUCCESS if ok
///
    fapi2::ReturnCode p10_mss_attr_update( const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target );

} //extern C

#endif //__P10_MSS_ATTR_UPDATE__
