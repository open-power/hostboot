/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file pre_data_init.H
/// @brief Class to set preliminary eff_config attributes
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_GEN_DATA_ENGINE_H_
#define _MSS_GEN_DATA_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/attr_engine_traits.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>

namespace mss
{

///
/// @brief Alias for function pointer to spd_facade timing methods
///
using spd_facade_fptr = fapi2::ReturnCode (spd::facade::*)(int64_t& o_timing_in_mtb) const;

///
/// @brief Algorithm to calculate SPD timings in nCK
/// @tparam ET SPD fields enumeration (e.g. attr_eff_engine_fields)
/// @tparam F SPD field
/// @tparam OT output type
/// @tparam TT defaulted to setTimingTraits<ET, F>
/// @param[in] i_spd the SPD data
/// @param[out] o_timing_in_ps SPD timing value in picoseconds
/// @return FAPI2_RC_SUCCESS iff okay
///
template < typename ET,
           ET F,
           typename OT,
           typename TT = setTimingTraits<ET, F> >
inline fapi2::ReturnCode calc_spd_time_in_ps(const spd::facade& i_spd,
        OT& o_timing_in_ps)
{
    const auto l_dimm = i_spd.get_dimm_target();
    int64_t l_timing_mtb = 0;
    int64_t l_timing_ftb = 0;
    int64_t l_mtb = 0;
    int64_t l_ftb = 0;

    FAPI_TRY( spd::get_timebases(i_spd, l_mtb, l_ftb) );

    FAPI_TRY( (i_spd.*TT::get_timing_in_mtb)(l_timing_mtb),
              "Failed to get % (in MTB) for %s", TT::TIMING_NAME,  spd::c_str(l_dimm) );
    FAPI_TRY( (i_spd.*TT::get_timing_in_ftb)(l_timing_ftb),
              "Failed to get %s (in FTB) for %s", TT::TIMING_NAME, spd::c_str(l_dimm) );

    FAPI_DBG("%s medium timebase (ps): %ld, fine timebase (ps): %ld, %s (MTB): %ld, (FTB): %ld",
             spd::c_str(l_dimm), l_mtb, l_ftb, TT::TIMING_NAME, l_timing_mtb, l_timing_ftb );

    o_timing_in_ps = spd::calc_timing_from_timebase(l_timing_mtb, l_mtb, l_timing_ftb, l_ftb);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Algorithm to calculate SPD timings in nCK
/// @tparam ET SPD fields enumeration (e.g. attr_eff_engine_fields)
/// @tparam F SPD field
/// @tparam OT output type
/// @tparam TT defaulted to setTimingTraits<ET, F>
/// @param[in] i_spd the SPD data
/// @param[out] o_timing_in_ps SPD timing value in number of clocks (nCK)
/// @return FAPI2_RC_SUCCESS iff okay
///
template < typename ET,
           ET F,
           typename OT,
           typename TT = setTimingTraits<ET, F> >
inline fapi2::ReturnCode calc_spd_time_in_nck(const spd::facade& i_spd,
        OT& o_timing_in_nck)
{
    const auto l_dimm = i_spd.get_dimm_target();

    // Calculate the DIMM speed in picoseconds (a.k.a tCK == clock period)
    int64_t l_tck_in_ps = 0;
    uint64_t l_freq = 0;
    FAPI_TRY( attr::get_freq(mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm), l_freq) );
    FAPI_TRY( freq_to_ps(l_freq, l_tck_in_ps),
              "Failed to calculate clock period (tCK) for %s", spd::c_str(l_dimm) );

    {
        // Calculate the desired timing in ps
        int64_t l_timing_in_ps = 0;
        FAPI_TRY( (calc_spd_time_in_ps<ET, F>(i_spd, l_tck_in_ps)) );

        // Calculate nck
        FAPI_TRY( spd::calc_nck(l_timing_in_ps, l_tck_in_ps, spd::INVERSE_DDR4_CORRECTION_FACTOR, o_timing_in_nck),
                  "Error in calculating %s (nCK) for target %s, with value of %d",
                  TT::TIMING_NAME, spd::c_str(l_dimm), l_timing_in_ps );

        FAPI_INF("tCK (ps): %d, %s (ps): %d, %s (nck): %d",
                 l_tck_in_ps, TT::TIMING_NAME, l_timing_in_ps, TT::TIMING_NAME, o_timing_in_nck);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets preliminary data fields
/// @tparam F pre_data_init_fields
/// @tparam T FAPI2 target type
/// @tparam IT Input data type
/// @tparam TT defaulted to preDataInitTraits<T>
/// @param[in] i_setting value we want to set attr with
/// @return FAPI2_RC_SUCCESS iff okay
///
template< attr_eff_engine_fields F,
          fapi2::TargetType T,
          typename IT,
          typename TT = mss::attrEngineTraits<decltype(F), F>
          >
inline fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                                   const IT i_setting)
{
    FAPI_TRY( (gen::set_field<TT>(i_target, i_setting)),
              "Failed set_field() for %s", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Value traits for attrEnumTraits
/// @class attrEnumTraits - attr_si_engine_fields specialization
///
template < >
struct attrEnumTraits<attr_si_engine_fields>
{
    static constexpr size_t DISPATCHER = ATTR_SI_DISPATCHER;
};

///
/// @brief Value traits for attrEnumTraits
/// @class attrEnumTraits - attr_eff_engine_fields specialization
///
template < >
struct attrEnumTraits<attr_eff_engine_fields>
{
    static constexpr size_t DISPATCHER = ATTR_EFF_DISPATCHER;
};

///
/// @brief Value traits for attrEnumTraits
/// @class attrEnumTraits - attr_eff_engine_fields specialization
///
template < >
struct attrEnumTraits<pre_data_init_fields>
{
    static constexpr size_t DISPATCHER = ATTR_PRE_DATA_ENG_DISPATCHER;
};

///
/// @brief Value traits for attrEnumTraits
/// @class attrEnumTraits - attr_eff_engine_fields specialization
///
template < >
struct attrEnumTraits<attr_engine_derived_fields>
{
    static constexpr size_t DISPATCHER = ATTR_DERIVED_DISPATCHER;
};

///
/// @brief attribute signal integrity engine
/// @class attr_si_engine
/// @tparam ET field enumeration type
/// @tparam TT defaulted to attrEnumTraits<ET>
///
template < typename ET, typename TT = attrEnumTraits<ET> >
struct attr_si_engine
{
    using attr_eng_t = gen::attr_engine<ET, static_cast<ET>(TT::DISPATCHER)>;

    ///
    /// @brief Sets attr_si_engine_fields
    /// @tparam[in] IT rank input type
    /// @param[in] i_target the DIMM target
    /// @param[in] i_efd_data EFD data
    /// @param[in] i_rank current rank
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    static fapi2::ReturnCode set(const std::shared_ptr<efd::base_decoder>& i_efd_data)
    {
        return attr_eng_t::set(i_efd_data);
    }
};

///
/// @brief Data structure to set effective config EFF data
/// @class pre_attr_eff_engine
/// @tparam F attr_eff_engine_fields enum
///
template < typename ET, typename TT = attrEnumTraits<ET> >
struct attr_eff_engine
{
    using attr_eng_t = gen::attr_engine<ET, static_cast<ET>(TT::DISPATCHER)>;

    ///
    /// @brief Sets attr_si_engine_fields
    /// @param[in] i_target the DIMM target
    /// @param[in] i_spd_data EFD data
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    static fapi2::ReturnCode set(const mss::spd::facade& i_spd_data)
    {
        return attr_eng_t::set(i_spd_data);
    }
};

///
/// @brief Data structure to set effective config EFF data
/// @class attr_derived_engine
/// @tparam ET attr fields enum type
///
template < typename ET, typename TT = attrEnumTraits<ET> >
struct attr_derived_engine
{
    using attr_eng_t = gen::attr_engine<ET, static_cast<ET>(TT::DISPATCHER)>;

    ///
    /// @brief Sets attr fields denoted by an eum list
    /// @param[in] i_target the DIMM target
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    static fapi2::ReturnCode set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
    {
        return attr_eng_t::set(i_target);
    }
};

}// mss

#endif
