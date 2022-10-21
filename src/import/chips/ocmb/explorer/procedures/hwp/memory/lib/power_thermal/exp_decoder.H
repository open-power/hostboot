/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/power_thermal/exp_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file exp_decoder.H
/// @brief Decoder for ATTR_MSS_MRW_PWR_CURVE_SLOPE and _INTERCEPT and THERMAL_POWER_LIMIT
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_POWER_EXP_DECODER__
#define _MSS_POWER_EXP_DECODER__

#include <fapi2.H>

#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_kind.H>
#include <lib/power_thermal/exp_throttle.H>
#include <generic/memory/lib/utils/power_thermal/gen_decoder.H>


namespace mss
{

namespace power_thermal
{

///
/// @brief checks if it is a mds DIMM
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note set the l_dimm_type with correct type either mds or non-mds dimm type
///
template<>
fapi2::ReturnCode decoder<mss::mc_type::EXPLORER, throttle_traits<mss::mc_type::EXPLORER>>::encode_dimm_type();

} // power_thermal
} // mss
#endif
