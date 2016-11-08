/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/mcbist_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file mcbist_workarounds.C
/// @brief Workarounds for the MCBISt engine
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Steven Glancy <sglancy@usi.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/mss_attribute_accessors.H>
#include <lib/utils/scom.H>
#include <lib/utils/pos.H>
#include <lib/dimm/kind.H>
#include <lib/workarounds/mcbist_workarounds.H>
#include <lib/mcbist/mcbist.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace workarounds
{

namespace mcbist
{

///
/// @brief Replace reads with displays in the passed in MCBIST program
/// @param[in,out] the MCBIST program to check for read/display replacement
/// @note Useful for testing
///
void replace_read_helper(mss::mcbist::program<TARGET_TYPE_MCBIST>& io_program)
{
    using TT = mss::mcbistTraits<TARGET_TYPE_MCBIST>;

    io_program.change_maint_broadcast_mode(mss::OFF);
    io_program.change_end_boundary(mss::mcbist::end_boundary::STOP_AFTER_ADDRESS);

    for (auto& st : io_program.iv_subtests)
    {
        uint64_t l_op = 0;
        st.iv_mcbmr.extractToRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(l_op);

        if (l_op == mss::mcbist::op_type::READ)
        {
            l_op = mss::mcbist::op_type::DISPLAY;
        }

        st.iv_mcbmr.insertFromRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(l_op);
    }
}

///
/// @brief End of rank work around
/// For Nimbus DD1 the MCBIST engine doesn't detect the end of rank properly
/// for a 1R DIMM during a super-fast read. To work around this, we check the
/// MCBIST to see if any port has a 1R DIMM on it and if so we change our stop
/// conditions to immediate. However, because that doesn't work (by design) with
/// read, we also must change all reads to displays (slow read.)
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[in,out] io_program the mcbist program to check
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode end_of_rank( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                               mss::mcbist::program<TARGET_TYPE_MCBIST>& io_program )
{
    using TT = mss::mcbistTraits<TARGET_TYPE_MCBIST>;

    // If we don't need the mcbist work-around, we're done.
    if (! mss::chip_ec_feature_mcbist_end_of_rank(i_target) )
    {
        return FAPI2_RC_SUCCESS;
    }

    // First things first - lets find out if we have an 1R DIMM on our side of the chip.
    const auto l_dimm_kinds = dimm::kind::vector( mss::find_targets<TARGET_TYPE_DIMM>(i_target) );
    const auto l_kind = std::find_if(l_dimm_kinds.begin(), l_dimm_kinds.end(), [](const dimm::kind & k) -> bool
    {
        // If total ranks are 1, we have a 1R DIMM, SDP. This is the fellow of concern
        return k.iv_total_ranks == 1;
    });

    // If we don't find the fellow of concern, we can get outta here
    if (l_kind == l_dimm_kinds.end())
    {
        FAPI_INF("no 1R SDP DIMM on this MCBIST (%s), we're ok", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    if( ! io_program.iv_config.getBit<TT::MCBIST_CFG_PAUSE_AFTER_RANK>() )
    {
        FAPI_INF("not checking rank boundaries on this MCBIST (%s), we're ok", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    // If we're here, we need to fix up our program. We need to set our stop to stop immediate, which implies
    // we don't do broadcasts and we can't do read, we have to do display.
    replace_read_helper(io_program);

    return fapi2::FAPI2_RC_SUCCESS;
}

} // close namespace mcbist
} // close namespace workarounds
} // close namespace mss

