/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file p9_mss_utils_to_throttle.H
/// @brief throttle API
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_POWER_THROTTLE_
#define _MSS_POWER_THROTTLE_

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/power_thermal/accessor_wrapper.H>
#include <lib/power_thermal/throttle_traits.H>
#include <lib/dimm/nimbus_kind.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle.H>

namespace mss
{
namespace power_thermal
{
///
/// @brief set ATTR_MSS_RUNTIME_MEM_M_DRAM_CLOCKS and ATTR_MSS_MEM_WATT_TARGET
/// @param[in] i_targets vector of mcs targets all on the same vddr domain
/// @return FAPI2_RC_SUCCESS iff it was a success
///
fapi2::ReturnCode set_runtime_m_and_watt_limit( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets );

}//power_thermal

}// mss

#endif
