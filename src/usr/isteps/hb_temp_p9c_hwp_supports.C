/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hb_temp_p9c_hwp_supports.C $                   */
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
/**
 *
 *  @file hb_temp_p9c_hwp_supports.C
 *
 *  TODO: RTC 176018
 *
 *  Contains the dummy functions to temporarily allow successful HB compilation
 *  when HWPs call Cumulus related libraries.
 *
 *  This file is to be removed once Hostboot imports Cumulus lib code from EKB.
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <fapi2.H>
#include <generic/memory/lib/utils/memory_size.H>

namespace mss
{

///
/// @brief Return the total memory size behind a DMI
/// @param[in] i_target the DMI target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode eff_memory_size( const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_target, uint64_t& o_size )
{
    o_size = 0;
    return fapi2::FAPI2_RC_SUCCESS;
}

}