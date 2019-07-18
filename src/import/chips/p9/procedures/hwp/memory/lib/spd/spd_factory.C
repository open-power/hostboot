/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/spd_factory.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
/* [+] Evan Lojewski                                                      */
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
/// @file spd_factory.C
/// @brief SPD factory and functions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

// std lib
#include <map>
#include <vector>

// fapi2
#include <fapi2.H>
#include <fapi2_spd_access.H>

// mss lib
#include <lib/spd/spd_factory.H>
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/spd/rdimm/ddr4/rdimm_decoder_ddr4.H>
#include <generic/memory/lib/spd/lrdimm/ddr4/lrdimm_decoder_ddr4.H>
#include <generic/memory/lib/spd/common/rcw_settings.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/spd/rdimm/ddr4/rdimm_raw_cards.H>
#include <generic/memory/lib/spd/lrdimm/ddr4/lrdimm_raw_cards.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <lib/utils/mss_nimbus_conversions.H>
#include <lib/utils/nimbus_find.H>
#include <lib/eff_config/timing.H>
#include <lib/shared/mss_const.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace spd
{

///
/// @brief Retrieve current raw card settings
/// based on dimm type and raw card reference rev
/// @param[in] i_target dimm target
/// @param[in] i_data SPD data
/// @param[out] o_raw_card raw card settings
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode raw_card_factory(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                   const facade& i_data,
                                   rcw_settings& o_raw_card)
{
    // Lets find out what raw card we are and grab the right
    // raw card settings
    uint8_t l_dimm_type = 0;
    uint8_t l_hybrid = 0;
    uint8_t l_hybrid_type = 0;
    uint8_t l_ref_raw_card_rev = 0;

    FAPI_TRY(i_data.base_module(l_dimm_type) );
    FAPI_TRY(i_data.hybrid(l_hybrid));
    FAPI_TRY(i_data.hybrid_media(l_hybrid_type));
    FAPI_TRY(i_data.reference_raw_card(l_ref_raw_card_rev));

    FAPI_INF("Retrieved dimm_type: %d, raw card reference: 0x%lx from SPD for %s",
             l_dimm_type, l_ref_raw_card_rev, spd::c_str(i_target));

    switch(l_dimm_type)
    {
        case RDIMM:
        case SORDIMM:
        case MINIRDIMM:

            // TODO:RTC178807 - Update how NVDIMMs are handled once more are up and running in the lab
            // NVDIMM is currently considered differently than all other rdimm raw cards, due to settings differences
            if((l_hybrid == fapi2::ENUM_ATTR_EFF_HYBRID_IS_HYBRID) &&
               (l_hybrid_type == fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NVDIMM))
            {
                l_ref_raw_card_rev = mss::rdimm::raw_card_rev::NVDIMM;
                FAPI_INF("%s is an NVDIMM, overwrote l_ref_raw_card_rev to be 0x%02x",
                         mss::spd::c_str(i_target),
                         l_ref_raw_card_rev);
            }

            FAPI_TRY( find_raw_card( i_target,
                                     RDIMM,
                                     l_ref_raw_card_rev,
                                     mss::rdimm::RAW_CARDS,
                                     o_raw_card) );
            break;

        case LRDIMM:
            FAPI_TRY( find_raw_card( i_target,
                                     LRDIMM,
                                     l_ref_raw_card_rev,
                                     mss::lrdimm::RAW_CARDS,
                                     o_raw_card) );
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_DIMM_TYPE()
                         .set_DIMM_TYPE(l_dimm_type)
                         .set_DIMM_TARGET(i_target)
                         .set_FUNCTION(mss::ffdc_function_codes::RAW_CARD_FACTORY),
                         "Recieved invalid dimm type: %d for %s",
                         l_dimm_type, mss::spd::c_str(i_target) );
            break;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Wrapper function for finding the raw card -- helper for testing
/// @param[in] i_target the dimm target
/// @param[in] i_dimm_type
/// @param[in] i_ref_raw_card_rev for FFDC
/// @param[in] i_mrw_supported_rc
/// @param[in] i_map raw card map
/// @param[out] o_rcw raw card setting
/// @return rcw_settings vector of rcw settings
/// @note This specialization is suited for creating a cache with custom
/// SPD data (e.g. testing custom SPD).
/// @note MRW attributes are read-only, this function provides a mechanism to test
/// different code paths.
///
fapi2::ReturnCode find_raw_card_helper( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                        const uint64_t i_dimm_type,
                                        const uint8_t i_ref_raw_card_rev,
                                        const uint8_t i_mrw_supported_rc,
                                        const std::vector<std::pair<uint8_t, rcw_settings> >& i_map,
                                        rcw_settings& o_raw_card)
{
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
    const auto l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(i_target);

    FAPI_INF("Unsupported raw cards %s allowed for %s",
             i_mrw_supported_rc ? "are" : "are NOT",
             mss::spd::c_str(i_target));

    FAPI_ASSERT(find_value_from_key( i_map, i_ref_raw_card_rev, o_raw_card),
                fapi2::MSS_INVALID_RAW_CARD(fapi2::FAPI2_ERRL_SEV_RECOVERED, l_rc)
                .set_DIMM_TYPE(i_dimm_type)
                .set_RAW_CARD_REV(i_ref_raw_card_rev)
                .set_DIMM_TARGET(i_target)
                .set_MCA_TARGET(l_mca),
                "Invalid reference raw card received for %s: %d for %s",
                (i_dimm_type == RDIMM) ? "RDIMM" : "LRDIMM",
                i_ref_raw_card_rev,
                mss::spd::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    // If system owners or open power partners decide they want to allow unsupported RCWs,
    // we'll create a hidden log for debugging purposes and continue on w/default settings.
    // We want the log for debugging purposes because these settings can break
    if( i_mrw_supported_rc == fapi2::ENUM_ATTR_MSS_MRW_ALLOW_UNSUPPORTED_RCW_ENABLE )
    {
        fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        l_rc = fapi2::FAPI2_RC_SUCCESS;
        o_raw_card = (i_dimm_type == RDIMM) ? rdimm_rc_default : lrdimm_rc_default;
    }

    return l_rc;
}

///
/// @brief Wrapper function for finding the raw card
/// @param[in] i_target the dimm target
/// @param[in] i_dimm_type
/// @param[in] i_ref_raw_card_rev for FFDC
/// @param[in] i_map raw card map
/// @param[out] o_rcw raw card setting
/// @return rcw_settings vector of rcw settings
/// @note This specialization is suited for creating a cache with custom
/// SPD data (e.g. testing custom SPD).
///
fapi2::ReturnCode find_raw_card( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_dimm_type,
                                 const uint8_t i_ref_raw_card_rev,
                                 const std::vector<std::pair<uint8_t, rcw_settings> >& i_map,
                                 rcw_settings& o_raw_card)
{
    uint8_t l_allow_unsupported_rcw = 0;
    FAPI_TRY( mrw_allow_unsupported_rcw(l_allow_unsupported_rcw) );

    FAPI_TRY( find_raw_card_helper(i_target, i_dimm_type, i_ref_raw_card_rev, l_allow_unsupported_rcw, i_map, o_raw_card),
              "Failed find_raw_card_helper for %s", mss::spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

}// spd
}// mss
