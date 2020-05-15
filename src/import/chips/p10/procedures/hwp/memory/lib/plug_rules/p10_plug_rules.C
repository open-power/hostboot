/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/plug_rules/p10_plug_rules.C $ */
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
/// @file p10_plug_rules.C
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/p10_consts.H>
#include <algorithm>

#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/num.H>
#include <mss_generic_attribute_getters.H>

#include <fapi2.H>
#include <lib/plug_rules/p10_plug_rules.H>

namespace mss
{

namespace plug_rule
{

///
/// @brief Enforce the plug-rules we can do after eff_config
/// @param[in] i_target FAPI2 target (port)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_post_eff_config(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    uint8_t l_ignore_plug_rules = 0;

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

    // Check SPD revision limits
    FAPI_TRY( ddimm_spd_revision(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

namespace check
{

///
/// @brief Check that we recognize DDIMM module manufacturing ID
/// @param[in] i_target dimm target
/// @param[in] i_module_mfg_id DIMM module manufacturing ID
/// @param[out] o_latest_content_rev latest SPD content revision
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
///
fapi2::ReturnCode module_mfg_id(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const uint16_t i_module_mfg_id,
                                uint8_t& o_latest_content_rev)
{
    // Check that we can find the ID in our latest revision list
    FAPI_ASSERT( mss::find_value_from_key(LATEST_SPD_CONTENT_REV, i_module_mfg_id, o_latest_content_rev),
                 fapi2::MSS_UNKNOWN_DIMM_MODULE_MFG_ID()
                 .set_DIMM_TARGET(i_target)
                 .set_MODULE_MFG_ID(i_module_mfg_id),
                 "%s DDIMM has unrecognized module manufacturing ID (0x%04X)",
                 mss::c_str(i_target), i_module_mfg_id );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::RC_MSS_UNKNOWN_DIMM_MODULE_MFG_ID;
}

///
/// @brief Check DDIMM base SPD revision versus latest supported
/// @param[in] i_target dimm target
/// @param[in] i_spd_rev base SPD revision
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
/// @note The return code from this function is only used in unit tests.
///
fapi2::ReturnCode base_spd_revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint8_t i_spd_rev)
{
    FAPI_ASSERT( (i_spd_rev >= LATEST_SPD_REV),
                 fapi2::MSS_NON_CURRENT_SPD_REVISION()
                 .set_DIMM_TARGET(i_target)
                 .set_SPD_REVISION(i_spd_rev)
                 .set_LATEST_SPD_REVISION(LATEST_SPD_REV),
                 "%s DDIMM has non-current SPD revision and could be updated (0x%02X < 0x%02X)",
                 mss::c_str(i_target), i_spd_rev, LATEST_SPD_REV );
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::RC_MSS_NON_CURRENT_SPD_REVISION;
}

///
/// @brief Check DDIMM SPD content revision versus latest supported
/// @param[in] i_target dimm target
/// @param[in] i_spd_content_rev SPD content revision
/// @param[in] i_latest_content_rev latest SPD content revision
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
/// @note The return code from this function is only used in unit tests.
///
fapi2::ReturnCode spd_content_revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const uint8_t i_spd_content_rev,
                                       const uint8_t i_latest_content_rev)
{
    FAPI_ASSERT( (i_spd_content_rev >= i_latest_content_rev),
                 fapi2::MSS_NON_CURRENT_SPD_CONTENT_REVISION()
                 .set_DIMM_TARGET(i_target)
                 .set_SPD_CONTENT_REVISION(i_spd_content_rev)
                 .set_LATEST_SPD_CONTENT_REVISION(i_latest_content_rev),
                 "%s DDIMM has non-current SPD content revision and could be updated (0x%02X < 0x%02X)",
                 mss::c_str(i_target), i_spd_content_rev, i_latest_content_rev );
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::RC_MSS_NON_CURRENT_SPD_CONTENT_REVISION;
}

} // namespace check

///
/// @brief Enforce minimum functional DDIMM SPD revision
/// @param[in] i_target port target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode ddimm_spd_revision(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_spd_rev = 0;
    uint8_t l_spd_content_rev = 0;

    FAPI_TRY( mss::attr::get_spd_revision(i_target, l_spd_rev) );
    FAPI_TRY( mss::attr::get_spd_content_revision(i_target, l_spd_content_rev) );

    for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint8_t l_latest_content_rev = 0;
        uint8_t l_dimm_type = 0;
        uint16_t l_module_mfg_id = 0;

        FAPI_TRY( mss::attr::get_dimm_type(l_dimm, l_dimm_type) );

        // These checks are not valid if we're not dealing with a DDIMM, so skip if not
        if (l_dimm_type != fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM)
        {
            FAPI_INF("Skipping SPD revision plug rule check on %s because it is not a DDIMM", mss::c_str(i_target));
            continue;
        }

        FAPI_TRY( mss::attr::get_module_mfg_id(l_dimm, l_module_mfg_id) );

        // First make sure we can get the SPD content revision using the module manufacturing ID
        // This is not necessarily a hard fail, so don't bomb out, but we have to skip the SPD revision checks.
        l_rc = check::module_mfg_id(l_dimm, l_module_mfg_id, l_latest_content_rev);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_INF("Skipping SPD revision plug rule check on %s because it has an unrecognized module manufacturing ID 0x%04X",
                     mss::c_str(i_target), l_module_mfg_id);
            continue;
        }

        // Now check the base SPD revision
        FAPI_ASSERT( (MIN_FUNCTIONAL_SPD_REV <= l_spd_rev),
                     fapi2::MSS_UNSUPPORTED_SPD_REVISION()
                     .set_DIMM_TARGET(l_dimm)
                     .set_SPD_REVISION(l_spd_rev)
                     .set_MINIMUM_FUNCTIONAL_SPD_REVISION(MIN_FUNCTIONAL_SPD_REV),
                     "%s DDIMM has unsupported SPD revision and needs to be updated (0x%02X < 0x%02X)",
                     mss::c_str(l_dimm), l_spd_rev, MIN_FUNCTIONAL_SPD_REV );

        // Don't bother checking the return code here because this check only produces informational logs
        // (and the RC is only used for unit tests)
        check::base_spd_revision(l_dimm, l_spd_rev);

        // Finally check the SPD content revision
        // Don't bother checking the return code here because this check only produces informational logs
        // (and the RC is only used for unit tests)
        check::spd_content_revision(l_dimm, l_spd_content_rev, l_latest_content_rev);
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns plug_rule

} // ns mss
