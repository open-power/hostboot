/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_memdiags.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#include <lib/shared/exp_defaults.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

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
