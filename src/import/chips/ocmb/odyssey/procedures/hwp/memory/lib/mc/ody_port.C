/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mc/ody_port.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/mcbist/ody_maint_cmds.H>
#include <mss_generic_attribute_getters.H>
#include <ody_scom_ody_odc.H>


namespace mss
{
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
    FAPI_TRY(mss::getScom(i_target, TT::ROQ_REG, l_data), "%s failed to getScom from ROQ0Q",
             mss::c_str(i_target));

    // Sets the bit
    l_data.writeBit<TT::ROQ_FIFO_MODE>(i_state == mss::states::ON);

    // Sets the regs
    FAPI_TRY(mss::putScom(i_target, TT::ROQ_REG, l_data), "%s failed to putScom to ROQ0Q",
             mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

namespace ody
{

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
                                       200);

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

} // mss
