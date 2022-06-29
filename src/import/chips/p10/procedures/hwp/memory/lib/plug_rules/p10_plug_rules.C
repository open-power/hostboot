/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/plug_rules/p10_plug_rules.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
/// @file p10_plug_rules.C
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/p10_consts.H>
#include <algorithm>

#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/num.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/plug_rules/p10_plug_rules.H>
#include <lib/dimm/exp_kind.H>


namespace mss
{

namespace plug_rule
{

///
/// @brief Enforces that MDS dimms are not mixed with non-MDS dimms
/// @param[in] i_target the MCC target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode check_mds(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_worst_rc = fapi2::FAPI2_RC_SUCCESS;

    bool l_is_mds = false;
    bool l_mds_dimm = false;

    // Check if MCC contains MDS dimms
    FAPI_TRY( mss::dimm::is_mds<mss::mc_type::EXPLORER>(i_target, l_is_mds) );

    // If no MDS dimms are present, skip
    if ( l_is_mds == false )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Loop through omi targets to get OCMB targets
    for(const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
    {
        // Check ocmb targets for mixed dimms
        for(const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
        {
            // Check dimm targets for mixed dimms
            for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_ocmb))
            {
                // Check if dimm is an MDS dimm
                FAPI_TRY( mss::dimm::is_mds<mss::mc_type::EXPLORER>(l_dimm, l_mds_dimm) );

                // If MCC contains MDS, ensure dimm is an MDS dimm
                FAPI_ASSERT_NOEXIT( l_mds_dimm,
                                    fapi2::MSS_PLUG_RULES_MIXED_MDS_PLUG_ERROR()
                                    .set_DIMM_TARGET(l_dimm)
                                    .set_OCMB_TARGET(l_ocmb)
                                    .set_MCC_TARGET(i_target),
                                    "%s is a non-MDS DIMM plugged mixed with MDS DIMMs",
                                    mss::c_str(l_dimm) );

                // Save off any failing errors
                if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
                {
                    // If there is a fail detected, log it
                    if (l_worst_rc != fapi2::FAPI2_RC_SUCCESS)
                    {
                        fapi2::logError(l_worst_rc, fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
                    }

                    // Save off the error and continue
                    l_worst_rc = fapi2::current_err;
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
            }

        }
    }

    return l_worst_rc;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks that the MDS Dimms have valid media controller targets
/// @param[in] i_target the OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode check_mds_media_controller(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    const uint8_t NUM_MDS_CNTL = 1;
    const auto l_num_cntl = mss::find_targets<fapi2::TARGET_TYPE_MDS_CTLR>(i_target, fapi2::TARGET_STATE_PRESENT).size();

    // If we are given a guaranteed failing list of targets (< 1 CNTL)
    FAPI_ASSERT((l_num_cntl >= NUM_MDS_CNTL),
                fapi2::INVALID_MDS_MEDIA_CNTL_TARGET_CONFIG()
                .set_OCMB_TARGET(i_target)
                .set_VALID_CONTROLLERS(l_num_cntl)
                .set_EXPECTED_CONTROLLERS(NUM_MDS_CNTL),
                "%s MDS Media Controller target missing or invalid, given %u controllers expected %u",
                mss::c_str(i_target),
                l_num_cntl,
                NUM_MDS_CNTL);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce the plug-rules for planar system
/// @param[in] i_target FAPI2 target (mem port)
/// @param[in] i_is_planar a uint8_t ATTR_MEM_MRW_IS_PLANAR attr
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_planar_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_is_planar)
{
    if ( i_is_planar == fapi2::ENUM_ATTR_MEM_MRW_IS_PLANAR_FALSE)
    {
        FAPI_INF("%s not a planar system so skipping planar based plug rules", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        mss::dimm::kind<mss::mc_type::EXPLORER> l_kind(l_dimm, l_rc);
        FAPI_TRY(l_rc, "%s Failed to create dimm::kind instance", mss::c_str(i_target));

        // Make sure the DRAM generation is DDR4
        FAPI_ASSERT( (l_kind.iv_dram_generation == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4),
                     fapi2::MSS_PLUG_RULES_PLANAR_DRAM_GEN()
                     .set_DRAM_GEN(l_kind.iv_target)
                     .set_DIMM_TARGET(l_dimm),
                     "Invalid DRAM generation (%d) plugged in for planar system %s",
                     l_kind.iv_dram_generation, mss::c_str(l_dimm) );

        // Make sure the DRAM type is UDIMM or RDIMM
        FAPI_ASSERT( ((l_kind.iv_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_UDIMM) ||
                      (l_kind.iv_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM)),
                     fapi2::MSS_PLUG_RULES_PLANAR_DRAM_DIMM_TYPE()
                     .set_DIMM_TYPE(l_kind.iv_dimm_type)
                     .set_DIMM_TARGET(l_dimm),
                     "Invalid DIMM type (%d) plugged in for planar system %s",
                     l_kind.iv_dimm_type, mss::c_str(l_dimm) );

        // Make sure the DRAM width is x4 or x8
        FAPI_ASSERT( ((l_kind.iv_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4) ||
                      (l_kind.iv_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8)),
                     fapi2::MSS_PLUG_RULES_PLANAR_DRAM_WIDTH()
                     .set_DRAM_WIDTH(l_kind.iv_dram_width)
                     .set_DIMM_TARGET(l_dimm),
                     "Invalid DRAM width DIMM (%d) plugged in for planar system %s",
                     l_kind.iv_dram_width, mss::c_str(l_dimm));

        // Make sure the DRAM density is 8G or 16G
        FAPI_ASSERT( ((l_kind.iv_dram_density == fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_8G) ||
                      (l_kind.iv_dram_density == fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_16G)),
                     fapi2::MSS_PLUG_RULES_PLANAR_DRAM_DENSITY()
                     .set_DRAM_DENSITY(l_kind.iv_dram_density)
                     .set_DIMM_TARGET(l_dimm),
                     "Invalid DRAM density DIMM (%d) plugged in for planar system %s",
                     l_kind.iv_dram_density, mss::c_str(l_dimm));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce the plug-rules we can do before mss_freq
/// @param[in] i_target FAPI2 target (proc chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_pre_freq(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    uint8_t l_ignore_plug_rules = 0;
    bool l_is_mds = false;

    // If there are no DIMM, we can just get out.
    if (mss::count_dimm(mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target)) == 0)
    {
        FAPI_INF("Skipping plug rule check on %s because it has no DIMM configured", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( mss::attr::get_ignore_mem_plug_rules(l_ignore_plug_rules) );

    // Skip plug rule checks if set to ignore (e.g. on Apollo)
    if (l_ignore_plug_rules == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_YES)
    {
        FAPI_INF("Attribute set to ignore plug rule checking");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check mds plug rules
    for(const auto& l_mcc : i_target.getChildren<fapi2::TARGET_TYPE_MCC>(fapi2::TARGET_STATE_FUNCTIONAL) )
    {
        // Check for MDS/non-MDS dimm mixing
        FAPI_TRY( mss::plug_rule::check_mds(l_mcc) );

        // If an MDS MCC, check media targets
        FAPI_TRY( mss::dimm::is_mds<mss::mc_type::EXPLORER>(l_mcc, l_is_mds) );

        if ( l_is_mds )
        {
            // Loop through omi targets to get OCMB targets
            for(const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(i_target))
            {
                // Check ocmb targets for mixed dimms
                for(const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
                {
                    FAPI_TRY( check_mds_media_controller(l_ocmb) )
                }
            }
        }
    }

    // Check shared reset signal plugging dependencies
    FAPI_TRY( reset_n_dead_load(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce the plug-rules we can do after eff_config
/// @param[in] i_target FAPI2 target (port)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_post_eff_config(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    uint8_t l_ignore_plug_rules = 0;
    uint8_t l_is_planar = 0;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // If there are no DIMM, we can just get out.
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("Skipping plug rule check on %s because it has no DIMM configured", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( mss::attr::get_ignore_mem_plug_rules(l_ignore_plug_rules) );

    // Skip plug rule checks if set to ignore (e.g. on Apollo)
    if (l_ignore_plug_rules == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_YES)
    {
        FAPI_INF("%s Attribute set to ignore plug rule checking", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Enforce planar system plug rules
    FAPI_TRY( mss::attr::get_mem_mrw_is_planar(l_ocmb, l_is_planar) );
    FAPI_INF("%s Enforcing planar plug rules checking", mss::c_str(i_target));
    FAPI_TRY( enforce_planar_plug_rules(i_target, l_is_planar) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for reset_n_dead_load unit testing
/// @param[in] i_reset_group non-functional ocmb reset group
/// @param[in] i_functional_dimms vector of all functional configured DIMMs under proc chip
/// @param[in,out] io_verified_reset_groups list of reset groups we've already verified
/// @param[out] o_callout_ocmbs vector of configured OCMB_CHIPs that need to be called out
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode reset_n_dead_load_helper(const uint64_t i_reset_group,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& i_functional_dimms,
        std::vector<uint8_t>& io_verified_reset_groups,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& o_callout_ocmbs)
{
    o_callout_ocmbs.clear();

    // Check if we've already covered this reset group so we don't do any double callouts
    const auto l_it = std::find(io_verified_reset_groups.begin(), io_verified_reset_groups.end(), i_reset_group);

    if (l_it != io_verified_reset_groups.end())
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& l_dimm : i_functional_dimms)
    {
        uint8_t l_reset_group = 0;
        const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_dimm);
        FAPI_TRY(mss::attr::get_mrw_ocmb_reset_group(l_ocmb, l_reset_group));

        if (l_reset_group == i_reset_group)
        {
            o_callout_ocmbs.push_back(l_ocmb);
        }
    }

    io_verified_reset_groups.push_back(i_reset_group);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce shared reset_n dependency
/// @param[in] i_target proc chip target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode reset_n_dead_load(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // On P10 systems, groups of four DDIMM slots share a reset_n signal. Current DIMMs have open drain
    // receivers for this, which creates a problem in that a dead load (present and not configured DIMM)
    // will draw the reset signal and cause the configured DIMMs to not operate correctly. Newer DDIMMs
    // will be fixed to avoid this problem, but this will remain a problem with many DDIMMs in
    // circulation (both B.0 and A.1)
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Note that we have to start from the DIMM targets because hostboot always returns
    // the architectural limit rather than what is actually installed for every target type
    // except DIMM targets. Plus we have to go through the MEM_PORT targets because we can't go directly
    // from PROC_CHIP to DIMM. Thus, our traversal goes PROC_CHIP->MEM_PORT->DIMM->OCMB_CHIP.
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_functional_dimms;
    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    std::vector<uint8_t> l_verified_reset_groups;

    for(const auto& l_port : l_ports)
    {
        for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port, fapi2::TARGET_STATE_FUNCTIONAL))
        {
            l_functional_dimms.push_back(l_dimm);
        }
    }

    for(const auto& l_port : l_ports)
    {
        for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port, fapi2::TARGET_STATE_PRESENT))
        {
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>> l_callout_ocmbs;
            const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_dimm);
            uint8_t l_reset_group = 0;

            // We're only interested in non-functional targets here
            if (l_ocmb.isFunctional())
            {
                continue;
            }

            FAPI_TRY(mss::attr::get_mrw_ocmb_reset_group(l_ocmb, l_reset_group));

            FAPI_TRY(reset_n_dead_load_helper(l_reset_group, l_functional_dimms, l_verified_reset_groups, l_callout_ocmbs));

            // Call out any OCMBs that share a reset_n signal with the deconfigured OCMB
            for (const auto& l_callout_ocmb : l_callout_ocmbs)
            {
                FAPI_ASSERT_NOEXIT( false,
                                    fapi2::MSS_DDIMM_RESET_N_DEAD_LOAD()
                                    .set_OCMB_RESET_GROUP(l_reset_group)
                                    .set_OCMB_TARGET(l_callout_ocmb),
                                    "%s shares a reset_n signal with a deconfigured DDIMM in group %d",
                                    mss::c_str(l_callout_ocmb), l_reset_group );

                // If our local error is bad, then log it prior to getting a new one
                if(l_rc != fapi2::FAPI2_RC_SUCCESS)
                {
                    fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
                }

                // Save any bad error code so it doesn't get overwritten in the loop
                l_rc = fapi2::current_err;
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
    }

    return l_rc;

fapi_try_exit:
    return fapi2::current_err;
}


} // ns plug_rule

} // ns mss
