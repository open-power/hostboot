/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_factory_pattern.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file spd_factory_pattern.C
/// @brief SPD factory pattern implementation
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <generic/memory/lib/spd/spd_factory_pattern.H>

namespace mss
{
namespace spd
{

///
/// @brief constexpr ctor
/// @param[in] i_dram_gen DRAM generation
/// @param[in] i_spd_param DIMM type
/// @param[in] i_rev SPD revision
///
module_key::module_key(const uint8_t i_dram_gen,
                       const module_params i_spd_param,
                       const uint8_t i_rev):
    iv_rev(i_rev),
    iv_dram_gen(i_dram_gen),
    iv_module_type(i_spd_param)
{}

///
/// @brief less-than operator
/// @param[in] i_rhs the module_key
/// @return true or false
///
bool module_key::operator<(const module_key& i_rhs) const
{
    // Impose weak strict ordering for dram_gen
    // by dram gen, dimm type, and then revision
    if(iv_dram_gen != i_rhs.iv_dram_gen)
    {
        return iv_dram_gen < i_rhs.iv_dram_gen;
    }

    // If we are here than iv_module_type == i_key.iv_module_type
    // Impose weak strict ordering for encoding_level
    if( iv_module_type != i_rhs.iv_module_type)
    {
        return iv_module_type < i_rhs.iv_module_type;
    }

    // If we are here than iv_encoding_level == i_key.iv_encoding_leve
    // Impose weak strict ordering for additions_level
    if( iv_rev != i_rhs.iv_rev)
    {
        return  iv_rev < i_rhs.iv_rev;
    }

    return false;
}

///
/// @brief ctor
/// @param[in] i_target the DIMM target
/// @param[in] i_key the module_key
///
rev_fallback::rev_fallback(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const module_key& i_key):
    iv_target(i_target),
    iv_key(i_key),
    iv_encoding_level(0),
    iv_additions_level(0),
    LRDIMM_DDR4_V1_0{DDR4, LRDIMM_MODULE, rev::V1_0},
    LRDIMM_DDR4_V1_1{DDR4, LRDIMM_MODULE, rev::V1_1},
    LRDIMM_DDR4_V1_2{DDR4, LRDIMM_MODULE, rev::V1_2},
    RDIMM_DDR4_V1_0{DDR4, RDIMM_MODULE, rev::V1_0},
    RDIMM_DDR4_V1_1{DDR4, RDIMM_MODULE, rev::V1_1},
    NVDIMM_DDR4_V1_0{DDR4, NVDIMM_MODULE, rev::V1_0},
    NVDIMM_DDR4_V1_1{DDR4, NVDIMM_MODULE, rev::V1_1},
    DDIMM_DDR4_V0_3{DDR4, DDIMM_MODULE, rev::V0_3}
{
    // Member variable initialization
    fapi2::buffer<uint8_t> l_buffer(i_key.iv_rev);
    l_buffer.extractToRight<ENCODINGS_REV_START, LEN>(iv_encoding_level);
    l_buffer.extractToRight<ADDITIONS_REV_START, LEN>(iv_additions_level);

    // Setup pre-defined maps available to search through
    // diff mappings because each map has an independently
    // managed revision.
    iv_rdimm_rev_map[RDIMM_DDR4_V1_0] = rev::V1_0;
    iv_rdimm_rev_map[RDIMM_DDR4_V1_1] = rev::V1_1;

    iv_lrdimm_rev_map[LRDIMM_DDR4_V1_0] = rev::V1_0;
    iv_lrdimm_rev_map[LRDIMM_DDR4_V1_1] = rev::V1_1;
    iv_lrdimm_rev_map[LRDIMM_DDR4_V1_2] = rev::V1_2;

    iv_nvdimm_rev_map[NVDIMM_DDR4_V1_0] = rev::V1_1;
    iv_nvdimm_rev_map[NVDIMM_DDR4_V1_1] = rev::V1_1;

    iv_ddimm_rev_map[DDIMM_DDR4_V0_3] = rev::V0_3;

    // Another small map to select the right map based on module
    iv_spd_param_map[RDIMM_MODULE] = iv_rdimm_rev_map;
    iv_spd_param_map[LRDIMM_MODULE] = iv_lrdimm_rev_map;
    iv_spd_param_map[NVDIMM_MODULE] = iv_nvdimm_rev_map;
    iv_spd_param_map[DDIMM_MODULE] = iv_ddimm_rev_map;
}

///
/// @brief Retrieves highest supported SPD revision
/// @param[out] o_rev SPD revision
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode rev_fallback::get_supported_rev(uint8_t& o_rev) const
{
    std::map<module_key, uint8_t> l_map;

    auto it = iv_spd_param_map.find(iv_key.iv_module_type);
    FAPI_ASSERT(it != iv_spd_param_map.end(),
                fapi2::MSS_INVALID_SPD_PARAMETER_RECEIVED()
                .set_SPD_PARAM(iv_key.iv_module_type)
                .set_FUNCTION_CODE(GET_SUPPORTED_REV)
                .set_TARGET(iv_target),
                "Invalid SPD parameter received %d for %s",
                iv_key.iv_module_type, spd::c_str(iv_target));

    l_map = it->second;
    FAPI_TRY( check_encoding_level(l_map) );

    // The logic is easier to handle only additions level changes.
    // This source will need to be updated to handle encodings level changes
    // (rare occurance that hasn't happened yet...) and will be caught with the conditional above.
    select_highest_rev(l_map, o_rev);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to select the largest SPD revision
/// @param[in] i_map a map of supported SPD revisions for a certain SPD param
/// @param[out] o_rev the SPD Revision
/// @return FAPI2_RC_SUCCESS iff okay
///
void rev_fallback::select_highest_rev( const std::map<module_key, uint8_t>& i_map,
                                       uint8_t& o_rev) const
{
    // When encoding revisions are the same and only
    // addition revisions differ, setting are backward
    // compatible.  This means if we hit a case where
    // the additions level is not in our existing list of
    // decoders we can default to the highest decoded revision.
    // (e.g. If the DRAM is rev 1.3 but we have only decoded up
    // to rev 1.1, we can safely default to rev 1.1 accepting
    // that we lose features that may exist in higher revisions).
    auto it = i_map.end();
    o_rev = (--it)->second;
}

///
/// @brief Helper function to check non-backward compatible encoding level changes
/// @param[in] i_map Map of supported SPD revisions for a certain SPD param
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode rev_fallback::check_encoding_level(const std::map<module_key, uint8_t>& i_map) const
{
    // A change in encoding revision breaks backward compatability,
    // (e.g. revision 2.# is not backwards compatible with revision 1.#,
    // for some integer #).
    auto it = --(i_map.end());
    const uint8_t l_highest_possible_rev = it->second;
    const fapi2::buffer<uint8_t> l_buffer(l_highest_possible_rev);

    uint8_t l_last_valid_encoding_lvl = 0;
    l_buffer.extractToRight<ENCODINGS_REV_START, LEN>(l_last_valid_encoding_lvl);

    FAPI_INF("Highest valid rev 0x%02x, Highest valid encoding level %d, encoding level received %d for %s",
             l_highest_possible_rev, l_last_valid_encoding_lvl, iv_encoding_level, spd::c_str(iv_target));

    FAPI_ASSERT( iv_encoding_level <= l_last_valid_encoding_lvl,
                 fapi2::MSS_SPD_REV_ENCODING_LEVEL_NOT_SUPPORTED()
                 .set_ENCODING_LEVEL(iv_encoding_level)
                 .set_TARGET(iv_target),
                 "SPD revision encoding level (%d) is greater than largest decode (%d) for %s",
                 iv_encoding_level, l_last_valid_encoding_lvl, spd::c_str(iv_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ctor
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_data SPD data in a vector reference
/// @param[out] o_rc FAPI2_RC_SUCCESS iff okay
///
factories::factories(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const std::vector<uint8_t>& i_spd_data,
                     fapi2::ReturnCode& o_rc):
    iv_target(i_target),
    iv_spd_data(i_spd_data)
{
    FAPI_TRY( (reader<init_fields::REVISION, spd::rev::GEN_SEC_MAX>(i_target, i_spd_data, iv_rev)),
              "Failed to read REVISION field for %s", spd::c_str(i_target) );
    FAPI_TRY( (reader<init_fields::BASE_MODULE, spd::rev::GEN_SEC_MAX>(i_target, i_spd_data, iv_base_module_type)),
              "Failed to read BASE_MODULE field for %s", spd::c_str(i_target) );
    FAPI_TRY( (reader<init_fields::DEVICE_TYPE, spd::rev::GEN_SEC_MAX>(i_target, i_spd_data, iv_dram_gen)),
              "Failed to read DEVICE_TYPE field for %s", spd::c_str(i_target) );
    FAPI_TRY( (reader<init_fields::HYBRID, spd::rev::GEN_SEC_MAX>(i_target, i_spd_data, iv_hybrid)),
              "Failed to read  HYBRID field for %s", spd::c_str(i_target) );
    FAPI_TRY( (reader<init_fields::HYBRID_MEDIA, spd::rev::GEN_SEC_MAX>(i_target, i_spd_data,
               iv_hybrid_media)),
              "Failed to read HYBRID_MEDIA field for %s", spd::c_str(i_target) );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
}

///
/// @brief creates base_cnfg_decoder object
/// @param[out] o_decoder_ptr the base_cnfg_decoder object ptr
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode factories::create_decoder( std::shared_ptr<base_cnfg_decoder>& o_decoder_ptr ) const
{
    module_params l_param = UNINITIALIZED;
    FAPI_TRY(base_cfg_select_param(l_param));

    {
        auto l_factory_key = module_key(iv_dram_gen, l_param, iv_rev);

        const module_factory<base_cnfg_decoder> l_decoder(iv_target, iv_spd_data);
        FAPI_TRY( l_decoder.make_object(l_factory_key, o_decoder_ptr) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief creates dimm_module_decoder object
/// @param[out] o_decoder_ptr the dimm_module_decoder object ptr
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode factories::create_decoder( std::shared_ptr<dimm_module_decoder>& o_decoder_ptr ) const
{
    module_params l_param = UNINITIALIZED;
    FAPI_TRY(dimm_module_select_param(l_param));

    {
        auto l_factory_key = module_key(iv_dram_gen, l_param, iv_rev);

        const module_factory<dimm_module_decoder> l_decoder(iv_target, iv_spd_data);
        FAPI_TRY( l_decoder.make_object(l_factory_key, o_decoder_ptr) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to select SPD parameter for the dimm module
/// @param[out] o_param SPD parameter
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode factories::dimm_module_select_param(module_params& o_param) const
{
    switch(iv_base_module_type)
    {
        case RDIMM:
        case SORDIMM:
        case MINIRDIMM:
            o_param = RDIMM_MODULE;
            break;

        case LRDIMM:
            o_param = LRDIMM_MODULE;
            break;

        case DDIMM:
            o_param = DDIMM_MODULE;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::MSS_INVALID_DIMM_MODULE_RECEIVED_FOR_SPD_REV_FALLBACK()
                        .set_DIMM_MODULE(iv_base_module_type)
                        .set_SPD_REV(iv_rev)
                        .set_DRAM_GEN(iv_dram_gen)
                        .set_DIMM_TARGET(iv_target),
                        "Invalid DIMM module recieved (%d) for %s",
                        iv_base_module_type, spd::c_str(iv_target));
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to select SPD parameter for the base cfg
/// @param[out] o_param SPD parameter
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode factories::base_cfg_select_param(module_params& o_param) const
{
    if(iv_hybrid == HYBRID && iv_hybrid_media == NVDIMM_HYBRID)
    {
        // The general section used for NVDIMMs is different than
        // those for LRDIMM and RDIMM modules.
        o_param = NVDIMM_MODULE;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If we are here let's make sure we are not hybrid, sanity
    // check to assure we don't have invalid hybrid combination
    FAPI_ASSERT(iv_hybrid == NOT_HYBRID &&
                iv_hybrid_media == NOT_HYBRID,
                fapi2::MSS_INVALID_HYBRID_MODULE().
                set_HYBRID(iv_hybrid).
                set_HYBRID_MEDIA(iv_hybrid_media).
                set_FUNCTION(BASE_CFG_PARAM_SELECT).
                set_TARGET(iv_target),
                "Invalid hybrid (%d) or hybrid_media (%d) for %s",
                iv_hybrid, iv_hybrid_media, spd::c_str(iv_target));

    FAPI_TRY(dimm_module_select_param(o_param));

fapi_try_exit:
    return fapi2::current_err;
}

}// spd
}// mss
