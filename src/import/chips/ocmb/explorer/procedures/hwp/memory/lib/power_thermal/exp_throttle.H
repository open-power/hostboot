/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/power_thermal/exp_throttle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_throttle.H
/// @brief throttle API
///

// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_EXP_THROTTLE_
#define _MSS_EXP_THROTTLE_

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/power_thermal/exp_throttle.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/power_thermal/exp_throttle_traits.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle.H>

namespace mss
{
namespace power_thermal
{

///
/// @brief Updates the max databus utilization based upon the DIMM type - EXPLORER specialization
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_max_util the utilization of the dimm at maximum possible percentage (mrw or calculated)
/// @return fapi2::FAPI2_RC_SUCCESS iff the method was a success
///
template<>
fapi2::ReturnCode update_max_util_by_dimm_type<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_target,
        double& io_max_util);

///
/// @brief Updates the database port max utilization based upon the DIMM type - EXPLORER/MEM_PORT specialization
/// @param[in] i_target the target on which to operate
/// @param[in] i_database_port_max the maximum utilization to use depending upon the DIMM type
/// @param[in,out] io_util the utilization of the dimm at maximum possible percentage (mrw or calculated)
/// @return fapi2::FAPI2_RC_SUCCESS iff the method was a success
///
template<>
fapi2::ReturnCode update_databus_port_max_util_by_dimm_type<mss::mc_type::EXPLORER>(const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const double i_databus_port_max,
        double& io_util);

///
/// @brief Set ATTR_EXP_PORT_MAXPOWER, ATTR_OCMB_EXP_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
///            ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT
/// @param[in] i_target
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note determines the throttle levels based off of the port's power curve,
/// sets the slot throttles to the same
/// @note Enums are POWER for power egulator throttles and THERMAL for thermal throttles
/// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///
fapi2::ReturnCode pwr_throttles( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 const mss::throttle_type i_throttle_type);

///
/// @brief Equalize the throttles among OCMB chips
/// @param[in] i_targets vector of OCMB chips
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///
fapi2::ReturnCode equalize_throttles( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >& i_targets,
                                      const mss::throttle_type i_throttle_type);

}//power_thermal
}// mss

#endif
