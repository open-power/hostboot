/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_attr_engine_traits.H $ */
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
#include <lib/eff_config/explorer_rc_resp_fields.H>

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

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_taa;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_taa;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
        return mss::calc_spd_time_in_ps<exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::SPD_TAA_MIN>(i_spd_data,
                o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, FOUR_RANK_MODE specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::FOUR_RANK_MODE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, SUPPORTED_RCD specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::SUPPORTED_RCD>
{
    using attr_type = fapi2::ATTR_MEM_EFF_SUPPORTED_RCD_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_SUPPORTED_RCD_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_SUPPORTED_RCD;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_supported_rcd(i_target, o_setting);
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
        return mss::attr::set_supported_rcd(i_target, i_setting);
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
        return i_spd_data.module_rcd(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, MODULE_THERMAL_SENSORS specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::MODULE_THERMAL_SENSORS>
{
    using attr_type = fapi2::ATTR_MEM_EFF_MODULE_THERMAL_SENSORS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_MODULE_THERMAL_SENSORS_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_MODULE_THERMAL_SENSORS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_module_thermal_sensors(i_target, o_setting);
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
        return mss::attr::set_module_thermal_sensors(i_target, i_setting);
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
        return i_spd_data.module_thermal_sensors(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_AVAIL specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_AVAIL>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_AVAIL_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_AVAIL_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_AVAIL;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_availability(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_availability(i_target, i_setting);
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
        return i_spd_data.therm_sensor_0_availability(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_SECOND_AVAIL specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_SECOND_AVAIL>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_SECOND_AVAIL_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_SECOND_AVAIL_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_SECOND_AVAIL;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_secondary_availability(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_secondary_availability(i_target, i_setting);
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
        return i_spd_data.therm_sensor_0_secondary_availability(o_setting);
    }
};


///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_TYPE specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_TYPE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_TYPE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_TYPE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_TYPE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_type(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_type(i_target, i_setting);
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
        return i_spd_data.therm_sensor_0_type(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_USAGE specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_USAGE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_USAGE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_usage(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_usage(i_target, i_setting);
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
        constexpr attr_integral_type THERM_SENSOR_0_USAGE_DRAM_AND_PMIC = 0x03;

        const auto l_rc = i_spd_data.therm_sensor_0_usage(o_setting);

        // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
        o_setting = (o_setting == THERM_SENSOR_0_USAGE_DRAM_AND_PMIC ) ?
                    fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_PMIC :
                    o_setting;

        return l_rc;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_I2C_ADDR specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_I2C_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_I2C_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_I2C_ADDR_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_I2C_ADDR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_i2c_addr(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_i2c_addr(i_target, i_setting);
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
        return i_spd_data.therm_sensor_0_i2c_address(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_AVAIL specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_AVAIL>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_AVAIL_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_AVAIL_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_AVAIL;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_availability(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_availability(i_target, i_setting);
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
        return i_spd_data.therm_sensor_1_availability(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_SECOND_AVAIL specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_SECOND_AVAIL>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_SECOND_AVAIL_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_SECOND_AVAIL_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_SECOND_AVAIL;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_secondary_availability(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_secondary_availability(i_target, i_setting);
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
        return i_spd_data.therm_sensor_1_secondary_availability(o_setting);
    }
};


///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_TYPE specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_TYPE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_TYPE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_TYPE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_TYPE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_type(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_type(i_target, i_setting);
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
        return i_spd_data.therm_sensor_1_type(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_USAGE specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_USAGE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_USAGE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_usage(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_usage(i_target, i_setting);
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
        constexpr attr_integral_type THERM_SENSOR_1_USAGE_DRAM_AND_PMIC = 0x03;

        const auto l_rc = i_spd_data.therm_sensor_1_usage(o_setting);

        // Note DRAM_AND_PMIC usage is not supported in OCC, so treat that setting as PMIC only
        o_setting = (o_setting == THERM_SENSOR_1_USAGE_DRAM_AND_PMIC ) ?
                    fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_PMIC :
                    o_setting;

        return l_rc;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_I2C_ADDR specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_I2C_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_I2C_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_I2C_ADDR_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_I2C_ADDR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_i2c_addr(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_i2c_addr(i_target, i_setting);
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
        return i_spd_data.therm_sensor_1_i2c_address(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_DIFF_AVAIL specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_DIFF_AVAIL>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_AVAIL_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_AVAIL_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_DIFF_AVAIL;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_differential_availability(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_differential_availability(i_target, i_setting);
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
        return i_spd_data.therm_sensor_differential_availability(o_setting);
    }
};


///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_DIFF_TYPE specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_DIFF_TYPE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_TYPE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_TYPE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_DIFF_TYPE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_differential_type(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_differential_type(i_target, i_setting);
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
        return i_spd_data.therm_sensor_differential_type(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_DIFF_USAGE specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_DIFF_USAGE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_DIFF_USAGE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_differential_usage(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_differential_usage(i_target, i_setting);
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
        return i_spd_data.therm_sensor_differential_usage(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_DIFF_I2C_ADDR specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_DIFF_I2C_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_I2C_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_I2C_ADDR_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_DIFF_I2C_ADDR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_differential_i2c_addr(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_differential_i2c_addr(i_target, i_setting);
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
        return i_spd_data.therm_sensor_differential_i2c_address(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_SECOND_I2C_ADDR specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_SECOND_I2C_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_SECOND_I2C_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_SECOND_I2C_ADDR_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_SECOND_I2C_ADDR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_secondary_i2c_addr(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_secondary_i2c_addr(i_target, i_setting);
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
        return i_spd_data.therm_sensor_0_secondary_i2c_address(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_SECOND_I2C_ADDR specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_SECOND_I2C_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_SECOND_I2C_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_SECOND_I2C_ADDR_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_SECOND_I2C_ADDR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_secondary_i2c_addr(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_secondary_i2c_addr(i_target, i_setting);
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
        return i_spd_data.therm_sensor_1_secondary_i2c_address(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_SECOND_LOCATION specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_SECOND_LOCATION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_SECOND_LOCATION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_SECOND_LOCATION_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_SECOND_LOCATION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_secondary_location(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_secondary_location(i_target, i_setting);
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
        return i_spd_data.therm_sensor_1_secondary_location(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_SECOND_LOCATION specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_SECOND_LOCATION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_SECOND_LOCATION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_SECOND_LOCATION_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_SECOND_LOCATION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_secondary_location(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_secondary_location(i_target, i_setting);
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
        return i_spd_data.therm_sensor_0_secondary_location(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_1_LOCATION specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_1_LOCATION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_LOCATION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_1_LOCATION_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_1_LOCATION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_1_location(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_1_location(i_target, i_setting);
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
        return i_spd_data.therm_sensor_1_location(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_eff_engine_fields, THERM_SENSOR_0_LOCATION specialization
///
template< proc_type P >
struct attrEngineTraits<P, exp::attr_eff_engine_fields, exp::attr_eff_engine_fields::THERM_SENSOR_0_LOCATION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_LOCATION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_THERM_SENSOR_0_LOCATION_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_THERM_SENSOR_0_LOCATION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_therm_sensor_0_location(i_target, o_setting);
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
        return mss::attr::set_therm_sensor_0_location(i_target, i_setting);
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
        return i_spd_data.therm_sensor_0_location(o_setting);
    }
};

////////////////////////////////////////////////////////
// Traits for explorer specific generic_metadata_fields
////////////////////////////////////////////////////////

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note AXONE, DIMM_TYPE_METADATA specialization
///
template <proc_type P>
struct attrEngineTraits<P, generic_metadata_fields, generic_metadata_fields::DIMM_TYPE_METADATA>
{
    using attr_type = fapi2::ATTR_MEM_DIMM_TYPE_METADATA_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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
    using attr_type_to_set = attr_integral_type;
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

////////////////////////////////////////////////////////
// attrEngineTraits for explorer specific attr_rc_resp_engine_fields
////////////////////////////////////////////////////////

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC00 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC00>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC00_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC00_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC00;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc00(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc00(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC00>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC00>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC01 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC01>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC01_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC01_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC01;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc01(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc01(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC01>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC01>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC03 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC03>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC03_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC03_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC03;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc03(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc03(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC03>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC03>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC04 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC04>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC04_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC04_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC04;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc04(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc04(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC04>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC04>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC05 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC05>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC05_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC05_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC05;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc05(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc05(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC05>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC05>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC0B specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC0B>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC0B_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC0B_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC0B;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc0b(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc0b(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC0B>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC0B>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC0E specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC0E>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC0E_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC0E_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC0E;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc0e(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc0e(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC0E>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC0E>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC0F specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC0F>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC0F_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC0F_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC0F;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc0f(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc0f(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC0F>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC0F>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC1X specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC1X>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC1X_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC1X_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC1X;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc1x(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc1x(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC1X>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC1X>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F0RC7X specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F0RC7X>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC7X_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F0RC7X_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F0RC7X;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f0rc7x(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f0rc7x(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F0RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC7X>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F0RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F0RC7X>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F1RC00 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F1RC00>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC00_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC00_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F1RC00;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f1rc00(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f1rc00(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F1RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC00>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F1RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC00>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F1RC02 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F1RC02>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC02_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC02_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F1RC02;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f1rc02(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f1rc02(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F1RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC02>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F1RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC02>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F1RC03 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F1RC03>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC03_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC03_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F1RC03;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f1rc03(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f1rc03(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F1RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC03>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F1RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC03>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F1RC04 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F1RC04>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC04_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC04_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F1RC04;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f1rc04(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f1rc04(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        std::vector<attr_integral_type> l_data;

        if(mss::index(i_rc_resp.get_target()) == 0)
        {
            get_data_F1RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC04>(i_rc_resp.get_target(), l_data, o_setting));
        }
        else
        {
            get_data_F1RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC04>(i_rc_resp.get_target(), l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note attr_rc_resp_engine_fields, F1RC05 specialization
///
template <proc_type P>
struct attrEngineTraits<P, exp::attr_rc_resp_engine_fields, exp::attr_rc_resp_engine_fields::F1RC05>
{
    using attr_type = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC05_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MSS_EXP_RESP_DDR4_F1RC05_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_F1RC05;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_exp_resp_ddr4_f1rc05(i_target, o_setting);
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
        return mss::attr::set_exp_resp_ddr4_f1rc05(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const exp::rc_resp_adaptor& i_rc_resp,
            attr_integral_type& o_setting)
    {
        // Reusable data buffer
        const auto l_dimm = i_rc_resp.get_target();

        std::vector<attr_integral_type> l_data;

        if(mss::index(l_dimm) == 0)
        {
            get_data_F1RC_D0(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC05>(l_dimm, l_data, o_setting));
        }
        else
        {
            get_data_F1RC_D1(i_rc_resp, l_data);
            FAPI_TRY(exp::reader<exp::rc_rsp_fields::F1RC05>(l_dimm, l_data, o_setting));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

} // namespace mss

#endif
