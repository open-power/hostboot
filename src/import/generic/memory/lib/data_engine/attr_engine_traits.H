/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/attr_engine_traits.H $ */
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
/// @file attr_engine_traits.H
/// @brief Trait class definitions for generic attrs
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_ATTR_ENGINE_TRAITS_H_
#define _MSS_ATTR_ENGINE_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>
#include <generic/memory/lib/spd/ddimm/efd_decoder.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/utils/buffer_ops.H>

namespace mss
{

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, PRIM_STACK_TYPE specialization
///
template<>
struct attrEngineTraits<attr_eff_engine_fields, PRIM_STACK_TYPE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PRIM_STACK_TYPE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PRIM_STACK_TYPE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_PRIM_STACK_TYPE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_prim_stack_type(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_prim_stack_type(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.prim_sdram_signal_loading(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, PRIM_DIE_COUNT specialization
///
template<>
struct attrEngineTraits<attr_eff_engine_fields, PRIMARY_DIE_COUNT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PRIM_DIE_COUNT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PRIM_DIE_COUNT_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_PRIM_DIE_COUNT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_prim_die_count(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_prim_die_count(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        // =========================================================
        // Byte 6 maps
        // Item JC-45-2220.01x
        // Page 19
        // DDR4 SPD Document Release 3
        // Byte 6 (0x006): Primary SDRAM Package Type
        // =========================================================
        static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_DIE_COUNT_MAP =
        {
            // {key byte, number of die}
            {0, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D1},
            {1, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D2},
            {2, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D3},
            {3, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D4},
            {4, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D5},
            {5, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D6},
            {6, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D7},
            {7, fapi2::ENUM_ATTR_MEM_EFF_PRIM_DIE_COUNT_D8}
        };

        const auto l_dimm = i_spd_data.get_dimm_target();

        attr_integral_type l_decoder_val = 0;
        FAPI_TRY( i_spd_data.prim_sdram_die_count(l_decoder_val) );

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_dimm, PRIM_DIE_COUNT_MAP, FFDC_CODE, l_decoder_val, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, DRAM_DENSITY specialization
///
template<>
struct attrEngineTraits<attr_eff_engine_fields, DRAM_DENSITY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_DENSITY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_DENSITY_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_DENSITY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_density(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the attr target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_dram_density(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[in] i_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        // =========================================================
        // DDR4 SPD Document Release 4
        // Byte 2 (0x002): Key Byte / DRAM Device Type
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_DENSITY_MAP =
        {
            // {key byte, capacity in GBs}
            {4, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_4G},
            {5, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_8G},
            {6, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_16G},
        };

        const auto l_dimm = i_spd_data.get_dimm_target();

        attr_integral_type l_sdram_density = 0;
        FAPI_TRY( i_spd_data.sdram_density(l_sdram_density),
                  "%s failed to get device type from SPD", spd::c_str(l_dimm) );

        FAPI_TRY( lookup_table_check(l_dimm, DRAM_DENSITY_MAP, FFDC_CODE, l_sdram_density, o_setting),
                  "%s failed DRAM_DENSITY lookup check", spd::c_str(l_dimm) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_engine_derived_fields, BUS_WIDTH specialization
///
template<>
struct attrEngineTraits<attr_eff_engine_fields, PRIM_BUS_WIDTH>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PRIM_BUS_WIDTH_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PRIM_BUS_WIDTH_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_PRIM_BUS_WIDTH;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_prim_bus_width(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_prim_bus_width(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay

    static inline fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        // =========================================================
        // Byte 13 maps
        // Item JC-45-2220.01x
        // Page 27
        // DDR4 SPD Document Release 3
        // Byte 13 (0x00D): Module Memory Bus Width
        // =========================================================
        const std::vector<std::pair<uint8_t, uint8_t> > BUS_WIDTH_MAP =
        {
            // {key byte, bus width (in bits)
            {0, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_8_BITS},
            {1, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_16_BITS},
            {2, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_32_BITS},
            {3, fapi2::ENUM_ATTR_MEM_EFF_PRIM_BUS_WIDTH_64_BITS}
            // All others reserved
        };

        const auto l_dimm = i_spd_data.get_dimm_target();

        attr_integral_type l_spd_bus_width = 0;
        FAPI_TRY( i_spd_data.prim_bus_width(l_spd_bus_width) );

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_dimm, BUS_WIDTH_MAP, FFDC_CODE, l_spd_bus_width, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, DRAM_WIDTH specialization
///
template<>
struct attrEngineTraits<attr_eff_engine_fields, DRAM_WIDTH>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_WIDTH_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_WIDTH_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_WIDTH;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_dram_width(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_dram_width(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        // =========================================================
        // Byte 12 maps
        // Item JC-45-2220.01x
        // Page 23
        // DDR4 SPD Document Release 3
        // Byte 12 (0x00C): Module Organization
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_WIDTH_MAP =
        {
            // {key byte, device width (bits)}
            {0, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4},
            {1, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8},
            {2, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X16},
            {3, fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X32},
            // All others reserved
        };

        // Read SPD value
        const auto l_dimm = i_spd_data.get_dimm_target();

        attr_integral_type l_value = 0;
        FAPI_TRY( i_spd_data.device_width(l_value) );

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_dimm, DRAM_WIDTH_MAP, SET_DRAM_WIDTH, l_value, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
// SI parameters
//

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, ATTR_SI_BASE_CASE specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, ATTR_SI_BASE_CASE> {};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_RCV_IMP_DQ_DQS specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_RCV_IMP_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_RCV_IMP_DQ_DQS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_rcv_imp_dq_dqs(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_rcv_imp_dq_dqs(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->phy_odt_impedance(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_DQ_DQS_PULL_UP specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_IMP_DQ_DQS_PULL_UP>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_IMP_DQ_DQS_PULL_UP;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_imp_dq_dqs_pull_up(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_imp_dq_dqs_pull_up(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->phy_drive_impedance_pull_up(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_imp_dq_dqs_pull_down(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_imp_dq_dqs_pull_down(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->phy_drive_impedance_pull_down(o_setting);
    }
};


///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_DQ_DQS specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_DQ_DQS_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_SLEW_RATE_DQ_DQS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_slew_rate_dq_dqs(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_slew_rate_dq_dqs(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->phy_slew_rate_dq_dqs(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_CMD_ADDR specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_IMP_CMD_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_IMP_CMD_ADDR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_imp_cmd_addr(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_imp_cmd_addr(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->atx_impedance(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_CMD_ADDR specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_CMD_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_CMD_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_CMD_ADDR_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_SLEW_RATE_CMD_ADDR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_slew_rate_cmd_addr(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_slew_rate_cmd_addr(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->atx_slew_rate(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_CLK specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_IMP_CLK>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_CLK_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_IMP_CLK_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_IMP_CLK;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_imp_clk(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_imp_clk(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->ck_impedance(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_CLK specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_CLK>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_CLK_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_CLK_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_SLEW_RATE_CLK;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_slew_rate_clk(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_slew_rate_clk(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->ck_slew_rate(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_RCV_IMP_ALERT_N specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_RCV_IMP_ALERT_N>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_RCV_IMP_ALERT_N;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_rcv_imp_alert_n(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_rcv_imp_alert_n(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->alert_odt_impedance(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_DRAM_RTT_NOM specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_DRAM_RTT_NOM>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_RTT_NOM_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_DRAM_RTT_NOM_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_DRAM_RTT_NOM;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_dram_rtt_nom(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_dram_rtt_nom(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->dram_rtt_nom(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_DRAM_RTT_WR specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_DRAM_RTT_WR>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_RTT_WR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_DRAM_RTT_WR_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_DRAM_RTT_WR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_dram_rtt_wr(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_dram_rtt_wr(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->dram_rtt_wr(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_DRAM_RTT_PARK specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_DRAM_RTT_PARK>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_RTT_PARK_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_DRAM_RTT_PARK_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_DRAM_RTT_PARK;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_dram_rtt_park(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_dram_rtt_park(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->dram_rtt_park(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_DRAM_PREAMBLE specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_DRAM_PREAMBLE>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_PREAMBLE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_DRAM_PREAMBLE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_DRAM_PREAMBLE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_dram_preamble(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_dram_preamble(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        i_efd_data->write_preamble(o_setting);
        return i_efd_data->read_preamble(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_MC_DRV_EQ_DQ_DQS specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_MC_DRV_EQ_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_EQ_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_MC_DRV_EQ_DQ_DQS_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_MC_DRV_EQ_DQ_DQS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_mc_drv_eq_dq_dqs(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_mc_drv_eq_dq_dqs(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->phy_equalization(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_DRAM_DRV_IMP_DQ_DQS specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_DRAM_DRV_IMP_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_DRAM_DRV_IMP_DQ_DQS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_dram_drv_imp_dq_dqs(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_dram_drv_imp_dq_dqs(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->dram_dic(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_VREF_DQ_TRAIN_RANGE specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_VREF_DQ_TRAIN_RANGE>
{
    using attr_type = fapi2::ATTR_MEM_SI_VREF_DQ_TRAIN_RANGE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_VREF_DQ_TRAIN_RANGE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_VREF_DQ_TRAIN_RANGE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_vref_dq_train_range(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_vref_dq_train_range(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->wr_vref_dq_range(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_VREF_DQ_TRAIN_VALUE specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_VREF_DQ_TRAIN_VALUE>
{
    using attr_type = fapi2::ATTR_MEM_SI_VREF_DQ_TRAIN_VALUE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_VREF_DQ_TRAIN_VALUE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_VREF_DQ_TRAIN_VALUE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_vref_dq_train_value(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::set_si_vref_dq_train_value(i_target, o_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->wr_vref_dq_value(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_ODT_WR specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_ODT_WR>
{
    using attr_type = fapi2::ATTR_MEM_SI_ODT_WR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_ODT_WR_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_ODT_WR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_odt_wr(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_odt_wr(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        fapi2::buffer<uint8_t> l_buffer;
        uint8_t l_value = 0;

        switch(i_efd_data->get_rank())
        {
            case 0:
                FAPI_TRY( i_efd_data->odt_wr_map_rank0(l_value) );
                break;

            case 1:
                FAPI_TRY( i_efd_data->odt_wr_map_rank1(l_value) );
                break;

            case 2:
                FAPI_TRY( i_efd_data->odt_wr_map_rank2(l_value) );
                break;

            case 3:
                FAPI_TRY( i_efd_data->odt_wr_map_rank3(l_value) );
                break;

            default:
                // TODO Add FFDC
                fapi2::Assert(false);
                break;
        };

        // TK update to handle differentiating 2 DIMMs, defaulted to DIMM0 case for explorer
        {
            // Map to attribute bitmap
            reverse(l_value);
            o_setting = l_value;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_ODT_RD specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_ODT_RD>
{
    using attr_type = fapi2::ATTR_MEM_SI_ODT_RD_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_ODT_RD_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_ODT_RD;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_odt_rd(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_odt_rd(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        uint8_t l_value = 0;

        switch(i_efd_data->get_rank())
        {
            case 0:
                FAPI_TRY( i_efd_data->odt_rd_map_rank0(l_value) );
                break;

            case 1:
                FAPI_TRY( i_efd_data->odt_rd_map_rank1(l_value) );
                break;

            case 2:
                FAPI_TRY( i_efd_data->odt_rd_map_rank2(l_value) );
                break;

            case 3:
                FAPI_TRY( i_efd_data->odt_rd_map_rank3(l_value) );
                break;

            default:
                // TODO Add FFDC
                fapi2::Assert(false);
                break;
        };

        // TK update to handle differentiating 2 DIMMs, defaulted to DIMM0 case for explorer
        {
            // Map to attribute bitmap
            reverse(l_value);
            o_setting = l_value;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_si_engine_fields, SI_GEARDOWN_MODE specialization
///
template<>
struct attrEngineTraits<attr_si_engine_fields, SI_GEARDOWN_MODE>
{
    using attr_type = fapi2::ATTR_MEM_SI_GEARDOWN_MODE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_SI_GEARDOWN_MODE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SI_GEARDOWN_MODE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_si_geardown_mode(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_si_geardown_mode(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_value_to_set(const std::shared_ptr<efd::base_decoder>& i_efd_data,
            attr_integral_type& o_setting)
    {
        return i_efd_data->geardown_during_training(o_setting);
    }
};

//
// Derived attributes
//
///

/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits
/// @note attrEngineTraits, MRANKS specialization
///
template<>
struct attrEngineTraits<attr_engine_derived_fields, LOGICAL_RANKS>
{
    using attr_type = fapi2::ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_LOGICAL_RANKS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_logical_ranks_per_dimm(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the attr target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_logical_ranks_per_dimm(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        uint8_t l_prim_stack_type = 0;
        uint8_t l_master_ranks = 0;
        uint8_t l_die_count = 0;

        FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(i_target, l_master_ranks) );
        FAPI_TRY( mss::attr::get_prim_die_count(i_target, l_die_count) );
        FAPI_TRY( mss::attr::get_prim_stack_type(i_target, l_prim_stack_type) );

        {
            // For single-load-stack(3DS) the logical ranks per package ends up being the same as the die count.
            // For MONOLITHIC & MULTI_LOAD_STACK
            // The die count isn't guaranteed to be 1 (e.g. SDP - 1 die package, DDP - 2 die package).
            // Value of 1 has no meaning and is used for calculation purposes as defined by the SPD spec.
            const auto l_multiplier = (l_prim_stack_type == fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_3DS) ? l_die_count : 1;
            o_setting = (l_master_ranks * l_multiplier);
            FAPI_DBG("Num Logical Ranks %d", o_setting);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_engine_derived_fields, MEM_DIMM_SIZE specialization
///
template<>
struct attrEngineTraits<attr_engine_derived_fields, MEM_DIMM_SIZE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DIMM_SIZE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DIMM_SIZE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_SIZE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_dimm_size(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& i_setting)
    {
        return mss::attr::set_dimm_size(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_efd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay

    static inline fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        uint8_t l_dram_width = 0;
        uint8_t l_dram_density = 0;
        uint8_t l_logical_rank_per_dimm = 0;
        uint8_t l_bus_width = 0;

        FAPI_TRY( mss::attr::get_dram_width(i_target, l_dram_width) );
        FAPI_TRY( mss::attr::get_dram_density(i_target, l_dram_density) );
        FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(i_target, l_logical_rank_per_dimm) );
        FAPI_TRY( mss::attr::get_prim_bus_width(i_target, l_bus_width) );

        // Calculate dimm size
        // Formula from SPD Spec (seriously, they don't have parenthesis in the spec)
        // Total = SDRAM Capacity / 8 * Primary Bus Width / SDRAM Width * Logical Ranks per DIMM
        o_setting = (l_dram_density * l_bus_width * l_logical_rank_per_dimm) / (8 * l_dram_width);

        FAPI_DBG("DIMM size = %d => (%d * %d * %d) / (8 * %d)",
                 o_setting, l_dram_density, l_bus_width, l_logical_rank_per_dimm, l_dram_width);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

}//mss

#endif
