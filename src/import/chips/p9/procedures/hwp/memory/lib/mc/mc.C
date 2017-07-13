/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/mc.C $       */
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
/// @file mc.C
/// @brief Subroutines to manipulate the memory controller
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/utils/dump_regs.H>
#include <lib/mc/mc.H>
#include <generic/memory/lib/utils/find.H>

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

enum throttle_enums
{
    NM_RAS_WEIGHT = 0b000,
    NM_CAS_WEIGHT = 0b001,

    CHANGE_AFTER_SYNC_ON = 0b1,
    CHANGE_AFTER_SYNC_OFF = 0b0,

    MAXALL_MINALL = 0b000,

    // Wait 959 refresh intervals of idle before powering down all ranks
    MIN_DOMAIN_REDUCTION_TIME = 959,

    // Wait 1023 refresh intervals of idle before going into STR on all ranks
    // 1023 is the max allowed value
    ENTER_STR_TIME = 1023
};

///
/// @brief set the PWR CNTRL register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MCA_MBARPC0Q
///
fapi2::ReturnCode set_pwr_cntrl_reg(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef mss::mcTraits<fapi2::TARGET_TYPE_MCA> TT;
    uint8_t l_pwr_cntrl = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mrw_power_control_requested(l_pwr_cntrl), "Error in set_pwr_cntrl_reg");
    FAPI_TRY(mss::getScom(i_target, MCA_MBARPC0Q, l_data), "Error in set_pwr_cntrl_reg");

    l_data.insertFromRight<TT::CFG_MIN_MAX_DOMAINS, TT::CFG_MIN_MAX_DOMAINS_LEN>(MAXALL_MINALL);

    //Write data if PWR_CNTRL_REQUESTED includes power down
    switch (l_pwr_cntrl)
    {
        case PD_AND_STR:
        case POWER_DOWN:
        case PD_AND_STR_CLK_STOP:
            l_data.setBit<TT::MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        case PD_AND_STR_OFF:
            l_data.clearBit<TT::MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        default:
            // Chief system engineer would reaally have to mess up here since _OFF is 0
            FAPI_ERR("ATTR_MSS_MRW_POWER_CONTROL_REQUESTED not set correctly in MRW");
            fapi2::Assert(false);
            break;
    }

    //Set the MIN_DOMAIN_REDUCTION time
    l_data.insertFromRight<TT::MIN_DOMAIN_REDUCTION_TIME, TT::MIN_DOMAIN_REDUCTION_TIME_LEN>
    (MIN_DOMAIN_REDUCTION_TIME);

    FAPI_TRY(mss::putScom(i_target, MCA_MBARPC0Q, l_data), "Error in set_pwr_cntrl_reg" );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error setting power control register MBARPC0Q for target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the STR register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBASTR0Q
///
fapi2::ReturnCode set_str_reg(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef mss::mcTraits<fapi2::TARGET_TYPE_MCA> TT;
    uint8_t l_str_enable = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mrw_power_control_requested(l_str_enable), "Error in set_pwr_cntrl_reg");
    FAPI_TRY(mss::getScom(i_target, MCA_MBASTR0Q, l_data), "Error in set_pwr_cntrl_reg");

    //Write bit if STR should be enabled
    switch (l_str_enable)
    {
        case PD_AND_STR:
        case PD_AND_STR_CLK_STOP:
            l_data.setBit<TT::CFG_STR_ENABLE>();
            break;

        case POWER_DOWN:
        case PD_AND_STR_OFF:
            l_data.clearBit<TT::CFG_STR_ENABLE>();
            break;

        default:
            // System engineer would reaally have to mess up here since _OFF is 0
            FAPI_ERR("ATTR_MSS_MRW_POWER_CONTROL_REQUESTED not set correctly in MRW");
            fapi2::Assert(false);
            break;
    }

    // MCA_MBASTR0Q_CFG_DIS_CLK_IN_STR:  Set to 1 for PD_AND_STR_CLK_STOP, otherwise clear the bit
    // Only for DD2.0 and above, will not work for DD1.* HW
    if( !chip_ec_feature_mss_dis_clk_in_str(i_target) )
    {
        l_data.writeBit<MCA_MBASTR0Q_CFG_DIS_CLK_IN_STR>(l_str_enable == PD_AND_STR_CLK_STOP);
    }

    l_data.insertFromRight<TT::ENTER_STR_TIME_POS, TT::ENTER_STR_TIME_LEN>(ENTER_STR_TIME);

    FAPI_TRY(mss::putScom(i_target, MCA_MBASTR0Q, l_data), "Error in set_str_reg" );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error setting the STR register MBASTR0Q for target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the general N/M throttle register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBA_FARB3Q
