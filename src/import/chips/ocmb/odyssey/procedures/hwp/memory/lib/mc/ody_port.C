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
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/lib/utils/mc/gen_mss_port_traits.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/mc/ody_port_traits.H>

namespace mss
{

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

    // Loops through all port targets, hitting all the registers
    for( const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target) )
    {
        fapi2::buffer<uint64_t> l_data;

        // Gets the reg
        FAPI_TRY(mss::getScom(l_port, TT::ROQ_REG, l_data), "%s failed to getScom from ROQ0Q",
                 mss::c_str(l_port));

        // Sets the bit
        l_data.writeBit<TT::ROQ_FIFO_MODE>(i_state == mss::states::ON);

        // Sets the regs
        FAPI_TRY(mss::putScom(l_port, TT::ROQ_REG, l_data), "%s failed to putScom to ROQ0Q",
                 mss::c_str(l_port));
    }

    // In case we don't have any port's
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // mss