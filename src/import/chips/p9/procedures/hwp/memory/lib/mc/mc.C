/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/mc.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file mc.C
/// @brief Subroutines to manipulate the memory controller
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/shared/nimbus_defaults.H>
#include <generic/memory/lib/utils/dump_regs.H>
#include <lib/mc/mc.H>
#include <lib/utils/nimbus_find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;

namespace mss
{

///
/// @brief Dump the registers of the MC (MCA_MBA, MCS)
/// @param[in] i_target the MCS target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode dump_regs( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
{
    return fapi2::FAPI2_RC_SUCCESS;
}

namespace mc
{

///
/// @brief set the runtime throttle register to safemode values
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBA_FARB3Q
/// @Will be overwritten by OCC/cronus later in IPL
/// @called in thermal_init
///
fapi2::ReturnCode set_runtime_throttles_to_safe(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef mss::mcTraits<fapi2::TARGET_TYPE_MCA> TT;

    fapi2::buffer<uint64_t> l_data;
    uint16_t l_throttle_per_port = 0;
    uint32_t l_throttle_denominator = 0;

    FAPI_TRY(mss::mrw_mem_m_dram_clocks(l_throttle_denominator), "Error in set_safemode_throttles" );
    FAPI_TRY(mss::mrw_safemode_mem_throttled_n_commands_per_port(l_throttle_per_port), "Error in set_safemode_throttles" );
    FAPI_TRY(mss::getScom(i_target, MCA_MBA_FARB3Q, l_data), "Error in set_safemode_throttles" );

    //Same value for both throttles
    l_data.insertFromRight<TT::RUNTIME_N_SLOT, TT::RUNTIME_N_SLOT_LEN>(l_throttle_per_port);
    l_data.insertFromRight<TT::RUNTIME_N_PORT, TT::RUNTIME_N_PORT_LEN>(l_throttle_per_port);
    l_data.insertFromRight<TT::RUNTIME_M, TT::RUNTIME_M_LEN>(l_throttle_denominator);

    FAPI_TRY(mss::putScom(i_target, MCA_MBA_FARB3Q, l_data), "Error in set_safemode_throttles" );
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("Error setting safemode throttles for target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief disable emergency mode throttle for thermal_init
/// @param[in] i_target the mcs target
/// @return fapi2::fapi2_rc_success if ok
/// @note clears mcmode0_enable_emer_throttle bit in mcsmode0
///
fapi2::ReturnCode disable_emergency_throttle (const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::getScom(i_target, MCS_MCMODE0, l_data));
    l_data.clearBit<MCS_MCMODE0_ENABLE_EMER_THROTTLE>();
    FAPI_TRY(mss::putScom(i_target, MCS_MCMODE0, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace mc

} //close namespace mss
