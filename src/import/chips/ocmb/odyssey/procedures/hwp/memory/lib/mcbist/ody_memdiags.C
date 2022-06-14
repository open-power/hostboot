/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_memdiags.C $ */
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
/// @file ody_memdiags.C
/// @brief Run and manage the MEMDIAGS engine
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/dimm/ody_rank.H>
#include <lib/mcbist/ody_memdiags.H>
#include <lib/mcbist/ody_mcbist.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/poll.H>


namespace mss
{

namespace memdiags
{

///
/// @brief Mask MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] and return the original mask value - specialization for Odyssey
/// @param[in] i_target the target
/// @param[out] o_fir_mask_save the original mask value to be restored later
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode mask_program_complete<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& o_fir_mask_save )
{
    using TT = mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_fir_mask;

    // Mask the FIR
    // Todo: ZEN:MST-1660 Implement FIR_MASK_REG
    //FAPI_TRY( mss::getScom(i_target, TT::FIRQ_MASK_REG, o_fir_mask_save) );
    l_fir_mask = o_fir_mask_save;
    l_fir_mask.setBit<TT::MCB_PROGRAM_COMPLETE>();
    // Todo: ZEN:MST-1660 Implement FIR_MASK_REG
    //FAPI_TRY( mss::putScom(i_target, TT::FIRQ_MASK_REG, l_fir_mask) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] mask value and clear the FIR - specialization for Odyssey
/// @param[in] i_target the target
/// @param[in] i_fir_mask_save the original mask value to be restored
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode clear_and_restore_program_complete<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_fir_mask_save )
{
    using TT = mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_fir;

    // Clear the FIR
    FAPI_TRY( mss::getScom(i_target, TT::FIRQ_REG, l_fir) );
    l_fir.clearBit<TT::MCB_PROGRAM_COMPLETE>();
    FAPI_TRY( mss::putScom(i_target, TT::FIRQ_REG, l_fir) );

    // Then restore the mask value
    // Todo: ZEN:MST-1660 Implement FIR_MASK_REG
    //FAPI_TRY( mss::putScom(i_target, TT::FIRQ_MASK_REG, i_fir_mask_save) );

fapi_try_exit:
    return fapi2::current_err;
}

} // memdiags
} // namespace mss
