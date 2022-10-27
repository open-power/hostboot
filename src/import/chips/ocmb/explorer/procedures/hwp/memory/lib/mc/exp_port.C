/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
/// @file exp_port.C
/// @brief Code to support ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#include <fapi2.H>
#include <algorithm>
#include <lib/mc/exp_port_traits.H>
#include <lib/mc/exp_port.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>

namespace mss
{
const std::vector<uint8_t> portTraits< mss::mc_type::EXPLORER >::NON_SPARE_NIBBLES =
{
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    // Byte 5 contains the spares (if they exist) for mc_type
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
};

const std::vector<uint8_t> portTraits< mss::mc_type::EXPLORER >::SPARE_NIBBLES =
{
    // Byte 5 contains the spares (if they exist) for mc_type
    10,
    11
};

///
/// @brief Configures the write reorder queue bit - Explorer specialization
/// @param[in] i_target the target to effect
/// @param[in] i_state to set the bit too
/// @return FAPI2_RC_SUCCSS iff ok
///
template< >
fapi2::ReturnCode configure_wrq<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const mss::states i_state)
{
    using TT = portTraits<mss::mc_type::EXPLORER>;

    // Loops through all port targets, hitting all the registers
    for( const auto& l_port : mss::find_targets<TT::PORT_TYPE>(i_target) )
    {
        fapi2::buffer<uint64_t> l_data;

        // Gets the reg
        FAPI_TRY(mss::getScom(l_port, TT::WRQ_REG, l_data), "%s failed to getScom from WRQ0Q for Explorer", mss::c_str(l_port));

        // Sets the bit
        l_data.writeBit<TT::WRQ_FIFO_MODE>(i_state == mss::states::ON);

        // Sets the regs
        FAPI_TRY(mss::putScom(l_port, TT::WRQ_REG, l_data), "%s failed to putScom to WRQ0Q for Explorer", mss::c_str(l_port));
    }

    // In case we don't have any port's
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the read reorder queue bit - Explorer specialization
/// @param[in] i_target the target to effect
/// @param[in] i_state to set the bit too
/// @return FAPI2_RC_SUCCSS iff ok
///
template< >
fapi2::ReturnCode configure_rrq<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const mss::states i_state)
{
    using TT = portTraits<mss::mc_type::EXPLORER>;

    // Loops through all port targets, hitting all the registers
    for( const auto& l_port : mss::find_targets<TT::PORT_TYPE>(i_target) )
    {
        fapi2::buffer<uint64_t> l_data;

        // Gets the reg
        // This register sits on different chiplets depending upon the MC type in question
        // In some MC's, it sits on the port level
        // In other MC's, it sits on the chip level
        // As such, a helper function is used to grab the appropriate target type to run this scom
        FAPI_TRY(mss::getScom(TT::get_rrq_target(l_port), TT::RRQ_REG, l_data), "%s failed to getScom from RRQ0Q for Explorer",
                 mss::c_str(l_port));

        // Sets the bit
        l_data.writeBit<TT::RRQ_FIFO_MODE>(i_state == mss::states::ON);

        // Sets the regs
        FAPI_TRY(mss::putScom(TT::get_rrq_target(l_port), TT::RRQ_REG, l_data), "%s failed to putScom to RRQ0Q for Explorer",
                 mss::c_str(l_port));
    }

    // In case we don't have any port's
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the bandwidth snapshot - Explorer specialization
/// @param[in] i_data data read from the FARB6 register
/// @param[out] o_bw_snapshot_side0 bandwidth for the port
/// @param[out] o_bw_snapshot_side1 not used for Explorer
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
void get_bw_snapshot<mss::mc_type::EXPLORER>( const fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_bw_snapshot_side0,
        uint64_t& o_bw_snapshot_side1 )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;

    o_bw_snapshot_side0 = 0;
    o_bw_snapshot_side1 = 0;

    i_data.extractToRight<TT::BW_SNAPSHOT, TT::BW_SNAPSHOT_LEN>(o_bw_snapshot_side0);
}

///
/// @brief Helper for setting rcd protection time to minimum of DSM0Q_WRDONE_DLY & DSM0Q_RDTAG_DLY
/// @param [in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok

fapi2::ReturnCode config_exp_rcd_protect_time (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    using TT = portTraits<mss::mc_type::EXPLORER>;

    uint64_t l_rdtag_dly = 0;
    uint64_t l_wrdone_dly = 0;
    uint64_t l_rcd_prtct_time = 0;

    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_farb0q_data;

    //Get RDTAG and WRDONE dly values from DSM0Q [36:41] and [24:29] respectively
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_SRQ_MBA_DSM0Q, l_data));
    l_data.extractToRight<TT::DSM0Q_RDTAG_DLY, TT::DSM0Q_RDTAG_DLY_LEN>(l_rdtag_dly);
    l_data.extractToRight<TT::DSM0Q_WRDONE_DLY, TT::DSM0Q_WRDONE_DLY_LEN>(l_wrdone_dly);

    // Get previous value of FARB0Q
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_SRQ_MBA_FARB0Q, l_farb0q_data));

    // Find lower of two delay values
    l_rcd_prtct_time = std::min(l_rdtag_dly, l_wrdone_dly);

    // Configure FARB0Q protect time to reflect
    l_farb0q_data.insertFromRight<TT::FARB0Q_RCD_PROTECTION_TIME, TT::FARB0Q_RCD_PROTECTION_TIME_LEN>(l_rcd_prtct_time);
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_SRQ_MBA_FARB0Q, l_farb0q_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable power management - Explorer specialization
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< >
fapi2::ReturnCode enable_power_management<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;

    //Enable Power management based off of mrw_power_control_requested
    FAPI_INF("%s Enable Power min max domains", mss::c_str(i_target));

    bool is_pwr_cntrl = true;
    fapi2::buffer<uint64_t> l_data;
    uint8_t  l_pwr_cntrl = 0;

    // Get the value from attribute and write it to scom register
    FAPI_TRY(fapi2::getScom(i_target, TT::MBARPC0Q_REG, l_data));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_pwr_cntrl));

    is_pwr_cntrl = ((l_pwr_cntrl == fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN)
                    || (l_pwr_cntrl == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_PD_AND_STR)
                    || (l_pwr_cntrl == fapi2::ENUM_ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP));

    l_data.writeBit< TT::CFG_MIN_MAX_DOMAINS_ENABLE>(is_pwr_cntrl);
    FAPI_TRY( fapi2::putScom(i_target, TT::MBARPC0Q_REG, l_data) );


fapi_try_exit:
    return fapi2::current_err;
}

}// namespace mss
