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
/// @brief memdiags multi-port init internal.
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template<>
fapi2::ReturnCode operation<mss::mc_type::EXPLORER>::multi_port_init_internal()
{
    return single_port_init();
}

///
/// @brief Set up memory controller specific settings for pre-maint mode read
/// @param[in] i_target the memory controller target
/// @return FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode pre_maint_read_settings<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    using TT = mss::portTraits<mss::mc_type::EXPLORER>;
    fapi2::buffer<uint64_t> l_data;

    // Set up Explorer specific settings
    FAPI_TRY( mss::getScom(i_target, TT::ECC_REG, l_data) );

    l_data.setBit<TT::RECR_MBSECCQ_MAINT_NO_RETRY_UE>();
    l_data.setBit<TT::RECR_MBSECCQ_MAINT_NO_RETRY_MPE>();

    FAPI_TRY( mss::putScom(i_target, TT::ECC_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up memory controller specific settings for pre-scrub
/// @param[in] i_target the memory controller target
/// @return FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode pre_scrub_settings<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    using TT = mss::portTraits<mss::mc_type::EXPLORER>;
    fapi2::buffer<uint64_t> l_data;

    // Set up Explorer specific settings
    FAPI_TRY( mss::getScom(i_target, TT::ECC_REG, l_data) );

    l_data.clearBit<TT::RECR_MBSECCQ_MAINT_NO_RETRY_UE>();
    l_data.clearBit<TT::RECR_MBSECCQ_MAINT_NO_RETRY_MPE>();

    FAPI_TRY( mss::putScom(i_target, TT::ECC_REG, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Mask MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] and return the original mask value - specialization for EXPLORER
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
/// @brief Restore MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] mask value and clear the FIR - specialization for EXPLORER
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

} // namespace memdiags

namespace exp
{

namespace memdiags
{

///
/// @brief Process the result from the mcbist sf_read subtest after memdiags
///
/// @param[in] i_target OCMB target for traces
/// @param[in] l_fail_behavior_attr
/// @param[in,out] io_rc ReturnCode from sf_read
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode process_subtest_result(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t l_fail_behavior_attr,
        fapi2::ReturnCode& io_rc)
{
    // Check RC
    if ((l_fail_behavior_attr == fapi2::ENUM_ATTR_MSS_POST_MEMDIAGS_READ_SUBTEST_FAIL_BEHAVIOR_TRACE)
        && (io_rc != fapi2::FAPI2_RC_SUCCESS))
    {
        // Trace + Bad RC: Log as recovered, return success, set io_rc back to success
        FAPI_ERR("%s Error code 0x%08lx from post-memdiags mcbist read subtest", mss::c_str(i_target), uint32_t(io_rc));
        fapi2::logError(io_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);

        io_rc = fapi2::FAPI2_RC_SUCCESS;

        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Else, we will just try the RC as-is
    FAPI_TRY(io_rc, "%s Error from post-memdiags mcbist read subtest", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a read only mcbist subtest at the end of memdiags
///
/// @param[in] i_target OCMB Chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode perform_read_only_subtest(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_fail_behavior = 0;

    auto l_stop_conditions = mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>();

    // Pause on unrecoverable error
    l_stop_conditions.set_pause_on_ue(mss::ON);

    // sf_read will run, poll for completion and return result ReturnCode
    l_rc = mss::memdiags::sf_read<mss::mc_type::EXPLORER>(i_target, l_stop_conditions);

    // Get fail behavior attr and process the result
    FAPI_TRY(mss::attr::get_post_memdiags_read_subtest(i_target, l_fail_behavior));
    FAPI_TRY(process_subtest_result(i_target, l_fail_behavior, l_rc));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // memdiags
} // exp

} // namespace mss
