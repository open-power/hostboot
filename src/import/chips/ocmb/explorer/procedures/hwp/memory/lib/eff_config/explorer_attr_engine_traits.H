/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_attr_engine_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file explorer_attr_engine_traits.H
/// @brief Trait class definitions for explorer attrs
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_EXPLORER_ATTR_ENGINE_TRAITS_H_
#define _MSS_EXPLORER_ATTR_ENGINE_TRAITS_H_

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_generic_attribute_setters.H>
#include <mss_generic_attribute_getters.H>

namespace mss
{

////////////////////////////////////////////////////////
// Explorer specific traits for setTimingTraits
////////////////////////////////////////////////////////

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note exp::attr_eff_engine_fields, SPD_TAA_MIN
///
template< >
struct setTimingTraits< exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::SPD_TAA_MIN >
{
    static constexpr const char* TIMING_NAME = "tAAmin";

    static constexpr spd_facade_fptr get_timing_in_mtb = &spd::facade::min_taa;
    static constexpr spd_facade_fptr get_timing_in_ftb = &spd::facade::fine_offset_min_taa;
};

////////////////////////////////////////////////////////
// Traits for explorer specific attr_eff_engine_fields
////////////////////////////////////////////////////////


///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, ATTR_EFF_BASE_CASE specialization
/// NOP for base case needed to trigger partial specialization of attr_engine
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::ATTR_EFF_BASE_CASE> {};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, ADDRESS_MIRROR specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::ADDRESS_MIRROR>
{
    using attr_type = fapi2::ATTR_MEM_EXP_DRAM_ADDRESS_MIRRORING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EXP_DRAM_ADDRESS_MIRRORING_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_EXP_DRAM_ADDRESS_MIRRORING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_dram_address_mirroring(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_exp_dram_address_mirroring(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.address_mirroring(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, BYTE_ENABLES specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::BYTE_ENABLES>
{
    using attr_type = fapi2::ATTR_MEM_EFF_BYTE_ENABLES_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_BYTE_ENABLES_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_BYTE_ENABLES;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_byte_enables(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_byte_enables(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.byte_enables(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, NIBBLE_ENABLES specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::NIBBLE_ENABLES>
{
    using attr_type = fapi2::ATTR_MEM_EFF_NIBBLE_ENABLES_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_NIBBLE_ENABLES_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_NIBBLE_ENABLES;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_nibble_enables(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_nibble_enables(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.nibble_enables(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, SPD_TAA_MIN specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::SPD_TAA_MIN>
{
    using attr_type = fapi2::ATTR_MEM_EXP_SPD_TAA_MIN_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EXP_SPD_TAA_MIN_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_TAA_MIN;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_spd_taa_min(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_exp_spd_taa_min(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_ps<exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::SPD_TAA_MIN>(i_spd_data,
                o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, FOUR_RANK_MODE specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::FOUR_RANK_MODE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_FOUR_RANK_MODE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_four_rank_mode(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_four_rank_mode(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        constexpr auto FOUR_RANK_MODE_BIT = 7; // From SPEC
        attr_integral_type l_spd_four_rank_mode = 0;
        FAPI_TRY(i_spd_data.compatabilty_modes(l_spd_four_rank_mode));

        o_setting = fapi2::buffer<uint8_t>(l_spd_four_rank_mode).getBit<FOUR_RANK_MODE_BIT>();

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, DDP_COMPATIBILITY specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::DDP_COMPATIBILITY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DDP_COMPATIBILITY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DDP_COMPATIBILITY_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_DDP_COMPATIBILITY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_ddp_compatibility(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_ddp_compatibility(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        constexpr auto DDP_COMPATIBILITY_BIT = 6; // From SPEC
        attr_integral_type l_spd_ddp_compatibility = 0;
        FAPI_TRY(i_spd_data.compatabilty_modes(l_spd_ddp_compatibility));

        o_setting = fapi2::buffer<uint8_t>(l_spd_ddp_compatibility).getBit<DDP_COMPATIBILITY_BIT>();

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, TSV_8H_SUPPORT specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::TSV_8H_SUPPORT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_TSV_8H_SUPPORT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_TSV_8H_SUPPORT_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_TSV_8H_SUPPORT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_tsv_8h_support(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_tsv_8h_support(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.compatabilty_modes(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, PSTATES specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::PSTATES>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PSTATES_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PSTATES_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_PSTATES;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_pstates(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_pstates(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.num_p_states(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, MRAM_SUPPORT specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::MRAM_SUPPORT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_MRAM_SUPPORT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_MRAM_SUPPORT_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_MRAM_SUPPORT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_mram_support(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_mram_support(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        constexpr auto MRAM_SUPPORT_BIT = 4; // From SPEC
        attr_integral_type l_spd_ddp_compatibility = 0;
        FAPI_TRY(i_spd_data.compatabilty_modes(l_spd_ddp_compatibility));

        o_setting = fapi2::buffer<uint8_t>(l_spd_ddp_compatibility).getBit<MRAM_SUPPORT_BIT>();

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, SPD_CL_SUPPORTED specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::SPD_CL_SUPPORTED>
{
    using attr_type = fapi2::ATTR_MEM_EXP_SPD_CL_SUPPORTED_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EXP_SPD_CL_SUPPORTED_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_SPD_CL_SUPPORTED;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_spd_cl_supported(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_exp_spd_cl_supported(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        uint64_t l_val = 0;
        FAPI_TRY(i_spd_data.supported_cas_latencies(l_val));

        o_setting = static_cast<attr_integral_type>(l_val);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note AXONE, DIMM_TYPE_METADATA specialization
///
template< proc_type P >
struct attrEngineTraits<P, generic_metadata_fields, generic_metadata_fields::DIMM_TYPE_METADATA>
{
    using attr_type = fapi2::ATTR_MEM_DIMM_TYPE_METADATA_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_DIMM_TYPE_METADATA_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_TYPE_METADATA;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the MCS target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dimm_type_metadata(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the MCS target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_dimm_type_metadata(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_target the DIMM target
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        return mss::attr::get_dimm_type(i_target, o_setting);
    }
};

///
/// @brief Traits associated with DIMM positioning
/// @class dimmPosTraits - EXPLORER specializattion
///
template<>
class dimmPosTraits<mss::mc_type::EXPLORER>
{
    private:
        using PT = posTraits<fapi2::TARGET_TYPE_DIMM>;
        using MT = mss::mcTypeTraits<mc_type::EXPLORER>;

    public:
        // Public interface syntatic sugar
        using pos_type = PT::pos_type;

        // Proc 0 would be DIMM0 - 31,  proc 1 would be DIMM32 - 63, etc. 32 is the stride between processors
        static constexpr auto DIMM_STRIDE_PER_PROC = 32;
        static constexpr auto TOTAL_DIMM = MT::MC_PER_PROC * MT::MI_PER_MC * MT::MCC_PER_MI *
                                           MT::OMI_PER_MCC * MT::OCMB_PER_OMI * MT::PORTS_PER_OCMB * MT::DIMMS_PER_PORT;

        ///
        /// @brief Return the PROC_CHIP parent of a DIMM
        /// @param[in] i_target the dimm target
        /// @return the fapi2 proc target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_proc(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
        {
            // Using fapi2 rather than mss::find as this is pretty low level stuff.
            const auto l_ocmb = i_target.getParent<fapi2::TARGET_TYPE_MEM_PORT>().getParent<fapi2::TARGET_TYPE_OCMB_CHIP>();
            const auto l_mc = l_ocmb.getParent<fapi2::TARGET_TYPE_OMI>().getParent<fapi2::TARGET_TYPE_MC>();
            return l_mc.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note generic_metadata_fields, DRAM_GEN_METADATA specialization
///
template< proc_type P >
struct attrEngineTraits<P, generic_metadata_fields, generic_metadata_fields::DRAM_GEN_METADATA>
{
    using attr_type = fapi2::ATTR_MEM_DRAM_GEN_METADATA_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_DRAM_GEN_METADATA_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_GEN_METADATA;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the MCS target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_gen_metadata(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the MCS target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_dram_gen_metadata(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_target the DIMM target
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        return mss::attr::get_dram_gen(i_target, o_setting);
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note generic_metadata_fields, DIMM_POS_METADATA specialization
///
template< proc_type P >
struct attrEngineTraits<P, generic_metadata_fields, generic_metadata_fields::DIMM_POS_METADATA>
{
    using attr_type = fapi2::ATTR_MEM_DIMM_POS_METADATA_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_DIMM_POS_METADATA_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_POS_METADATA;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the MCS target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dimm_pos_metadata(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the MCS target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_dimm_pos_metadata(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_target the DIMM target
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        using TT = mss::dimmPosTraits<mss::mc_type::EXPLORER>;
        return gen::dimm_pos<TT>(i_target, o_setting);
    }
};

}//mss

#endif
