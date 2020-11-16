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
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
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

}//mss

#endif
