/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/plug_rules.C $ */
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
/// @file plug_rules.C
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vpd_access.H>
#include <mss.H>
#include <lib/mss_vpd_decoder.H>

#include <lib/eff_config/eff_config.H>
#include <lib/dimm/rank.H>
#include <lib/utils/assert_noexit.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;
using fapi2::FAPI2_RC_INVALID_PARAMETER;

namespace mss
{

namespace plug_rule
{

///
/// @brief Helper to find the best represented DIMM type in a vector of dimm::kind
/// @param[in, out] io_kinds a vector of dimm::kind
/// @return std::pair representing the type and the count.
/// @note the vector of kinds comes back sorted by DIMM type.
///
std::pair<uint8_t, uint64_t> dimm_type_helper(std::vector<dimm::kind>& io_kinds)
{
    std::pair<uint8_t, uint64_t> l_max = {fapi2::ENUM_ATTR_EFF_DIMM_TYPE_EMPTY, 0};

    // Sort the vector of kinds and walk it looking for the most common DIMM Type. This
    // is the 'winning' DIMM Type in that all the others are the one's which are incorrect.
    // Once we know that, we can walk the list and error out the 'losing' DIMM. For an MCS
    // there are only 4 DIMM possible, even for an MCBIST there are only 8. So this isn't
    // terrible. If this becomes a burden we can partition the vector once we know the winner,
    // and just error out the 'loser' partition.
    std::sort(io_kinds.begin(), io_kinds.end(), [](const dimm::kind & a, const dimm::kind & b) -> bool
    {
        return a.iv_dimm_type > b.iv_dimm_type;
    });

    uint8_t  l_cur_type = 0;
    uint64_t l_cur_type_count = 0;

    for (const auto& k : io_kinds)
    {
        // Empty DIMM don't count.
        if (k.iv_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_EMPTY)
        {
            continue;
        }

        // If we're on the same type, keep on keeping on
        if (k.iv_dimm_type == l_cur_type)
        {
            l_cur_type_count += 1;
        }

        // If we're on a different DIMM type, reset.
        else
        {
            l_cur_type = k.iv_dimm_type;
            l_cur_type_count = 1;
        }

        // Check to see if this current type over ran the previous champion
        if (l_cur_type_count > l_max.second)
        {
            l_max.first = l_cur_type;
            l_max.second = l_cur_type_count;
        }
    }

    // Don't need this output all that often. DBG is good.
    FAPI_DBG("winning type: %d winning count: %d", l_max.first, l_max.second);

    return l_max;
}

///
/// @brief Enforce no mixing DIMM types
/// @param[in] io_kinds a vector of DIMM (sorted while processing)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
/// @note The list of DIMM represents all the DIMM to check. So, if you want to
/// check the consistency of types across an MCS, give the list of DIMM on that MCS.
/// If you want to check across an MCBIST, system, etc., give that list of DIMM.
///
fapi2::ReturnCode dimm_type_mixing(std::vector<dimm::kind>& io_kinds)
{
    // We need to keep track of current_err ourselves as the FAPI_ASSERT_NOEXIT macro doesn't.
    fapi2::current_err = FAPI2_RC_SUCCESS;

    // Find out which DIMM type has the most DIMM in the list. This type is the 'correct'
    // type (by rule of majority) and the others are the one's who are incorrect.
    // We walk all the DIMM and call-out all the losers, not just the first. We have to break apart
    // the FAPI_ASSERT_NOEXIT macro a bit to do this.
    std::pair<uint8_t, uint64_t> l_winner = dimm_type_helper(io_kinds);

    for (const auto& k : io_kinds)
    {
        // Sets fapi2::current_err
        MSS_ASSERT_NOEXIT( ((k.iv_dimm_type == l_winner.first) ||
                            (k.iv_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_EMPTY)),
                           fapi2::MSS_PLUG_RULES_INVALID_DIMM_TYPE_MIX()
                           .set_DIMM_TYPE(k.iv_dimm_type)
                           .set_MAJORITY_DIMM_TYPE(l_winner.first)
                           .set_DIMM_TARGET(k.iv_target),
                           "%s of type %d can not be plugged in with DIMM of type %d",
                           mss::c_str(k.iv_target), k.iv_dimm_type, l_winner.first );

        // This should never fail ... but Just In Case a little belt-and-suspenders never hurt.
        // Later on down the line we make the assumption that effective config caught any mimatched
        // DRAM generations - so we ought to at least do that ...
        // TODO RTC:160395 This needs to change for controllers which support different generations, of which
        // Nimbus does not.
        MSS_ASSERT_NOEXIT( ((k.iv_dram_generation == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4) ||
                            (k.iv_dram_generation == fapi2::ENUM_ATTR_EFF_DRAM_GEN_EMPTY)),
                           fapi2::MSS_PLUG_RULES_INVALID_DRAM_GEN()
                           .set_DRAM_GEN(k.iv_dimm_type)
                           .set_DIMM_TARGET(k.iv_target),
                           "%s is not DDR4 it is %d",
                           mss::c_str(k.iv_target), k.iv_dram_generation );

    }

    return fapi2::current_err;
}

///
/// @brief Enforce rank configs
/// Enforces rank configurations which are not part of the VPD/rank config thing.
/// @note Reads an MRW attribute to further limit rank configs.
/// @param[in] i_target the port
/// @param[in] i_kinds a vector of DIMM (sorted while processing)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Expects the kind array to represent the DIMM on the port.
///
fapi2::ReturnCode check_rank_config(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                    const std::vector<dimm::kind>& i_kinds)
{
    // We need to keep trak of current_err ourselves as the FAPI_ASSERT_NOEXIT macro doesn't.
    fapi2::current_err = FAPI2_RC_SUCCESS;

    // If we have one DIMM, make sure it's in slot 0 and we're done.
    if (i_kinds.size() == 1)
    {
        // Sets fapi2::current_err
        MSS_ASSERT_NOEXIT( mss::index(i_kinds[0].iv_target) == 0,
                           fapi2::MSS_PLUG_RULES_SINGLE_DIMM_IN_WRONG_SLOT()
                           .set_MCA_TARGET(i_target)
                           .set_DIMM_TARGET(i_kinds[0].iv_target),
                           "%s is in slot 1, should be in slot 0", mss::c_str(i_kinds[0].iv_target));

        // Pass or fail, we're done as we only had one DIMM
        return fapi2::current_err;
    }

    // So if we're here we know we have more than one DIMM on this port.
    else
    {
        // Total up the number of ranks on this port. If it's more than MAX_PRIMARY_RANKS_PER_PORT we have a problem.
        // Notice that totaling up the ranks and using that as a metric also catches the 4R-is-not-the-only-DIMM case
        // (really probably that's the only case it catches but <shhhhh>.)
        // I don't think f/w supports std::count ... There aren't many DIMM on this port ...
        uint64_t l_rank_count = 0;
        const dimm::kind* l_dimm0_kind = nullptr;

        for (const auto& k : i_kinds)
        {
            // While we're here, lets look for the DIMM on slot 0 - we'll need it later
            if (mss::index(k.iv_target) == 0)
            {
                l_dimm0_kind = &k;
            }

            l_rank_count += k.iv_master_ranks;
        }

        // If we get here and we see there's no DIMM in slot 0, we did something very wrong. We shouldn't have
        // passed the i_kinds.size() == 1 test above. So lets assert, shouldn't happen, but tracking the nullptr
        // dereference is harder <grin>
        if (l_dimm0_kind == nullptr)
        {
            FAPI_ERR("seeing a nullptr for DIMM0, which is terrible %s %d", mss::c_str(i_target), i_kinds.size() );
            fapi2::Assert(false);
        }

        // Safe to use l_dimm0_kind.
        MSS_ASSERT_NOEXIT( l_rank_count <= MAX_PRIMARY_RANKS_PER_PORT,
                           fapi2::MSS_PLUG_RULES_INVALID_PRIMARY_RANK_COUNT()
                           .set_TOTAL_RANKS(l_rank_count)
                           .set_TARGET(i_target),
                           "There are more than %d master ranks on %s (%d)",
                           MAX_PRIMARY_RANKS_PER_PORT, mss::c_str(i_target), l_rank_count );

        FAPI_INF("DIMM in slot 0 %s has %d master ranks",
                 mss::c_str(l_dimm0_kind->iv_target), l_dimm0_kind->iv_master_ranks);

        // The DIMM in slot 0 has to have the largest number of master ranks on the port.
        const auto l_result = std::find_if(i_kinds.begin(), i_kinds.end(), [&l_dimm0_kind](const dimm::kind & k) -> bool
        {
            return k.iv_master_ranks > l_dimm0_kind->iv_master_ranks;
        });

        // Assertion is that we have no DIMM with more ranks - that is, we came to the end without finding
        // a DIMM with more master ranks than DIMM0
        MSS_ASSERT_NOEXIT( l_result == i_kinds.end(),
                           fapi2::MSS_PLUG_RULES_INVALID_RANK_CONFIG()
                           .set_RANKS_ON_DIMM0(i_kinds[0].iv_master_ranks)
                           .set_RANKS_ON_DIMM1(i_kinds[1].iv_master_ranks)
                           .set_TARGET(i_target),
                           "The DIMM configuration on %s is incorrect. Master ranks on [1][0]: %d,%d",
                           mss::c_str(i_target), i_kinds[1].iv_master_ranks, i_kinds[0].iv_master_ranks );

        return fapi2::current_err;
    }
}

} // close namespace plug_rule

///
/// @brief Enforce the plug-rules per MCS
/// @param[in] i_target FAPI2 target (MCS)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode eff_config::enforce_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    // Check per-MCS plug rules. If those all pass, check each of our MCA

