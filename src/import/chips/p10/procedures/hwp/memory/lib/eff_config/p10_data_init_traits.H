/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/eff_config/p10_data_init_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file p10_data_init_traits.H
/// @brief Trait class definitions for Axone pre_data_init
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_P10_PRE_DATA_INIT_TRAITS_H_
#define _MSS_P10_PRE_DATA_INIT_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>

namespace mss
{

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note pre_data_init_fields, DIMM_TYPE specialization
///
template<>
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::DIMM_TYPE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DIMM_TYPE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DIMM_TYPE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_TYPE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dimm_type(i_target, o_setting);
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
        return mss::attr::set_dimm_type(i_target, i_setting);
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
        // Byte 3 (0x003): Key Byte / Module Type
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > BASE_MODULE_TYPE_MAP =
        {
            //{key byte, dimm type}
            {1, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM},
            {2, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_UDIMM},
            {10, fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM},
            // All others reserved or not supported
        };

        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_base_module_type = 0;
        FAPI_TRY( i_spd_data.base_module(l_base_module_type),
                  "%s failed to get base module from SPD", spd::c_str(l_dimm) );

        FAPI_TRY( lookup_table_check(l_dimm, BASE_MODULE_TYPE_MAP, FFDC_CODE, l_base_module_type, o_setting),
                  "%s failed DIMM_TYPE lookup check", spd::c_str(l_dimm) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note pre_data_init_fields, DRAM_GEN specialization
///
template<>
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::DRAM_GEN>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DRAM_GEN_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DRAM_GEN_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_GEN;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_dram_gen(i_target, o_setting);
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
        return mss::attr::set_dram_gen(i_target, i_setting);
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
        // Byte 2 (0x002): Key Byte / DRAM Device Type
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > DRAM_GEN_MAP =
        {
            //{key value, dram gen}
            {0x0C, fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4}
            // Other key bytes reserved or not supported
        };

        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_device_type = 0;
        FAPI_TRY( i_spd_data.device_type(l_device_type),
                  "%s failed to get device type from SPD", spd::c_str(l_dimm) );

        FAPI_TRY( lookup_table_check(l_dimm, DRAM_GEN_MAP, FFDC_CODE, l_device_type, o_setting),
                  "%s failed DRAM_GEN lookup check", spd::c_str(l_dimm) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note pre_data_init_fields, HOST_TO_DDR_SPEED_RATIO specialization
///
template<>
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::HOST_TO_DDR_SPEED_RATIO>
{
    using attr_type = fapi2::ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_HOST_TO_DDR_SPEED_RATIO;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_host_to_ddr_speed_ratio(i_target, o_setting);
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
        return mss::attr::set_host_to_ddr_speed_ratio(i_target, i_setting);
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
        // Byte 220 (0x0DC): Host Interface Speed to DDR Interface Speed Ratio
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > HOST_TO_DDR_SPEED_RATIO_MAP =
        {
            // {key byte, speed ratio}
            {0, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_1_TO_1},
            {1, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_2_TO_1},
            {2, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_4_TO_1},
            {3, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_8_TO_1},
            {4, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_16_TO_1},
            {5, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_32_TO_1},
            {6, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_64_TO_1},
            {7, fapi2::ENUM_ATTR_MEM_EFF_HOST_TO_DDR_SPEED_RATIO_128_TO_1},
            // All others reserved or not supported
        };

        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_value = 0;
        FAPI_TRY( i_spd_data.host_to_ddr_speed_ratio(l_value),
                  "%s failed to get host to DDR speed ratio from SPD", spd::c_str(l_dimm) );

        FAPI_TRY( lookup_table_check(l_dimm, HOST_TO_DDR_SPEED_RATIO_MAP, FFDC_CODE, l_value, o_setting),
                  "%s failed HOST_TO_DDR_SPEED_RATIO lookup check", spd::c_str(l_dimm) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note pre_data_init_fields, HYBRID specialization
///
template<>
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::HYBRID>
{
    using attr_type = fapi2::ATTR_MEM_EFF_HYBRID_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_HYBRID_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_HYBRID;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_hybrid(i_target, o_setting);
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
        return mss::attr::set_hybrid(i_target, i_setting);
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
        // Byte 3 (0x003): Key Byte / Module Type - Hybrid
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > HYBRID_MAP =
        {
            //{key byte, dimm type}
            {0, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_NOT_HYBRID},
            {1, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_IS_HYBRID},
            // All others reserved or not supported
        };

        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_spd_hybrid_type = 0;
        FAPI_TRY(i_spd_data.hybrid(l_spd_hybrid_type),
                 "%s failed to get hybrid from SPD", spd::c_str(l_dimm) );

        FAPI_TRY(lookup_table_check(l_dimm, HYBRID_MAP, FFDC_CODE, l_spd_hybrid_type, o_setting),
                 "%s failed HYBRID lookup check", spd::c_str(l_dimm) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note pre_data_init_fields, HYBRID_MEDIA specialization
///
template<>
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::HYBRID_MEDIA>
{
    using attr_type = fapi2::ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_HYBRID_MEDIA;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attr target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_hybrid_memory_type(i_target, o_setting);
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
        return mss::attr::set_hybrid_memory_type(i_target, i_setting);
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
        // Byte 3 (0x003): Key Byte / Module Type - Hybrid
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > HYBRID_MEMORY_TYPE_MAP =
        {

            //{key byte, dimm type}
            {0, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NONE},
            {1, fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_NVDIMM},
            // All others reserved or not supported
        };
        const auto l_dimm = i_spd_data.get_target();
        attr_integral_type l_spd_hybrid_media = 0;

        FAPI_TRY( i_spd_data.hybrid_media(l_spd_hybrid_media),
                  "%s failed to get hybrid media from SPD", spd::c_str(l_dimm) );

        FAPI_TRY( lookup_table_check(l_dimm, HYBRID_MEMORY_TYPE_MAP, FFDC_CODE, l_spd_hybrid_media, o_setting),
                  "%s failed HYBRID_MEMORY_TYPE lookup check", spd::c_str(l_dimm) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note pre_data_init_fields, MRANKS specialization
///
template<>
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::MRANKS>
{
    using attr_type = fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_MRANKS;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the attribute associated target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_num_master_ranks_per_dimm(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the attribute associated target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return mss::attr::set_num_master_ranks_per_dimm(i_target, i_setting);
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
        // Byte 12 (0x00C): Module Organization
        // =========================================================
        static const std::vector< std::pair<uint8_t, uint8_t> > NUM_PACKAGE_RANKS_MAP =
        {
            // {key byte, num of package ranks per DIMM (package ranks)}
            {0, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_1R},
            {1, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_2R},
            {3, fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_4R},
        };

        const auto l_dimm = i_spd_data.get_target();

        attr_integral_type l_master_ranks_spd = 0;
        FAPI_TRY( i_spd_data.num_package_ranks_per_dimm(l_master_ranks_spd),
                  "%s failed to get number of package ranks from SPD", spd::c_str(l_dimm) );

        FAPI_TRY( lookup_table_check(l_dimm, NUM_PACKAGE_RANKS_MAP, FFDC_CODE, l_master_ranks_spd, o_setting),
                  "%s failed MASTER_RANKS lookup check", spd::c_str(l_dimm) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note DIMM_RANKS_CNFG specialization
///
template<>
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::DIMM_RANKS_CNFG>
{

    using attr_type = fapi2::ATTR_MEM_EFF_DIMM_RANKS_CONFIGED_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static const fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DIMM_RANKS_CONFIGED_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_RANKS_CNFG;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static inline fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
            attr_type& o_setting)
    {
        return mss::attr::get_dimm_ranks_configed(i_target, o_setting);
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
        return mss::attr::set_dimm_ranks_configed(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay

    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        // Set configed ranks. Set the bit representing the master rank configured (0 being left most.) So,
        // a 4R DIMM would be 0b11110000 (0xF0). This is used by PRD.
        fapi2::buffer<uint8_t> l_ranks_configed;

        // Make sure the number of master ranks is setup
        uint8_t l_master_ranks = 0;
        FAPI_TRY( (attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::MRANKS>::get_value_to_set(
                       i_spd_data,
                       l_master_ranks)) );

        FAPI_TRY( l_ranks_configed.setBit(0, l_master_ranks),
                  "%s. Failed to setBit", spd::c_str(i_spd_data.get_target()) );

        o_setting = l_ranks_configed;

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note pre_data_init_fields, SPD_REVISION specialization
///
template < >
struct attrEngineTraits<proc_type::PROC_P10, pre_data_init_fields, pre_data_init_fields::SPD_REVISION>
{
    using attr_type = fapi2::ATTR_MEM_EFF_SPD_REVISION_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    using attr_type_to_set = attr_integral_type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_SPD_REVISION_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_SPD_REVISION;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return mss::attr::get_spd_revision(i_target, o_setting);
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
        return mss::attr::set_spd_revision(i_target, i_setting);
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
        return i_spd_data.revision(o_setting);
    }
};

} // namespace mss

#endif
