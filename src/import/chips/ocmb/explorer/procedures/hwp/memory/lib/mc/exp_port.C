/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <exp_port.H>

namespace mss
{

///
/// @brief Set up memory controller specific settings for ECC registers (at the end of draminit_mc)
/// @param[in] i_target the target
/// @param[in,out] io_data contents of RECR register
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note mc_type::EXPLORER specialization
///
template< >
fapi2::ReturnCode ecc_reg_settings_draminit_mc<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& io_data )
{
    using TT = portTraits<mss::mc_type::EXPLORER>;
    fapi2::buffer<uint64_t> l_ctcr_data;

    // Explorer specific settings for RECR
    io_data.setBit<TT::RECR_ENABLE_MPE_NOISE_WINDOW>();
    io_data.setBit<TT::RECR_RETRY_UNMARKED_ERRORS>();
    io_data.clearBit<TT::RECR_CFG_MAINT_USE_TIMERS>();

    // Set up CTCR timers to 20x4^3 (1280 clock cycles; typical read latency is 120ish, so this is about 10x)
    // This is a preliminary guess from the design team. Also enable UE lockout window
    // CTCR -> 51A8E00000000000
    FAPI_TRY( mss::getScom(i_target, TT::CTCR_REG, l_ctcr_data) );

    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMER, TT::CTCR_MPE_TIMER_LEN>(0b010100);
    l_ctcr_data.insertFromRight<TT::CTCR_MPE_TIMEBASE, TT::CTCR_MPE_TIMEBASE_LEN>(0b011);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMER, TT::CTCR_UE_TIMER_LEN>(0b010100);
    l_ctcr_data.insertFromRight<TT::CTCR_UE_TIMEBASE, TT::CTCR_UE_TIMEBASE_LEN>(0b011);
    l_ctcr_data.setBit<TT::CTCR_UE_LOCKOUT_ENABLE>();

    FAPI_TRY( mss::putScom(i_target, TT::CTCR_REG, l_ctcr_data) );

fapi_try_exit:
    return fapi2::current_err;
}


}// mss