    const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(i_target);

    // Check to see that we have DIMM on this MCS. If we don't, just carry on - this is valid.
    // Cronus does this often; they don't deconfigure empty ports or controllers. However, f/w
    // does. So if we're here we're running on Cronus or f/w has a bug <grin>
    if (l_dimms.size() == 0)
    {
        FAPI_INF("No DIMM configured for MCS %s, but it itself seems configured", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    auto l_dimm_kinds = mss::dimm::kind::vector(l_dimms);

    // We want to be careful here. The idea is to execute all the plug rules and commit erros before
    // failing out. That way, a giant configuration doesn't take 45m to boot, to find a DIMM out of place
    // the another 45m to find the next DIMM, etc.
    fapi2::ReturnCodes l_rc = FAPI2_RC_SUCCESS;

    // We enforce DIMM type mixing per MCS
    l_rc = (plug_rule::dimm_type_mixing(l_dimm_kinds) == FAPI2_RC_SUCCESS) ? l_rc : FAPI2_RC_INVALID_PARAMETER;

    // All good, got check the ports.
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        l_rc = (enforce_plug_rules(p) == FAPI2_RC_SUCCESS) ? l_rc : FAPI2_RC_INVALID_PARAMETER;
    }

    return l_rc;
}

///
/// @brief Enforce the plug-rules per MCA
/// @param[in] i_target FAPI2 target (MCA)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode eff_config::enforce_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(i_target);

    // Check to see that we have DIMM on this MCA. If we don't, just carry on - this is valid.
    // Cronus does this often; they don't deconfigure empty ports or controllers. However, f/w
    // does. So if we're here we're running on Cronus or f/w has a bug <grin>
    if (l_dimms.size() == 0)
    {
        FAPI_INF("No DIMM configured for MCA %s, but it itself seems configured", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    // Safe, even though the VPD decoder can get us here before the rest of eff_config has completed.
    // We'll only use the master rank information to enforce the rank config rules (which will have been
    // decoded and are valid before VPD was asked for.)
    const auto l_dimm_kinds = mss::dimm::kind::vector(l_dimms);

    // Note that we do limited rank config checking here. Most of the checking is done via VPD decoding,
    // meaning that if the VPD decoded the config then there's only a few rank related issues we need
    // to check here.
    FAPI_TRY( plug_rule::check_rank_config(i_target, l_dimm_kinds) );

fapi_try_exit:
    return fapi2::current_err;
}


}// mss
