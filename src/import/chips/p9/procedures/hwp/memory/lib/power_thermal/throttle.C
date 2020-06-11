/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle.C $ */
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
/// @file throttle.C
/// @brief Determine throttle settings for memory
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
//std lib
#include<algorithm>
// fapi2
#include <fapi2.H>

// mss lib
#include <lib/power_thermal/throttle.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/pos.H>

namespace mss
{
namespace power_thermal
{

///
/// @brief set ATTR_MSS_RUNTIME_MEM_M_DRAM_CLOCKS and ATTR_MSS_MEM_WATT_TARGET
/// @param[in] i_targets vector of mcs targets all on the same vddr domain
/// @return FAPI2_RC_SUCCESS iff it was a success
///
fapi2::ReturnCode set_runtime_m_and_watt_limit( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets )
{
    uint32_t l_m_clocks = 0;
    uint32_t l_vmem_power_limit_dimm = 0;
    uint8_t l_max_dimms = 0;

    uint32_t l_count_dimms_vec = 0;
    uint32_t l_watt_target = 0;

    for (const auto& l_mcs : i_targets)
    {
        l_count_dimms_vec += mss::count_dimm(l_mcs);
    }

    if ( l_count_dimms_vec == 0)
    {
        FAPI_INF("No DIMMs found. Can't calculate WATT_TARGET");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( mrw_vmem_regulator_power_limit_per_dimm_ddr4(l_vmem_power_limit_dimm));
    FAPI_TRY( mrw_mem_m_dram_clocks(l_m_clocks));
    FAPI_TRY( mrw_max_number_dimms_possible_per_vmem_regulator(l_max_dimms));

    //Now calculate the watt target
    //Calculate max power available / number of dimms configured on the VDDR rail
    l_watt_target = (l_vmem_power_limit_dimm * l_max_dimms) / l_count_dimms_vec;

    // If we have too many dimms, deconfigure the first MCS
    // We know there are MCSs on the vector due to the check above
    FAPI_ASSERT( (l_count_dimms_vec <= l_max_dimms),
                 fapi2::MSS_DIMM_COUNT_EXCEEDS_VMEM_REGULATOR_LIMIT()
                 .set_MAX_DIMM_AMOUNT(l_max_dimms)
                 .set_DIMMS_SEEN(l_count_dimms_vec),
                 "The number of dimms counted (%d) on the vector of MCS surpasses the limit (%d)",
                 l_count_dimms_vec,
                 l_max_dimms);

    FAPI_INF("Calculated ATTR_MSS_MEM_WATT_TARGET is %d, power_limit dimm is %d, max_dimms is %d, count dimms on vector is %d",
             l_watt_target,
             l_vmem_power_limit_dimm,
             l_max_dimms,
             l_count_dimms_vec);

    for (const auto& l_mcs : i_targets)
    {
        uint32_t l_watt_temp [PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {{l_watt_target, l_watt_target}, {l_watt_target, l_watt_target}};
        uint32_t l_runtime_m [PORTS_PER_MCS] = {l_m_clocks, l_m_clocks};

        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_M_DRAM_CLOCKS, l_mcs, l_runtime_m));
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_WATT_TARGET, l_mcs, l_watt_temp));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error setting power_thermal attributes MSS_WATT_TARGET");
    return fapi2::current_err;
}

///
/// @brief set the safemode throttle register
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
/// @note sets FARB4Q
/// @note used to set throttle window (N throttles  / M clocks)
/// @note NIMBUS specialization
///
template<>
fapi2::ReturnCode set_safemode_throttles<mss::mc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    using TT = throttle_traits<mss::mc_type::NIMBUS>;

    fapi2::buffer<uint64_t> l_data;
    fapi2::ATTR_MSS_MRW_SAFEMODE_MEM_THROTTLED_N_COMMANDS_PER_PORT_Type l_throttle_per_port = 0;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;

    FAPI_TRY(mss::attr::get_mrw_mem_m_dram_clocks(l_throttle_denominator), "Error in set_nm_support" );
    FAPI_TRY(mss::attr::get_mrw_safemode_mem_throttled_n_commands_per_port(l_throttle_per_port));

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB4Q_REG, l_data));

    l_data.insertFromRight<TT::EMERGENCY_M, TT::EMERGENCY_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::EMERGENCY_N, TT::EMERGENCY_N_LEN>(l_throttle_per_port);

    FAPI_TRY(fapi2::putScom(i_target, TT::FARB4Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("%s Error setting safemode throttles", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the PWR CNTRL register
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note NIMBUS specialization
///
template<>
fapi2::ReturnCode set_pwr_cntrl_reg<mss::mc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    using TT = throttle_traits<mss::mc_type::NIMBUS>;

    fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_Type l_pwr_cntrl = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::attr::get_mrw_power_control_requested(l_pwr_cntrl));
    FAPI_TRY(fapi2::getScom(i_target, TT::MBARPC0Q_REG, l_data));

    l_data.insertFromRight<TT::CFG_MIN_MAX_DOMAINS, TT::CFG_MIN_MAX_DOMAINS_LEN>(TT::MAXALL_MINALL);

    // Write data if PWR_CNTRL_REQUESTED includes power down
    switch (l_pwr_cntrl)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP:
            l_data.setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF:
            l_data.clearBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_UNSUPPORTED_MRW_POWER_CONTROL_REQUESTED()
                         .set_VALUE(l_pwr_cntrl),
                         "%s ATTR_MSS_MRW_POWER_CONTROL_REQUESTED not set correctly in MRW: l_pwr_cntrl",
                         mss::c_str(i_target),
                         l_pwr_cntrl);
            break;
    }

    //Set the MIN_DOMAIN_REDUCTION time
    l_data.insertFromRight<TT::CFG_MIN_DOMAIN_REDUCTION_TIME, TT::CFG_MIN_DOMAIN_REDUCTION_TIME_LEN>
    (TT::MIN_DOMAIN_REDUCTION_TIME);

    FAPI_TRY(fapi2::putScom(i_target, TT::MBARPC0Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("%s Error setting power control register MBARPC0Q", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the STR register
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note NIMBUS specialization
///
template<>
fapi2::ReturnCode set_str_reg<mss::mc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    using TT = throttle_traits<mss::mc_type::NIMBUS>;

    fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_Type l_str_enable = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::attr::get_mrw_power_control_requested(l_str_enable));
    FAPI_TRY(fapi2::getScom(i_target, TT::STR0Q_REG, l_data));

    //Write bit if STR should be enabled
    switch (l_str_enable)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP:
            l_data.setBit<TT::CFG_STR_ENABLE>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF:
            l_data.clearBit<TT::CFG_STR_ENABLE>();
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_UNSUPPORTED_MRW_POWER_CONTROL_REQUESTED()
                         .set_VALUE(l_str_enable),
                         "%s ATTR_MSS_MRW_POWER_CONTROL_REQUESTED not set correctly in MRW: l_pwr_cntrl",
                         mss::c_str(i_target),
                         l_str_enable);
            break;
    }

    l_data.insertFromRight<TT::CFG_ENTER_STR_TIME, TT::CFG_ENTER_STR_TIME_LEN>(TT::ENTER_STR_TIME);

    FAPI_TRY(fapi2::putScom(i_target, TT::STR0Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("%s Error setting the STR register MBASTR0Q", mss::c_str(i_target));
    return fapi2::current_err;
}

}//namespace power_thermal
}//namespace mss
