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

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
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
