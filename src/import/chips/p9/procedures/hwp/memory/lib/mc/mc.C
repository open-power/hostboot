/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/mc.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/utils/dump_regs.H>
#include <lib/mc/mc.H>
#include <lib/utils/find.H>

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
/// @brief safemode throttle values defined from MRW attributes
/// @param[in] i_target the MCA target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets safemode values for emergency mode and regular throttling
///
fapi2::ReturnCode thermal_throttle_scominit (const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    uint32_t l_throttle_denominator = 0;
    FAPI_TRY( mss::mem_m_dram_clocks( i_target, l_throttle_denominator) );

    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(mss::getScom(i_target, MCA_MBA_FARB3Q, l_data));

        uint32_t l_throttle_per_port = 0;
        FAPI_TRY( mss::mrw_safemode_mem_throttled_n_commands_per_port( l_throttle_per_port) );

        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT, MCA_MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN>(l_throttle_per_port);
        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT, MCA_MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN>(l_throttle_per_port);
        l_data.insertFromRight<MCA_MBA_FARB3Q_CFG_NM_M, MCA_MBA_FARB3Q_CFG_NM_M_LEN>(l_throttle_denominator);

        l_data.clearBit<MCA_MBA_FARB3Q_CFG_NM_CHANGE_AFTER_SYNC>();

        FAPI_TRY( mss::putScom(i_target, MCA_MBA_FARB3Q, l_data) );
    }

    {
        fapi2::buffer<uint64_t> l_data;
        uint32_t l_throttle_per_slot = 0;

        FAPI_TRY( mss::mrw_safemode_mem_throttled_n_commands_per_port(l_throttle_per_slot) );
        FAPI_TRY( mss::getScom(i_target, MCA_MBA_FARB4Q, l_data) );

        l_data.insertFromRight<MCA_MBA_FARB4Q_EMERGENCY_M, MCA_MBA_FARB4Q_EMERGENCY_M_LEN>(l_throttle_denominator);
        l_data.insertFromRight<MCA_MBA_FARB4Q_EMERGENCY_N, MCA_MBA_FARB4Q_EMERGENCY_N_LEN>(l_throttle_per_slot);
        FAPI_TRY( mss::putScom(i_target, MCA_MBA_FARB4Q, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disable emergency mode throttle for thermal_init
/// @param[in] i_target the MCS target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note Clears MCMODE0_ENABLE_EMER_THROTTLE bit in MCSMODE0
///
fapi2::ReturnCode disable_emergency_throttle (const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, MCS_MCMODE0, l_data));
    l_data.clearBit<MCS_MCMODE0_ENABLE_EMER_THROTTLE>();
    FAPI_TRY( mss::putScom(i_target, MCS_MCMODE0, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace mc

} //close namespace mss
