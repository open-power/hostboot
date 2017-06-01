/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/memory_size.H $           */
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

///
/// @file memory_size.H
/// @brief Return the effective memory size behind a target
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EFF_MEMORY_SIZE_H_
#define _MSS_EFF_MEMORY_SIZE_H_

#include <fapi2.H>

namespace mss
{
///
/// @brief Check if a given DIMM is functional
/// @param[in] i_valid_dimm_bitmap from ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR
/// @param[in] i_port port index [0:1]
/// @param[in] i_dimm dimm index [0:1]
/// @return true if dimm is functional, false otherwise
///
bool is_dimm_functional(const uint8_t i_valid_dimm_bitmap,
                        const uint8_t i_port,
                        const uint8_t i_dimm);

///
/// @brief Return the total memory size behind the target
/// @tparam T fapi2 target template parameter
/// @param[in] i_target the fapi2::Target, typically a port
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode eff_memory_size( const fapi2::Target<T>& i_target, uint64_t& o_size );
}

#endif