///

fapi2::ReturnCode set_nm_support (const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef mss::mcTraits<fapi2::TARGET_TYPE_MCA> TT;

    uint16_t l_run_slot = 0;
    uint16_t l_run_port = 0;
    uint32_t l_throttle_denominator = 0;

    fapi2::buffer<uint64_t> l_data;

    //runtime should be calculated in eff_config_thermal, which is called before scominit in ipl
    FAPI_TRY(runtime_mem_throttled_n_commands_per_port(i_target, l_run_port), "Error in set_nm_support");
    FAPI_TRY(runtime_mem_throttled_n_commands_per_slot(i_target, l_run_slot), "Error in set_nm_support");
    FAPI_TRY(mss::mrw_mem_m_dram_clocks(l_throttle_denominator), "Error in set_nm_support" );
    FAPI_INF("For target %s throttled n commands per port are %d, per slot are %d, and dram m clocks are %d",
             mss::c_str(i_target),
             l_run_port,
             l_run_slot,
             l_throttle_denominator);
    FAPI_TRY(mss::getScom(i_target, MCA_MBA_FARB3Q, l_data), "Error in set_nm_support");

    l_data.insertFromRight<TT::RUNTIME_N_SLOT, TT::RUNTIME_N_SLOT_LEN>(l_run_slot);
    l_data.insertFromRight<TT::RUNTIME_N_PORT, TT::RUNTIME_N_PORT_LEN>(l_run_port);
    l_data.insertFromRight<TT::RUNTIME_M, TT::RUNTIME_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::RAS_WEIGHT_POS, TT::RAS_WEIGHT_LEN>(NM_RAS_WEIGHT);
    l_data.insertFromRight<TT::CAS_WEIGHT_POS, TT::CAS_WEIGHT_LEN>(NM_CAS_WEIGHT);

    // If set, changes to cfg_nm_n_per_slot, cfg_nm_n_per_port, cfg_nm_m, min_max_domains will only be applied after a pc_sync command is seen
    // Set to disable permanently due to hardware design bug (HW403028) that won't be changed
    l_data.writeBit<TT::NM_CHANGE_AFTER_SYNC>(CHANGE_AFTER_SYNC_OFF);

    FAPI_TRY(mss::putScom(i_target, MCA_MBA_FARB3Q, l_data), "Error in set_nm_support" );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error setting nm throttles for target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the safemode throttle register
/// @param[in] i_target the mca target
/// @return fapi2::fapi2_rc_success if ok
/// @note sets MCA_MBA_FARB4Q
/// @note used to set throttle window (N throttles  / M clocks)
///
fapi2::ReturnCode set_safemode_throttles(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef mss::mcTraits<fapi2::TARGET_TYPE_MCA> TT;

    fapi2::buffer<uint64_t> l_data;
    uint16_t l_throttle_per_slot = 0;
    uint32_t l_throttle_denominator = 0;

    FAPI_TRY(mss::mrw_mem_m_dram_clocks(l_throttle_denominator), "Error in set_safemode_throttles" );
    FAPI_TRY(mss::mrw_safemode_mem_throttled_n_commands_per_port(l_throttle_per_slot), "Error in set_safemode_throttles" );
    FAPI_TRY(mss::getScom(i_target, MCA_MBA_FARB4Q, l_data), "Error in set_safemode_throttles" );

    l_data.insertFromRight<TT::EMERGENCY_M, TT::EMERGENCY_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::EMERGENCY_N, TT::EMERGENCY_N_LEN>(l_throttle_per_slot);
    FAPI_TRY(mss::putScom(i_target, MCA_MBA_FARB4Q, l_data), "Error in set_safemode_throttles" );
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("Error setting safemode throttles for target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

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
/// @brief safemode throttle values defined from MRW attributes
/// @param[in] i_target the MCA target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets safemode values for emergency mode and regular throttling
///
fapi2::ReturnCode thermal_throttle_scominit (const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    FAPI_TRY(set_pwr_cntrl_reg(i_target), "Error in thermal_throttle_scominit");
    FAPI_TRY(set_str_reg(i_target), "Error in thermal_throttle_scominit");
    FAPI_TRY(set_nm_support(i_target), "Error in thermal_throttle_scominit");
    FAPI_TRY(set_safemode_throttles(i_target), "Error in thermal_throttle_scominit");

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error setting scominits for power_thermal values");
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
