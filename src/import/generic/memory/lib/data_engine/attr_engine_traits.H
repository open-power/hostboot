/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/attr_engine_traits.H $ */
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
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/spd/ddimm/efd_decoder.H>
#include <generic/memory/lib/utils/dimm/mss_timing.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TCCD_L
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TCCD_L >
{
    static constexpr const char* TIMING_NAME = "TCCD_L";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_tccd_l;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_tccd_l;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TWTR_L
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TWTR_L >
{
    static constexpr const char* TIMING_NAME = "tWTR_L";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_twtr_l;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_twtr_l;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TWTR_S
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TWTR_S >
{
    static constexpr const char* TIMING_NAME = "tWTR_S";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_twtr_s;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_twtr_s;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TFAW
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TFAW >
{
    static constexpr const char* TIMING_NAME = "tFAW";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_tfaw;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_tfaw;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TRCD
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRCD >
{
    static constexpr const char* TIMING_NAME = "trcd";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_trcd;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_trcd;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TRP
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRP >
{
    static constexpr const char* TIMING_NAME = "tRP";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_trp;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_trp;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TRAS
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRAS >
{
    static constexpr const char* TIMING_NAME = "tRAS";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_tras;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_tras;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TWR
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TWR >
{
    static constexpr const char* TIMING_NAME = "tWR";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_twr;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_twr;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TRRD_S
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRRD_S >
{
    static constexpr const char* TIMING_NAME = "tRRD_S";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_trrd_s;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_trrd_s;
};

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, DRAM_TRRD_L
///
template< >
struct setTimingTraits< attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRRD_L >
{
    static constexpr const char* TIMING_NAME = "tRRD_L";

    static constexpr spd_facade_fptr<int64_t> get_timing_in_mtb = &spd::facade::min_trrd_l;
    static constexpr spd_facade_fptr<int64_t> get_timing_in_ftb = &spd::facade::fine_offset_min_trrd_l;
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_eff_engine_fields, PRIM_STACK_TYPE specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::PRIM_STACK_TYPE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PRIM_STACK_TYPE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_eff_engine_fields, PRIM_DIE_COUNT specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::PRIMARY_DIE_COUNT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PRIM_DIE_COUNT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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

        const auto l_dimm = i_spd_data.get_target();

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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_eff_engine_fields, DRAM_DENSITY specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_DENSITY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_DENSITY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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

        const auto l_dimm = i_spd_data.get_target();

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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_engine_derived_fields, BUS_WIDTH specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::PRIM_BUS_WIDTH>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PRIM_BUS_WIDTH_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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

        const auto l_dimm = i_spd_data.get_target();

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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_eff_engine_fields, DRAM_WIDTH specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_WIDTH>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_WIDTH_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_value = 0;
        FAPI_TRY( i_spd_data.device_width(l_value) );

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_dimm, DRAM_WIDTH_MAP, SET_DRAM_WIDTH, l_value, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, COLUMN_ADDR_BITS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::COLUMN_ADDR_BITS>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_COLUMN_BITS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_COLUMN_BITS_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_COL_ADDR_BITS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_dram_column_bits(i_target, o_setting);
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
        return mss::attr::set_dram_column_bits(i_target, i_setting);
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
        static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_ADDR_COL_MAP =
        {
            {0b001, fapi2::ENUM_ATTR_MEM_EFF_DRAM_COLUMN_BITS_NUM10},
        };

        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_value = 0;
        FAPI_TRY(i_spd_data.column_address_bits(l_value))

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_dimm, DRAM_ADDR_COL_MAP, SET_COL_ADDR_BITS, l_value, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, ROW_ADDR_BITS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::ROW_ADDR_BITS>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_ROW_BITS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_ROW_BITS_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_ROW_ADDR_BITS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_dram_row_bits(i_target, o_setting);
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
        return mss::attr::set_dram_row_bits(i_target, i_setting);
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
        static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_ADDR_ROW_MAP =
        {
            {0b010, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM14},
            {0b011, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM15},
            {0b100, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM16},
            {0b101, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM17},
            {0b110, fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM18},
        };

        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_value = 0;
        FAPI_TRY(i_spd_data.row_address_bits(l_value))

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_dimm, DRAM_ADDR_ROW_MAP, SET_ROW_ADDR_BITS, l_value, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

//
// SI parameters
//

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, ATTR_SI_BASE_CASE specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::ATTR_SI_BASE_CASE> {};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_RCV_IMP_DQ_DQS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_RCV_IMP_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_RCV_IMP_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_odt_impedance = 0;
        uint8_t l_spd_rev = 0;

        const auto l_ocmb = i_efd_data->get_target();
        const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(l_ocmb);

        FAPI_TRY(mss::attr::get_spd_revision(l_ports[0], l_spd_rev));
        FAPI_TRY(i_efd_data->phy_odt_impedance(l_odt_impedance));

        // Call helper function
        FAPI_TRY(mss::gen::decode_rcv_imp_dq_dqs(l_ocmb, l_odt_impedance, l_spd_rev, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_DQ_DQS_PULL_UP specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_IMP_DQ_DQS_PULL_UP>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_phy_drv_imp_pu;

        static const std::vector< std::pair<uint16_t, uint16_t> > PHY_DRV_IMP_PU_MAP =
        {
            // {key byte, DRV IMP PU (ohms)}
            {0b000000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_DISABLE},
            {0b000001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_28},
            {0b000010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_30},
            {0b000011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_32},
            {0b000100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_34},
            {0b000101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_36},
            {0b000110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_40},
            {0b000111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_43},
            {0b001000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_48},
            {0b001001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_53},
            {0b001010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_60},
            {0b001011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_68},
            {0b001100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_80},
            {0b001101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_96},
            {0b001110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_120},
            {0b001111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_160},
            {0b010000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_240},
            {0b010001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_UP_OHM_480},

            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        FAPI_TRY(i_efd_data->phy_drive_impedance_pull_up(l_phy_drv_imp_pu));
        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, PHY_DRV_IMP_PU_MAP, mss::SET_SI_MC_DRV_IMP_DQ_DQS_PULL_UP,
                                    static_cast<uint16_t>(l_phy_drv_imp_pu), o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_phy_drv_imp_pd = 0;

        static const std::vector< std::pair<uint16_t, uint16_t> > PHY_DRV_IMP_PD_MAP =
        {
            // {key byte, DRV IMP PD (ohms)}
            {0b000000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_DISABLE},
            {0b000001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_28},
            {0b000010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_30},
            {0b000011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_32},
            {0b000100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_34},
            {0b000101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_36},
            {0b000110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_40},
            {0b000111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_43},
            {0b001000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_48},
            {0b001001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_53},
            {0b001010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_60},
            {0b001011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_68},
            {0b001100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_80},
            {0b001101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_96},
            {0b001110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_120},
            {0b001111, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_160},
            {0b010000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_240},
            {0b010001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN_OHM_480},

            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        FAPI_TRY(i_efd_data->phy_drive_impedance_pull_down(l_phy_drv_imp_pd));
        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, PHY_DRV_IMP_PD_MAP, mss::SET_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN,
                                    static_cast<uint16_t>(l_phy_drv_imp_pd), o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};


///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_DQ_DQS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_SLEW_RATE_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_CMD_ADDR specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_IMP_CMD_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_atx_impedance = 0;

        static const std::vector< std::pair<uint8_t, uint8_t> > ATX_IMP_MAP =
        {
            // {key byte, ATX IMP (ohm)}
            {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_DISABLE},
            {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_20},
            {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_24},
            {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_30},
            {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_40},
            {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_60},
            {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CMD_ADDR_OHM_120},

            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        FAPI_TRY(i_efd_data->atx_impedance(l_atx_impedance));
        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, ATX_IMP_MAP, mss::SET_SI_MC_DRV_IMP_CMD_ADDR, l_atx_impedance, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_CMD_ADDR specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_SLEW_RATE_CMD_ADDR>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_CMD_ADDR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_IMP_CLK specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_IMP_CLK>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_IMP_CLK_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_ck_impedance = 0;

        static const std::vector< std::pair<uint8_t, uint8_t> > CK_IMP_MAP =
        {
            // {key byte, CK IMP (ohm)}
            {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_DISABLE},
            {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_20},
            {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_24},
            {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_30},
            {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_40},
            {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_60},
            {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_DRV_IMP_CLK_OHM_120},

            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        FAPI_TRY(i_efd_data->ck_impedance(l_ck_impedance));
        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, CK_IMP_MAP, mss::SET_SI_MC_DRV_IMP_CLK, l_ck_impedance, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_SLEW_RATE_CLK specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_SLEW_RATE_CLK>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_SLEW_RATE_CLK_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_RCV_IMP_ALERT_N specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_RCV_IMP_ALERT_N>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_alert_odt_imp = 0;

        static const std::vector< std::pair<uint8_t, uint8_t> > ALERT_ODT_IMP_MAP =
        {
            // {key byte, ALERT ODT IMP (ohms)}
            {0b0000, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_DISABLE},
            {0b0001, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_40},
            {0b0010, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_48},
            {0b0011, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_60},
            {0b0100, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_80},
            {0b0101, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_120},
            {0b0110, fapi2::ENUM_ATTR_MEM_SI_MC_RCV_IMP_ALERT_N_OHM_240},

            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        FAPI_TRY(i_efd_data->alert_odt_impedance(l_alert_odt_imp));
        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, ALERT_ODT_IMP_MAP, mss::SET_SI_MC_RCV_IMP_ALERT_N, l_alert_odt_imp, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_DRAM_RTT_NOM specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_DRAM_RTT_NOM>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_RTT_NOM_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_rtt_nom = 0;

        static const std::vector< std::pair<uint8_t, uint8_t> > RTT_NOM_MAP =
        {
            {0b0000, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_DISABLE},
            {0b0001, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM34},
            {0b0010, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM40},
            {0b0011, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM60},
            {0b0100, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM80},
            {0b0101, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM120},
            {0b0110, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_NOM_OHM240},
            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        switch(i_efd_data->get_rank())
        {
            case 0:
                FAPI_TRY( i_efd_data->dram_rtt_nom_rank0(l_rtt_nom) );
                break;

            case 1:
                FAPI_TRY( i_efd_data->dram_rtt_nom_rank1(l_rtt_nom) );
                break;

            case 2:
                FAPI_TRY( i_efd_data->dram_rtt_nom_rank2(l_rtt_nom) );
                break;

            case 3:
                FAPI_TRY( i_efd_data->dram_rtt_nom_rank3(l_rtt_nom) );
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_RANK().
                            set_FUNCTION(SET_SI_DRAM_RTT_NOM).
                            set_RANK( i_efd_data->get_rank() ).
                            set_TARGET(l_ocmb),
                            "%s SPD decoder returned invalid rank: %d",
                            spd::c_str(l_ocmb),
                            i_efd_data->get_rank());
                break;
        };

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, RTT_NOM_MAP, mss::SET_SI_DRAM_RTT_NOM, l_rtt_nom, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_DRAM_RTT_WR specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_DRAM_RTT_WR>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_RTT_WR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_rtt_wr = 0;

        static const std::vector< std::pair<uint8_t, uint8_t> > RTT_WR_MAP =
        {
            {0b0000, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_DISABLE},
            {0b0001, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_OHM80},
            {0b0010, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_OHM120},
            {0b0011, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_WR_OHM240},
            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        switch(i_efd_data->get_rank())
        {
            case 0:
                FAPI_TRY( i_efd_data->dram_rtt_wr_rank0(l_rtt_wr) );
                break;

            case 1:
                FAPI_TRY( i_efd_data->dram_rtt_wr_rank1(l_rtt_wr) );
                break;

            case 2:
                FAPI_TRY( i_efd_data->dram_rtt_wr_rank2(l_rtt_wr) );
                break;

            case 3:
                FAPI_TRY( i_efd_data->dram_rtt_wr_rank3(l_rtt_wr) );
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_RANK().
                            set_FUNCTION(SET_SI_DRAM_RTT_WR).
                            set_RANK( i_efd_data->get_rank() ).
                            set_TARGET(l_ocmb),
                            "%s SPD decoder returned invalid rank: %d",
                            spd::c_str(l_ocmb),
                            i_efd_data->get_rank());
                break;
        };

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, RTT_WR_MAP, mss::SET_SI_DRAM_RTT_WR, l_rtt_wr, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_DRAM_RTT_PARK specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_DRAM_RTT_PARK>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_RTT_PARK_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_rtt_park = 0;

        static const std::vector< std::pair<uint8_t, uint8_t> > RTT_PARK_MAP =
        {
            // {key byte, RTT PARK (ohms)}
            {0b0000, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_DISABLE},
            {0b0001, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM34},
            {0b0010, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM40},
            {0b0011, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM48},
            {0b0100, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM60},
            {0b0101, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM80},
            {0b0110, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM120},
            {0b0111, fapi2::ENUM_ATTR_MEM_SI_DRAM_RTT_PARK_OHM240},
            // All others reserved
        };
        const auto l_ocmb = i_efd_data->get_target();

        switch(i_efd_data->get_rank())
        {
            case 0:
                FAPI_TRY( i_efd_data->dram_rtt_park_rank0(l_rtt_park) );
                break;

            case 1:
                FAPI_TRY( i_efd_data->dram_rtt_park_rank1(l_rtt_park) );
                break;

            case 2:
                FAPI_TRY( i_efd_data->dram_rtt_park_rank2(l_rtt_park) );
                break;

            case 3:
                FAPI_TRY( i_efd_data->dram_rtt_park_rank3(l_rtt_park) );
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_RANK().
                            set_FUNCTION(SET_SI_DRAM_RTT_PARK).
                            set_RANK( i_efd_data->get_rank() ).
                            set_TARGET(l_ocmb),
                            "%s SPD decoder returned invalid rank: %d",
                            spd::c_str(l_ocmb),
                            i_efd_data->get_rank());
                break;
        };

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, RTT_PARK_MAP, mss::SET_SI_DRAM_RTT_PARK, l_rtt_park, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_DRAM_PREAMBLE specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_DRAM_PREAMBLE>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_PREAMBLE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_read_preamble = 0;
        uint8_t l_write_preamble = 0;

        FAPI_TRY(i_efd_data->read_preamble(l_read_preamble));
        FAPI_TRY(i_efd_data->write_preamble(l_write_preamble));

        o_setting = static_cast<attr_integral_type>(
                        mss::gen::align_preamble_to_attr(l_read_preamble, l_write_preamble));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_MC_DRV_EQ_DQ_DQS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_MC_DRV_EQ_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_MC_DRV_EQ_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_DRAM_DRV_IMP_DQ_DQS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_DRAM_DRV_IMP_DQ_DQS>
{
    using attr_type = fapi2::ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_DIC_MAP =
        {
            // {key byte, DRAM DIC (ohms)}
            {0, fapi2::ENUM_ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_DISABLE},
            {1, fapi2::ENUM_ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_OHM34},
            {2, fapi2::ENUM_ATTR_MEM_SI_DRAM_DRV_IMP_DQ_DQS_OHM48},
        };

        const auto l_ocmb = i_efd_data->get_target();

        attr_integral_type l_dram_dic = 0;
        FAPI_TRY(i_efd_data->dram_dic(l_dram_dic))

        // Map SPD value to desired setting
        FAPI_TRY(lookup_table_check(l_ocmb, DRAM_DIC_MAP, SET_SI_DRAM_DRV_IMP_DQ_DQS, l_dram_dic, o_setting));

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_ODT_WR specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_ODT_WR>
{
    using attr_type = fapi2::ATTR_MEM_SI_ODT_WR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
        uint8_t l_value = 0;

        const auto l_ocmb = i_efd_data->get_target();

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
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_RANK().
                            set_FUNCTION(SET_SI_ODT_WR).
                            set_RANK( i_efd_data->get_rank() ).
                            set_TARGET(l_ocmb),
                            "%s SPD decoder returned invalid rank: %d",
                            spd::c_str(l_ocmb),
                            i_efd_data->get_rank());
                break;
        };

        // Map to attribute bitmap
        l_value = mss::gen::align_odt_field_to_attr(l_value);

        o_setting = l_value;

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_ODT_RD specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_ODT_RD>
{
    using attr_type = fapi2::ATTR_MEM_SI_ODT_RD_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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

        const auto l_ocmb = i_efd_data->get_target();

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
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_SPD_RANK().
                            set_FUNCTION(SET_SI_ODT_RD).
                            set_RANK( i_efd_data->get_rank() ).
                            set_TARGET(l_ocmb),
                            "%s SPD decoder returned invalid rank: %d",
                            spd::c_str(l_ocmb),
                            i_efd_data->get_rank());
                break;
        };

        // Map to attribute bitmap
        l_value = mss::gen::align_odt_field_to_attr(l_value);

        o_setting = l_value;

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_si_engine_fields, SI_GEARDOWN_MODE specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_si_engine_fields, attr_si_engine_fields::SI_GEARDOWN_MODE>
{
    using attr_type = fapi2::ATTR_MEM_SI_GEARDOWN_MODE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, MRANKS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_engine_derived_fields, attr_engine_derived_fields::LOGICAL_RANKS>
{
    using attr_type = fapi2::ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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
            FAPI_DBG("%s Num Logical Ranks %d", spd::c_str(i_target), o_setting);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_engine_derived_fields, MEM_DIMM_SIZE specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_engine_derived_fields, attr_engine_derived_fields::MEM_DIMM_SIZE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DIMM_SIZE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
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

        FAPI_DBG("%s DIMM size = %d => (%d * %d * %d) / (8 * %d)",
                 spd::c_str(i_target), o_setting, l_dram_density, l_bus_width, l_logical_rank_per_dimm, l_dram_width);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attr_engine_derived_fields, HEIGHT_3DS specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_engine_derived_fields, attr_engine_derived_fields::HEIGHT_3DS>
{
    using attr_type = fapi2::ATTR_MEM_3DS_HEIGHT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_3DS_HEIGHT_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_3DS_HEIGHT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_3ds_height(i_target, o_setting);
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
        return mss::attr::set_3ds_height(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        uint8_t l_master_ranks_per_dimm = 0;
        uint8_t l_logical_ranks_per_dimm = 0;

        FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_master_ranks_per_dimm));
        FAPI_TRY(mss::attr::get_logical_ranks_per_dimm(i_target, l_logical_ranks_per_dimm));
        {
            const uint16_t l_result = l_logical_ranks_per_dimm / l_master_ranks_per_dimm;

            static const std::vector< std::pair<uint16_t, uint16_t> > HEIGHT_3DS_MAP =
            {
                // {key byte, 3DS HEIGHT}
                {1, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_PLANAR},
                {2, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H2},
                {4, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H4},
                {8, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H8},
                // All others reserved
            };

            // Map SPD value to desired setting
            FAPI_TRY(lookup_table_check(i_target, HEIGHT_3DS_MAP, mss::SET_3DS_HEIGHT, l_result, o_setting));
        }
    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_CWL specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_CWL>
{
    using attr_type = fapi2::ATTR_MEM_DRAM_CWL_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_DRAM_CWL_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_CWL;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_cwl(i_target, o_setting);
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
        return mss::attr::set_dram_cwl(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        // Taken from DDR4 JEDEC spec 1716.78C
        // Proposed DDR4 Full spec update(79-4A)
        // Page 26, Table 7
        static const std::vector<std::pair<uint64_t, uint8_t> > CWL_TABLE_1 =
        {
            {1866, 10},
            {2133, 11},
            {2400, 12},
            {2666, 14},
            {2933, 16},
            {3200, 16},
        };

        static const std::vector<std::pair<uint64_t, uint8_t> > CWL_TABLE_2 =
        {
            // Note that 2tCK write preamble is not valid for 1866 or 2133 speed grades
            {2400, 14},
            {2666, 16},
            {2933, 18},
            {3200, 18},
        };

        const auto& l_dimm = i_spd_data.get_target();
        // TK This could change but not sure where to get this from
        constexpr size_t MAX_RANKS_PER_DIMM = 4;
        uint64_t l_freq = 0;
        uint8_t l_preambles[MAX_RANKS_PER_DIMM] = {0};
        fapi2::buffer<uint8_t> l_preamble;

        FAPI_TRY( mss::attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
        FAPI_TRY( mss::attr::get_si_dram_preamble(l_dimm, l_preambles) );

        // TK Using the preamble for rank0 for now
        l_preamble = l_preambles[0];

        if (!l_preamble.getBit<fapi2::ENUM_ATTR_MEM_SI_DRAM_PREAMBLE_WRITE_PREAMBLE_BIT>())
        {
            FAPI_TRY(lookup_table_check(l_dimm, CWL_TABLE_1, FFDC_CODE, l_freq, o_setting));
        }
        else
        {
            FAPI_TRY(lookup_table_check(l_dimm, CWL_TABLE_2, FFDC_CODE, l_freq, o_setting));
        }

        FAPI_DBG("%s DRAM CWL %d", spd::c_str(l_dimm), o_setting);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_engine_derived_fields, MODULE_MFG_ID specialization
///
template < proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::MODULE_MFG_ID>
{
    using attr_type = fapi2::ATTR_MEM_EFF_MODULE_MFG_ID_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_MODULE_MFG_ID_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_MODULE_MFG_ID;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_module_mfg_id(i_target, o_setting);
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
        return mss::attr::set_module_mfg_id(i_target, i_setting);
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
        fapi2::buffer<attr_integral_type> l_temp;
        FAPI_TRY(i_spd_data.module_manufacturer_id_code(l_temp));
        fapi2::endian_swap(l_temp);
        o_setting = l_temp;

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_engine_derived_fields, DRAM_MFG_ID specialization
///
template < proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_MFG_ID>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_MFG_ID_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_MFG_ID_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_MFG_ID;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_mfg_id(i_target, o_setting);
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
        return mss::attr::set_dram_mfg_id(i_target, i_setting);
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
        fapi2::buffer<attr_integral_type> l_temp;
        FAPI_TRY(i_spd_data.dram_manufacturer_id_code(l_temp));
        fapi2::endian_swap(l_temp);
        o_setting = l_temp;

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TREFI specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TREFI>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TREFI_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TREFI_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TREFI;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trefi(i_target, o_setting);
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
        return mss::attr::set_dram_trefi(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        const auto& l_dimm = i_spd_data.get_target();
        uint8_t l_refresh_mode = 0;
        uint8_t l_refresh_rate = 0;
        uint64_t l_trefi_in_ps = 0;
        int64_t l_tck_in_ps = 0;
        uint64_t l_freq = 0;

        FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
        FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
                  "%s Failed to calculate clock period (tCK)", spd::c_str(l_dimm) );

        FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(l_refresh_mode) );
        FAPI_TRY( mss::attr::get_mrw_refresh_rate_request(l_refresh_rate) );

        switch(l_refresh_mode)
        {
            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:

                FAPI_TRY( calc_trefi( mss::refresh_rate::REF1X,
                                      l_refresh_rate,
                                      l_trefi_in_ps),
                          "%s Failed to calculate tREF1", spd::c_str(l_dimm) );
                break;

            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:

                FAPI_TRY( calc_trefi( mss::refresh_rate::REF2X,
                                      l_refresh_rate,
                                      l_trefi_in_ps),
                          "%s Failed to calculate tREF2", spd::c_str(l_dimm) );
                break;

            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:

                FAPI_TRY( calc_trefi( mss::refresh_rate::REF4X,
                                      l_refresh_rate,
                                      l_trefi_in_ps),
                          "%s Failed to calculate tREF4", spd::c_str(l_dimm) );
                break;

            default:
                // Fine Refresh Mode will be a platform attribute set by the MRW,
                // which they "shouldn't" mess up as long as use "attribute" enums.
                // if openpower messes this up we can at least catch it
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                            set_FINE_REF_MODE(l_refresh_mode),
                            "%s Incorrect Fine Refresh Mode received: %d ",
                            spd::c_str(l_dimm),
                            l_refresh_mode);
                break;
        };

        {
            // Calculate refresh cycle time in nCK & set attribute
            constexpr double PERCENT_ADJUST = 0.99;

            // Calculate nck
            uint64_t l_trefi_in_nck = 0;
            FAPI_TRY(  spd::calc_nck( l_trefi_in_ps,
                                      static_cast<uint64_t>(l_tck_in_ps),
                                      spd::INVERSE_DDR4_CORRECTION_FACTOR,
                                      l_trefi_in_nck),
                       "%s Error in calculating tREFI, with value of l_trefi_in_ps: %d", spd::c_str(l_dimm), l_trefi_in_ps);

            // Lab requested 99% of tREFI calculation to avoid any latency impact and violation of any
            // refresh specification (across all number of ranks and frequencies) observed
            // during lab power/thermal tests.

            FAPI_INF("%s adjusting tREFI calculation by 99%, calculated tREFI (nck): %lu, adjusted tREFI (nck): %lu,",
                     spd::c_str(l_dimm), l_trefi_in_nck, l_trefi_in_nck * PERCENT_ADJUST);

            // The compiler does this under the covers but just to be explicit on intent:
            // Floating point arithmetic and truncation of result saved to an unsigned integer
            l_trefi_in_nck = static_cast<double>(l_trefi_in_nck * PERCENT_ADJUST);

            FAPI_INF("%s tCK (ps): %d, tREFI (ps): %d, tREFI (nck): %d",
                     spd::c_str(l_dimm), l_tck_in_ps, l_trefi_in_ps, l_trefi_in_nck);

            o_setting = l_trefi_in_nck;
            FAPI_DBG("%s DRAM TREFI %d", spd::c_str(l_dimm), o_setting);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TCCD_L specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TCCD_L>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TCCD_L_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TCCD_L_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TCCD_L;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_tccd_l(i_target, o_setting);
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
        return mss::attr::set_dram_tccd_l(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TCCD_L>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TWTR_L specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TWTR_L>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TWTR_L_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TWTR_L_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TWTR_L;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_twtr_l(i_target, o_setting);
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
        return mss::attr::set_dram_twtr_l(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TWTR_L>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TWTR_S specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TWTR_S>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TWTR_S_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TWTR_S_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TWTR_S;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_twtr_s(i_target, o_setting);
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
        return mss::attr::set_dram_twtr_s(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TWTR_S>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TFAW specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TFAW>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TFAW_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TFAW_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TFAW;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_tfaw(i_target, o_setting);
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
        return mss::attr::set_dram_tfaw(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TFAW>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRCD specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRCD>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRCD_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRCD_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRCD;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trcd(i_target, o_setting);
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
        return mss::attr::set_dram_trcd(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TRCD>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRP specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRP>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRP_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRP_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRP;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trp(i_target, o_setting);
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
        return mss::attr::set_dram_trp(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TRP>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRAS specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRAS>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRAS_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRAS_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRAS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_tras(i_target, o_setting);
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
        return mss::attr::set_dram_tras(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TRAS>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TWR specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TWR>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TWR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TWR_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TWR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_twr(i_target, o_setting);
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
        return mss::attr::set_dram_twr(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_nck<attr_eff_engine_fields,
                attr_eff_engine_fields::DRAM_TWR>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRTP specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRTP>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRTP_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRTP_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRTP;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trtp(i_target, o_setting);
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
        return mss::attr::set_dram_trtp(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        const auto& l_dimm = i_spd_data.get_target();
        int64_t l_tck_in_ps = 0;
        uint64_t l_freq = 0;

        // Values from proposed DDR4 Full spec update(79-4A)
        // Item No. 1716.78C
        // Page 241 & 246
        constexpr int64_t l_max_trtp_in_ps = trtp();
        uint8_t l_calc_trtp_in_nck = 0;

        FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
        FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
                  "%s Failed to calculate clock period (tCK)", spd::c_str(l_dimm) );

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_max_trtp_in_ps, l_tck_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_calc_trtp_in_nck),
                  "%s Error in calculating trtp, with value of l_twtr_in_ps: %d",
                  spd::c_str(l_dimm), l_max_trtp_in_ps);

        FAPI_INF("%s tCK (ps): %d, tRTP (ps): %d, tRTP (nck): %d",
                 spd::c_str(l_dimm), l_tck_in_ps, l_max_trtp_in_ps, l_calc_trtp_in_nck);

        o_setting = l_calc_trtp_in_nck;
        FAPI_DBG("%s DRAM TRTP %d", spd::c_str(l_dimm), o_setting);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRRD_S specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRRD_S>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRRD_S_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRRD_S_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRRD_S;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trrd_s(i_target, o_setting);
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
        return mss::attr::set_dram_trrd_s(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        const auto& l_dimm = i_spd_data.get_target();

        // Taking the worst case required minimum JEDEC value
        // instead of calculating proposed value from SPD -- which selects optimistic values
        // leading to errors in expected timing values
        uint64_t l_trrd_s_in_nck = 0;
        uint64_t l_freq = 0;
        uint8_t l_dram_width = 0;
        FAPI_TRY( attr::get_dram_width(l_dimm, l_dram_width) );
        FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
        FAPI_TRY( trrd_s( l_dimm, l_dram_width, l_freq, l_trrd_s_in_nck) );

        FAPI_INF("%s SDRAM width: %d, tRRD_S (nck): %d",
                 spd::c_str(l_dimm), l_dram_width, l_trrd_s_in_nck);

        o_setting = l_trrd_s_in_nck;
        FAPI_DBG("%s DRAM TRRD_S %d", spd::c_str(l_dimm), o_setting);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRRD_L specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRRD_L>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRRD_L_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRRD_L_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRRD_L;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trrd_l(i_target, o_setting);
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
        return mss::attr::set_dram_trrd_l(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        const auto& l_dimm = i_spd_data.get_target();

        // Taking the worst case required minimum JEDEC value
        // instead of calculating proposed value from SPD -- which selects optimistic values
        // leading to errors in expected timing values
        uint8_t l_dram_width = 0;
        uint64_t l_trrd_l_in_nck = 0;
        uint64_t l_freq = 0;

        FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
        FAPI_TRY( attr::get_dram_width(l_dimm, l_dram_width) );
        FAPI_TRY( trrd_l( l_dimm, l_dram_width, l_freq, l_trrd_l_in_nck) );

        FAPI_INF("%s SDRAM width: %d, tRRD_L (nck): %d",
                 spd::c_str(l_dimm), l_dram_width, l_trrd_l_in_nck);

        o_setting = l_trrd_l_in_nck;
        FAPI_DBG("%s DRAM TRRD_L %d", spd::c_str(l_dimm), o_setting);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRFC specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRFC>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRFC_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRFC_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRFC;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trfc(i_target, o_setting);
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
        return mss::attr::set_dram_trfc(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        const auto& l_dimm = i_spd_data.get_target();
        int64_t l_tck_in_ps = 0;
        uint64_t l_freq = 0;
        uint8_t l_refresh_mode = 0;
        int64_t l_trfc_mtb = 0;
        int64_t l_trfc_in_ps = 0;

        FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
        FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
                  "%s Failed to calculate clock period (tCK)", spd::c_str(l_dimm) );

        FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(l_refresh_mode) );

        // Selects appropriate tRFC based on fine refresh mode
        switch(l_refresh_mode)
        {
            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_NORMAL:
                FAPI_TRY( i_spd_data.min_trfc1(l_trfc_mtb),
                          "%s Failed to decode SPD for tRFC1", spd::c_str(l_dimm) );
                break;

            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_2X:
            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_2X:
                FAPI_TRY( i_spd_data.min_trfc2(l_trfc_mtb),
                          "%s Failed to decode SPD for tRFC2", spd::c_str(l_dimm) );
                break;

            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FIXED_4X:
            case fapi2::ENUM_ATTR_MSS_MRW_FINE_REFRESH_MODE_FLY_4X:
                FAPI_TRY( i_spd_data.min_trfc4(l_trfc_mtb),
                          "%s Failed to decode SPD for tRFC4", spd::c_str(l_dimm) );
                break;

            default:
                // Fine Refresh Mode will be a platform attribute set by the MRW,
                // which they "shouldn't" mess up as long as use "attribute" enums.
                // if openpower messes this up we can at least catch it
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_FINE_REFRESH_MODE().
                            set_FINE_REF_MODE(l_refresh_mode),
                            "%s Incorrect Fine Refresh Mode received: %d ",
                            spd::c_str(l_dimm),
                            l_refresh_mode);
                break;
        }// switch

        // Calculate trfc (in ps)
        {
            int64_t l_trfc_ftb = 0;
            int64_t l_ftb = 0;
            int64_t l_mtb = 0;

            FAPI_TRY( spd::get_timebases(i_spd_data, l_mtb, l_ftb) );

            FAPI_INF( "%s medium timebase (ps): %ld, fine timebase (ps): %ld, tRFC (MTB): %ld, tRFC(FTB): %ld",
                      spd::c_str(l_dimm), l_mtb, l_ftb, l_trfc_mtb, l_trfc_ftb );

            l_trfc_in_ps = spd::calc_timing_from_timebase(l_trfc_mtb, l_mtb, l_trfc_ftb, l_ftb);
        }

        {
            // Calculate refresh cycle time in nCK & set attribute

            uint16_t l_trfc_in_nck = 0;

            // Calculate nck
            FAPI_TRY( spd::calc_nck(l_trfc_in_ps, l_tck_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, l_trfc_in_nck),
                      "%s Error in calculating l_tRFC, with value of l_trfc_in_ps: %d", spd::c_str(l_dimm), l_trfc_in_ps);

            FAPI_INF("%s tCK (ps): %d, tRFC (ps): %d, tRFC (nck): %d",
                     spd::c_str(l_dimm), l_tck_in_ps, l_trfc_in_ps, l_trfc_in_nck);

            o_setting = l_trfc_in_nck;
            FAPI_DBG("%s DRAM TRFC %d", spd::c_str(l_dimm), o_setting);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attrEngineTraits
/// @class attrEngineTraits - partial specialization
/// @tparam P processor type
/// @note attrEngineTraits, DRAM_TRFC_DLR specialization
///
template<proc_type P>
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_TRFC_DLR>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_TRFC_DLR_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_TRFC_DLR_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_TRFC_DLR;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_trfc_dlr(i_target, o_setting);
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
        return mss::attr::set_dram_trfc_dlr(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        const auto& l_dimm = i_spd_data.get_target();
        int64_t l_tck_in_ps = 0;
        uint64_t l_freq = 0;
        uint8_t l_refresh_mode = 0;
        uint8_t l_dram_density = 0;
        uint64_t l_trfc_dlr_in_ps = 0;
        attr_integral_type l_trfc_dlr_in_nck = 0;

        FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
        FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
                  "%s Failed to calculate clock period (tCK)", spd::c_str(l_dimm) );

        FAPI_TRY( mss::attr::get_mrw_fine_refresh_mode(l_refresh_mode) );
        FAPI_TRY( mss::attr::get_dram_density(l_dimm, l_dram_density) );

        // Calculate refresh cycle time in ps
        FAPI_TRY( calc_trfc_dlr(l_dimm, l_refresh_mode, l_dram_density, l_trfc_dlr_in_ps),
                  "%s Failed calc_trfc_dlr()", spd::c_str(l_dimm) );

        // Calculate refresh cycle time in nck
        FAPI_TRY( spd::calc_nck(l_trfc_dlr_in_ps, static_cast<uint64_t>(l_tck_in_ps), spd::INVERSE_DDR4_CORRECTION_FACTOR,
                                l_trfc_dlr_in_nck));

        FAPI_INF("%s tCK (ps): %d, tRFC_DLR (ps): %d, tRFC_DLR (nck): %d",
                 spd::c_str(l_dimm), l_tck_in_ps, l_trfc_dlr_in_ps, l_trfc_dlr_in_nck);

        o_setting = l_trfc_dlr_in_nck;
        FAPI_DBG("%s DRAM TRFC_DLR %d", spd::c_str(l_dimm), o_setting);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_engine_derived_fields, RCD_MFG_ID specialization
///
template < proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::RCD_MFG_ID>
{
    using attr_type = fapi2::ATTR_MEM_EFF_RCD_MFG_ID_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_RCD_MFG_ID_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_RCD_MFG_ID;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_rcd_mfg_id(i_target, o_setting);
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
        return mss::attr::set_rcd_mfg_id(i_target, i_setting);
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
        return i_spd_data.reg_manufacturer_id_code(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_engine_derived_fields, DRAM_MODULE_HEIGHT specialization
///
template < proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::DRAM_MODULE_HEIGHT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_MODULE_HEIGHT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_module_height(i_target, o_setting);
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
        return mss::attr::set_dram_module_height(i_target, i_setting);
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
        return i_spd_data.module_base_height(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_engine_derived_fields, SPD_CONTENT_REVISION specialization
///
template< proc_type P >
struct attrEngineTraits<P, attr_eff_engine_fields, attr_eff_engine_fields::SPD_CONTENT_REVISION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_SPD_CONTENT_REVISION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_SPD_CONTENT_REVISION_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SPD_CONTENT_REVISION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_spd_content_revision(i_target, o_setting);
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
        return mss::attr::set_spd_content_revision(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        // =========================================================
        // DDR4 SPD Document Release 4
        // Byte 221 (0x0DD): SPD Content Revision
        // =========================================================
        return i_spd_data.spd_content_revision(o_setting);
    }
};

}//mss

#endif
