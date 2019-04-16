/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/accessor_wrapper.H $ */
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
/// @file accessor_wrapper.H
/// @brief The wrapper of new accessor API(get_/set_) to old accessor API
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ACCESSOR_WRAPPER_
#define _MSS_ACCESSOR_WRAPPER_

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <lib/mss_attribute_accessors.H>


namespace mss
{
namespace attr
{
///
/// @brief ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint16_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Runtime throttle numerator setting for cfg_nm_n_per_slot
///
inline fapi2::ReturnCode get_runtime_mem_throttled_n_commands_per_slot(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&
        i_target, uint16_t& o_value)
{
    return mss::runtime_mem_throttled_n_commands_per_slot(i_target, o_value);
}

///
/// @brief ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT setter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[in] uint16_t the value to set
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Runtime throttle numerator setting for cfg_nm_n_per_slot
///
inline fapi2::ReturnCode set_runtime_mem_throttled_n_commands_per_slot(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&
        i_target, uint16_t i_value)
{
    uint16_t l_value[2] = {};

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
                            i_target.getParent<fapi2::TARGET_TYPE_MCS>(), l_value) );
    l_value[mss::index(i_target)] = i_value;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
                            i_target.getParent<fapi2::TARGET_TYPE_MCS>(), l_value) );
    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("failed setting ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    return fapi2::current_err;
}


///
/// @brief ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint16_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Runtime throttled N commands per M DRAM clocks setting for cfg_nm_n_per_port.
///
inline fapi2::ReturnCode get_runtime_mem_throttled_n_commands_per_port(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&
        i_target, uint16_t& o_value)
{
    return mss::runtime_mem_throttled_n_commands_per_port(i_target, o_value);
}

///
/// @brief ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT setter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[in] uint16_t the value to set
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Runtime throttled N commands per M DRAM clocks setting for cfg_nm_n_per_port.
///
inline fapi2::ReturnCode set_runtime_mem_throttled_n_commands_per_port(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&
        i_target, uint16_t i_value)
{
    uint16_t l_value[2] = {};

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT,
                            i_target.getParent<fapi2::TARGET_TYPE_MCS>(), l_value) );
    l_value[mss::index(i_target)] = i_value;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT,
                            i_target.getParent<fapi2::TARGET_TYPE_MCS>(), l_value) );
    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("failed setting ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint16_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  This is the throttle numerator setting for cfg_nm_n_per_slot
///
inline fapi2::ReturnCode get_mem_throttled_n_commands_per_slot(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint16_t& o_value)
{
    return mss::mem_throttled_n_commands_per_slot(i_target, o_value);
}

///
/// @brief ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT setter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[in] uint16_t the value to set
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  This is the throttled N commands per window of M DRAM clocks setting for cfg_nm_n_per_port.
///
inline fapi2::ReturnCode set_mem_throttled_n_commands_per_port(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint16_t i_value)
{
    uint16_t l_value[2] = {};

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target.getParent<fapi2::TARGET_TYPE_MCS>(),
                            l_value) );
    l_value[mss::index(i_target)] = i_value;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target.getParent<fapi2::TARGET_TYPE_MCS>(),
                            l_value) );
    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("failed setting ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint16_t& reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  This is the throttled N commands per window of M DRAM clocks setting for cfg_nm_n_per_port.
///
inline fapi2::ReturnCode get_mem_throttled_n_commands_per_port(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint16_t& o_value)
{
    return mss::mem_throttled_n_commands_per_port(i_target, o_value);
}

///
/// @brief ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT setter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[in] uint16_t the value to set
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  This is the throttle numerator setting for cfg_nm_n_per_slot
///
inline fapi2::ReturnCode set_mem_throttled_n_commands_per_slot(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint16_t i_value)
{
    uint16_t l_value[2] = {};

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target.getParent<fapi2::TARGET_TYPE_MCS>(),
                            l_value) );
    l_value[mss::index(i_target)] = i_value;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target.getParent<fapi2::TARGET_TYPE_MCS>(),
                            l_value) );
    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("failed setting ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_PORT_MAXPOWER setter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[in] uint32_t the value to set
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Channel Pair Max Power output from thermal procedures
///
inline fapi2::ReturnCode set_port_maxpower(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint32_t i_value)
{
    uint32_t l_value[2] = {};

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_PORT_MAXPOWER, i_target.getParent<fapi2::TARGET_TYPE_MCS>(), l_value) );
    l_value[mss::index(i_target)] = i_value;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_PORT_MAXPOWER, i_target.getParent<fapi2::TARGET_TYPE_MCS>(), l_value) );
    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("failed setting ATTR_MSS_PORT_MAXPOWER: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    return fapi2::current_err;
}


///
/// @brief ATTR_MSS_DIMM_THERMAL_LIMIT getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint32_t&[] array reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  DIMM Max Power based on a thermal limit Decoded from ATTR_MSS_MRW_THERMAL_POWER_LIMIT
///
inline fapi2::ReturnCode get_dimm_thermal_limit(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint32_t (&o_array)[2])
{
    return mss::dimm_thermal_limit(i_target, o_array);
}

///
/// @brief ATTR_MSS_TOTAL_PWR_INTERCEPT getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint16_t&[] array reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  VDDR+VPP Power intercept value for dimm creator: mss_eff_config consumer: mss_bulk_pwr_throttles
///
inline fapi2::ReturnCode get_total_pwr_intercept(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint16_t (&o_array)[2])
{
    return total_pwr_intercept(i_target, o_array);
}

///
/// @brief ATTR_MSS_TOTAL_PWR_SLOPE getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint16_t&[] array reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  VDDR+VPP Power slope value for dimm creator: mss_eff_config consumer: mss_bulk_pwr_throttles
///
inline fapi2::ReturnCode get_total_pwr_slope(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        uint16_t (&o_array)[2])
{
    return mss::total_pwr_slope(i_target, o_array);
}

///
/// @brief ATTR_MSS_MEM_WATT_TARGET getter
/// @param[in] const ref to the TARGET_TYPE_MCA
/// @param[out] uint32_t&[] array reference to store the value
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note  Total memory power used to throttle for each dimm Used to compute the throttles
/// on the channel and/or dimms for OCC OCC sets after IPL creator: mss_eff_config consumer:
/// mss_bulk_pwr_throttle, mss_utils_to_throttle firmware notes: none.
///
inline fapi2::ReturnCode get_mem_watt_target(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint32_t& o_value)
{
    return mss::mem_watt_target(i_target, o_value);
}

}// namespace attr
}// namespace mss

#endif
