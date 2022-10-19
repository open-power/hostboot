/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_memdiags.C $ */
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

///
/// @file exp_memdiags.C
/// @brief Run and manage the MEMDIAGS engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/dimm/exp_rank.H>
#include <lib/mcbist/exp_memdiags.H>
#include <lib/mcbist/exp_mcbist.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/poll.H>


namespace mss
{

namespace memdiags
{

///
/// @brief Helper function to get the subtest to run continuous scrub for this memory controller type - Explorer specialization
/// @return The subtest used to run continuous scrub
///
template<>
mss::mcbist::subtest_t<mss::mc_type::EXPLORER> get_scrub_subtest<mss::mc_type::EXPLORER>()
{
    return mss::mcbist::scrub_subtest<mss::mc_type::EXPLORER>();
}

///
/// @brief Mask MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] and return the original mask value - specialization for Explorer
/// @param[in] i_target the target
/// @param[out] o_fir_mask_save the original mask value to be restored later
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode mask_program_complete<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& o_fir_mask_save )
{
    using TT = mss::mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_fir_mask;

    // Mask the FIR
    FAPI_TRY( mss::getScom(i_target, TT::FIRQ_MASK_REG, o_fir_mask_save) );
    l_fir_mask = o_fir_mask_save;
    l_fir_mask.setBit<TT::MCB_PROGRAM_COMPLETE>();
    FAPI_TRY( mss::putScom(i_target, TT::FIRQ_MASK_REG, l_fir_mask) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] mask value and clear the FIR - specialization for Explorer
/// @param[in] i_target the target
/// @param[in] i_fir_mask_save the original mask value to be restored
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode clear_and_restore_program_complete<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_fir_mask_save )
{
    using TT = mss::mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_fir;

    // Clear the FIR
    FAPI_TRY( mss::getScom(i_target, TT::FIRQ_REG, l_fir) );
    l_fir.clearBit<TT::MCB_PROGRAM_COMPLETE>();
    FAPI_TRY( mss::putScom(i_target, TT::FIRQ_REG, l_fir) );

    // Then restore the mask value
    FAPI_TRY( mss::putScom(i_target, TT::FIRQ_MASK_REG, i_fir_mask_save) );

fapi_try_exit:
    return fapi2::current_err;
}

} // memdiags
} // namespace mss
