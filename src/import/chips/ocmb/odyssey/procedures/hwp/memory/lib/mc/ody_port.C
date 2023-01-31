/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mc/ody_port.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_port.C
/// @brief Odyssey specializations for memory ports
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <ody_scom_ody.H>
#include <lib/shared/ody_consts.H>
#include <lib/dimm/ody_rank.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/lib/utils/mc/gen_mss_restore_repairs.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/mc/ody_port.H>
#include <lib/ecc/ecc_traits_odyssey.H>
#include <lib/mcbist/ody_maint_cmds.H>
#include <mss_generic_attribute_getters.H>
#include <ody_scom_ody_odc.H>
#include <generic/memory/lib/utils/mss_generic_check.H>


namespace mss
{
#ifndef __PPE__
const std::vector<uint8_t> portTraits< mss::mc_type::ODYSSEY >::NON_SPARE_NIBBLES =
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

const std::vector<uint8_t> portTraits< mss::mc_type::ODYSSEY >::SPARE_NIBBLES =
{
    // Byte 5 contains the spares (if they exist) for mc_type
    10,
    11
};
#endif
///
/// @brief Configures the write reorder queue bit - Odyssey specialization
/// @param[in] i_target the target to effect
/// @param[in] i_state to set the bit too
/// @return FAPI2_RC_SUCCSS iff ok
/// @NOTE: Due to RRQ and WRQ being combined into ROQ this function is now NOOP
///
template< >
fapi2::ReturnCode configure_wrq<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const mss::states i_state)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Configures the read reorder queue bit - Odyssey specialization
/// @param[in] i_target the target to effect
/// @param[in] i_state to set the bit too
/// @return FAPI2_RC_SUCCSS iff ok
///
template< >
fapi2::ReturnCode configure_rrq<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const mss::states i_state)
{
    using TT = portTraits<mss::mc_type::ODYSSEY>;
    fapi2::buffer<uint64_t> l_data;

    // Gets the reg
    FAPI_TRY(mss::getScom(i_target, TT::ROQ_REG, l_data), TARGTIDFORMAT " failed to getScom from ROQ0Q",
             TARGTID);

    // Sets the bit
    l_data.writeBit<TT::ROQ_FIFO_MODE>(i_state == mss::states::ON);

    // Sets the regs
    FAPI_TRY(mss::putScom(i_target, TT::ROQ_REG, l_data), TARGTIDFORMAT " failed to putScom to ROQ0Q",
             TARGTID);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the bandwidth snapshot - Odyssey specialization
/// @param[in] i_data data read from the FARB6 register
/// @param[out] o_bw_snapshot_side0 bandwidth for side 0
/// @param[out] o_bw_snapshot_side1 bandwidth for side 1
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
void get_bw_snapshot<mss::mc_type::ODYSSEY>( const fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_bw_snapshot_side0,
        uint64_t& o_bw_snapshot_side1 )
{
    using TT = portTraits<mss::mc_type::ODYSSEY>;

    o_bw_snapshot_side0 = 0;
    o_bw_snapshot_side1 = 0;
    i_data.extractToRight<TT::BW_SNAPSHOT_SIDE0, TT::BW_SNAPSHOT_SIDE0_LEN>(o_bw_snapshot_side0);
    i_data.extractToRight<TT::BW_SNAPSHOT_SIDE1, TT::BW_SNAPSHOT_SIDE1_LEN>(o_bw_snapshot_side1);
}

namespace ody
{

///
/// @brief Enable power management - Odyssey helper for unit testing
/// @param[in] i_target the target
/// @param[in] i_pwr_cntrl value of ATTR_MSS_MRW_POWER_CONTROL_REQUESTED
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode enable_power_management_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_pwr_cntrl)
{
    using TT = portTraits<mss::mc_type::ODYSSEY>;

    fapi2::buffer<uint64_t> l_rpc0;
    fapi2::buffer<uint64_t> l_str0;

    // Get the value from attribute and write the corresponding settings to scom registers
    FAPI_TRY(fapi2::getScom(i_target, TT::MBARPC0Q_REG, l_rpc0));
    FAPI_TRY(fapi2::getScom(i_target, TT::STR0Q_REG, l_str0));

    switch (i_pwr_cntrl)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF:
            {
                l_rpc0.clearBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>()
                .clearBit<TT::CFG_LP_CTRL_ENABLE>()
                .clearBit<TT::CFG_LP_DATA_ENABLE>();
                l_str0.clearBit<TT::CFG_STR_ENABLE>()
                .clearBit<TT::CFG_DIS_CLK_IN_STR>();
                break;
            }

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN:
            {
                l_rpc0.setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>()
                .clearBit<TT::CFG_LP_CTRL_ENABLE>()
                .clearBit<TT::CFG_LP_DATA_ENABLE>();
                l_str0.clearBit<TT::CFG_STR_ENABLE>()
                .clearBit<TT::CFG_DIS_CLK_IN_STR>();
                break;
            }

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR:
            {
                l_rpc0.setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>()
                .setBit<TT::CFG_LP_CTRL_ENABLE>()
                .setBit<TT::CFG_LP_DATA_ENABLE>();
                l_str0.setBit<TT::CFG_STR_ENABLE>()
                .clearBit<TT::CFG_DIS_CLK_IN_STR>();
                break;
            }

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP:
        default:
            {
                l_rpc0.setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>()
                .setBit<TT::CFG_LP_CTRL_ENABLE>()
                .setBit<TT::CFG_LP_DATA_ENABLE>();
                l_str0.setBit<TT::CFG_STR_ENABLE>()
                .setBit<TT::CFG_DIS_CLK_IN_STR>();
                break;
            }
    }

    // Set the MIN_DOMAIN_REDUCTION time
    l_rpc0.insertFromRight<TT::CFG_MIN_DOMAIN_REDUCTION_TIME, TT::CFG_MIN_DOMAIN_REDUCTION_TIME_LEN>
    (TT::MIN_DOMAIN_REDUCTION_TIME);

    // Set the ENTER_STR time
    l_str0.insertFromRight<TT::CFG_ENTER_STR_TIME, TT::CFG_ENTER_STR_TIME_LEN>(TT::ENTER_STR_TIME);

    FAPI_TRY(fapi2::putScom(i_target, TT::MBARPC0Q_REG, l_rpc0));
    FAPI_TRY(fapi2::putScom(i_target, TT::STR0Q_REG, l_str0));


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Initializes the DFI interface
/// @param[in] i_target the target to check for DFI interface completion
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode poll_for_dfi_init_complete( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{

    // For each port...
    for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // ... Polls for the DFI init complete
        FAPI_TRY(poll_for_dfi_init_complete(l_port));
    }

    FAPI_INF(TARGTIDFORMAT " DFI polling completed successfully", TARGTID);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Initializes the DFI interface
/// @param[in] i_target the target to check for DFI interface completion
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode poll_for_dfi_init_complete( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    using TT = mss::portTraits< mss::mc_type::ODYSSEY >;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Each PHY (aka port target) has its own DFI complete bit
    // As such, depending upon the port in question, the DFI complete bit is different
    const uint64_t DFI_COMPLETE_BIT = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
                                      (i_target) == 0 ?
                                      TT::DFI_INIT_COMPLETE0 : TT::DFI_INIT_COMPLETE1;


    fapi2::buffer<uint64_t> l_data;
    mss::poll_parameters l_poll_params(DELAY_10NS,
                                       200,
                                       mss::DELAY_1MS,
                                       200,
                                       2000);

    // Poll for getting 1 at the DFI complete bit
    bool l_poll_return = mss::poll(l_ocmb, l_poll_params, [&l_ocmb, &DFI_COMPLETE_BIT]()->bool
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(l_ocmb, TT::FARB6Q_REG, l_data));
        return l_data.getBit(DFI_COMPLETE_BIT);

    fapi_try_exit:
        FAPI_ERR("mss::poll() hit an error in mss::getScom");
        return false;
    });

    // following FAPI_TRY to preserve the scom failure in lambda.
    FAPI_TRY(fapi2::current_err);
    FAPI_ASSERT(l_poll_return,
                fapi2::ODY_DRAMINIT_DFI_INIT_TIMEOUT().
                set_PORT_TARGET(i_target),
                TARGTIDFORMAT " poll for DFI init complete timed out", TARGTID);

fapi_try_exit:
    return fapi2::current_err;
}

} // ody

///
/// @brief Enable power management - Odyssey specialization
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< >
fapi2::ReturnCode enable_power_management<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    //Enable Power management based off of mrw_power_control_requested
    FAPI_INF(TARGTIDFORMAT " Enable Power min max domains", TARGTID);

    uint8_t l_pwr_cntrl = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_pwr_cntrl));

    FAPI_TRY(mss::ody::enable_power_management_helper(i_target, l_pwr_cntrl));

fapi_try_exit:
    return fapi2::current_err;
}

} // mss
