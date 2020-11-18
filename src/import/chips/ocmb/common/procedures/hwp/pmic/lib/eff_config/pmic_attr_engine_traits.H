/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/eff_config/pmic_attr_engine_traits.H $ */
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
/// @file pmic_attr_engine_traits.H
/// @brief Trait class definitions for pmic attrs
///

// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_PMIC_ATTR_ENGINE_TRAITS_H_
#define _MSS_PMIC_ATTR_ENGINE_TRAITS_H_

#include <fapi2.H>
#include <lib/utils/pmic_consts.H>
#include <lib/eff_config/pmic_efd_processing.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <lib/mss_pmic_attribute_getters.H>
#include <lib/mss_pmic_attribute_setters.H>

namespace mss
{

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, ATTR_EFF_BASE_CASE partial specialization
/// NOP for base case needed to trigger partial specialization of attr_engine
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::ATTR_EFF_BASE_CASE> {};

//----------------------------------------
// PMIC 0
//----------------------------------------

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_MFG_ID partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_MFG_ID>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_MFG_ID_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_MFG_ID_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_MFG_ID;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_mfg_id(i_target, o_setting);
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
        return attr::set_pmic0_mfg_id(i_target, i_setting);
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
        return i_spd_data.mfg_id_pmic0(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWA_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWA_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWA_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWA_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWA_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swa_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic0_swa_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swa_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWA_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWA_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWA_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWA_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWA_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swa_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic0_swa_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swa_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWA_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWA_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWA_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWA_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWA_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swa_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic0_swa_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swa_pmic0(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swa_pmic0(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWA_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWA_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWA_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWA_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWA_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swa_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic0_swa_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swa_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWA_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWA_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWA_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWA_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWA_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swa_sequence_order(i_target, o_setting);
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
        return attr::set_pmic0_swa_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swa_pmic0(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWB_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWB_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWB_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWB_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWB_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swb_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic0_swb_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swb_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWB_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWB_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWB_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWB_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWB_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swb_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic0_swb_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swb_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWB_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWB_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWB_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWB_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWB_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swb_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic0_swb_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swb_pmic0(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swb_pmic0(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWB_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWB_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWB_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWB_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWB_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swb_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic0_swb_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swb_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWB_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWB_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWB_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWB_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWB_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swb_sequence_order(i_target, o_setting);
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
        return attr::set_pmic0_swb_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swb_pmic0(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWC_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWC_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWC_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWC_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWC_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swc_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic0_swc_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swc_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWC_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWC_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWC_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWC_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWC_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swc_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic0_swc_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swc_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWC_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWC_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWC_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWC_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWC_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swc_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic0_swc_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swc_pmic0(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swc_pmic0(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWC_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWC_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWC_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWC_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWC_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swc_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic0_swc_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swc_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWC_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWC_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWC_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWC_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWC_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swc_sequence_order(i_target, o_setting);
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
        return attr::set_pmic0_swc_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swc_pmic0(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWD_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWD_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWD_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWD_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWD_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swd_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic0_swd_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swd_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWD_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWD_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWD_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWD_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWD_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swd_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic0_swd_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swd_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWD_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWD_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWD_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWD_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWD_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swd_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic0_swd_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swd_pmic0(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swd_pmic0(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWD_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWD_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWD_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWD_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWD_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swd_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic0_swd_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swd_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SWD_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SWD_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SWD_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SWD_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SWD_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_swd_sequence_order(i_target, o_setting);
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
        return attr::set_pmic0_swd_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swd_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_PHASE_COMB partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_PHASE_COMB>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_PHASE_COMB_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_PHASE_COMB_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_PHASE_COMB;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_phase_comb(i_target, o_setting);
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
        return attr::set_pmic0_phase_comb(i_target, i_setting);
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
        return i_spd_data.phase_combination_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_REDUNDANCY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_REDUNDANCY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_REDUNDANCY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_REDUNDANCY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_REDUNDANCY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_redundancy(i_target, o_setting);
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
        return attr::set_pmic0_redundancy(i_target, i_setting);
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
        return i_spd_data.pmic0_redundancy(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_REVISION partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_REVISION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_REVISION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_REVISION_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_REVISION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_revision(i_target, o_setting);
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
        return attr::set_pmic0_revision(i_target, i_setting);
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
        return i_spd_data.revision_pmic0(o_setting);
    }
};

//----------------------------------------
// PMIC 1
//----------------------------------------

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_MFG_ID partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_MFG_ID>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_MFG_ID_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_MFG_ID_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_MFG_ID;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_mfg_id(i_target, o_setting);
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
        return attr::set_pmic1_mfg_id(i_target, i_setting);
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
        return i_spd_data.mfg_id_pmic1(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWA_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWA_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWA_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWA_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWA_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swa_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic1_swa_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swa_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWA_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWA_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWA_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWA_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWA_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swa_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic1_swa_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swa_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWA_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWA_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWA_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWA_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWA_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swa_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic1_swa_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swa_pmic1(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swa_pmic1(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWA_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWA_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWA_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWA_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWA_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swa_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic1_swa_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swa_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWA_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWA_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWA_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWA_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWA_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swa_sequence_order(i_target, o_setting);
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
        return attr::set_pmic1_swa_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swa_pmic1(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWB_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWB_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWB_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWB_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWB_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swb_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic1_swb_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swb_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWB_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWB_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWB_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWB_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWB_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swb_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic1_swb_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swb_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWB_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWB_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWB_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWB_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWB_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swb_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic1_swb_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swb_pmic1(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swb_pmic1(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWB_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWB_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWB_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWB_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWB_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swb_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic1_swb_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swb_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWB_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWB_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWB_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWB_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWB_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swb_sequence_order(i_target, o_setting);
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
        return attr::set_pmic1_swb_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swb_pmic1(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWC_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWC_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWC_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWC_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWC_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swc_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic1_swc_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swc_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWC_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWC_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWC_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWC_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWC_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swc_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic1_swc_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swc_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWC_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWC_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWC_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWC_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWC_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swc_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic1_swc_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swc_pmic1(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swc_pmic1(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWC_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWC_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWC_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWC_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWC_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swc_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic1_swc_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swc_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWC_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWC_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWC_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWC_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWC_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swc_sequence_order(i_target, o_setting);
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
        return attr::set_pmic1_swc_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swc_pmic1(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWD_VOLTAGE_SETTING partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWD_VOLTAGE_SETTING>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWD_VOLTAGE_SETTING_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWD_VOLTAGE_SETTING_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWD_VOLTAGE_SETTING;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swd_voltage_setting(i_target, o_setting);
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
        return attr::set_pmic1_swd_voltage_setting(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_swd_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWD_VOLTAGE_RANGE_SELECT partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWD_VOLTAGE_RANGE_SELECT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWD_VOLTAGE_RANGE_SELECT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWD_VOLTAGE_RANGE_SELECT_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWD_VOLTAGE_RANGE_SELECT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swd_voltage_range_select(i_target, o_setting);
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
        return attr::set_pmic1_swd_voltage_range_select(i_target, i_setting);
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
        return i_spd_data.volt_setpoint_range_swd_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWD_VOLTAGE_OFFSET partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWD_VOLTAGE_OFFSET>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWD_VOLTAGE_OFFSET_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWD_VOLTAGE_OFFSET_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWD_VOLTAGE_OFFSET;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swd_voltage_offset(i_target, o_setting);
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
        return attr::set_pmic1_swd_voltage_offset(i_target, i_setting);
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
        uint8_t l_offset = 0;
        uint8_t l_direction = 0;
        FAPI_TRY(i_spd_data.volt_offset_swd_pmic1(l_offset));
        FAPI_TRY(i_spd_data.volt_offset_direction_swd_pmic1(l_direction));

        o_setting = mss::pmic::convert_to_signed_offset(l_offset, l_direction);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWD_SEQUENCE_DELAY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWD_SEQUENCE_DELAY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWD_SEQUENCE_DELAY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWD_SEQUENCE_DELAY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWD_SEQUENCE_DELAY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swd_sequence_delay(i_target, o_setting);
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
        return attr::set_pmic1_swd_sequence_delay(i_target, i_setting);
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
        return i_spd_data.volt_delay_swd_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SWD_SEQUENCE_ORDER partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SWD_SEQUENCE_ORDER>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SWD_SEQUENCE_ORDER_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SWD_SEQUENCE_ORDER_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SWD_SEQUENCE_ORDER;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_swd_sequence_order(i_target, o_setting);
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
        return attr::set_pmic1_swd_sequence_order(i_target, i_setting);
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
        return i_spd_data.volt_order_swd_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_PHASE_COMB partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_PHASE_COMB>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_PHASE_COMB_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_PHASE_COMB_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_PHASE_COMB;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_phase_comb(i_target, o_setting);
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
        return attr::set_pmic1_phase_comb(i_target, i_setting);
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
        return i_spd_data.phase_combination_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_REDUNDANCY partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_REDUNDANCY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_REDUNDANCY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_REDUNDANCY_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_REDUNDANCY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_redundancy(i_target, o_setting);
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
        return attr::set_pmic1_redundancy(i_target, i_setting);
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
        return i_spd_data.pmic1_redundancy(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC0_SEQUENCE partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC0_SEQUENCE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC0_SEQUENCE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC0_SEQUENCE_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC0_SEQUENCE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic0_sequence(i_target, o_setting);
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
        return attr::set_pmic0_sequence(i_target, i_setting);
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
        return i_spd_data.sequence_pmic0(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_SEQUENCE partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_SEQUENCE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_SEQUENCE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_SEQUENCE_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_SEQUENCE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_sequence(i_target, o_setting);
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
        return attr::set_pmic1_sequence(i_target, i_setting);
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
        return i_spd_data.sequence_pmic1(o_setting);
    }
};

//
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @tparam P processor type
/// @note P, pmic::attr_eff_engine_fields, PMIC1_REVISION partial specialization
///
template< proc_type P>
struct attrEngineTraits<P, pmic::attr_eff_engine_fields, pmic::attr_eff_engine_fields::PMIC1_REVISION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PMIC1_REVISION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PMIC1_REVISION_TargetType;
    static constexpr pmic::ffdc_codes FFDC_CODE = pmic::SET_PMIC1_REVISION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pmic1_revision(i_target, o_setting);
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
        return attr::set_pmic1_revision(i_target, i_setting);
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
        return i_spd_data.revision_pmic1(o_setting);
    }
};

} // namespace mss

#endif
