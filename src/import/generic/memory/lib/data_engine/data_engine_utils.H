/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine_utils.H $ */
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
/// @file data_engine_utils.H
/// @brief Data engine to set memory driven data
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _MSS_DATA_ENGINE_UTILS_H_
#define _MSS_DATA_ENGINE_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/spd/ddimm/efd_decoder.H>
#include <generic/memory/lib/spd/spd_facade.H>

namespace mss
{

///
/// @class DataSetterTraits2D
/// @brief Traits for setting eff_config data
/// @tparam P proc_type
/// @tparam X size of 1st array index
/// @tparam Y size of 2nd array index
///
template < proc_type, size_t X, size_t Y >
struct DataSetterTraits2D;

///
/// @class DataSetterTraits - Nimbus, [PORT][DIMM] array specialization
/// @brief Traits for setting eff_config data
///
template < >
struct DataSetterTraits2D < proc_type::NIMBUS,
           procTraits<proc_type::NIMBUS>::PORTS_PER_MCS,
           procTraits<proc_type::NIMBUS>::DIMMS_PER_PORT
           >
{
    static constexpr fapi2::TargetType TARGET = fapi2::TARGET_TYPE_MCA;
};

///
/// @brief Helper function to update a 2D array output
/// @tparam P proc_type
/// @tparam X size of 1st array index
/// @tparam Y size of 2nd array index
/// @tparam T Input/output data type
/// @tparam TT defaulted to DataSetterTraits2D<P, X, Y>
/// @param[in] i_target the DIMM target
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data attribute data structure to set
/// @warning This is Nimbus specific until MCA alias to MEM_PORT
///
template < proc_type P,
           size_t X,
           size_t Y,
           typename T,
           typename TT = DataSetterTraits2D<P, X, Y>
           >
fapi2::ReturnCode update_data(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const T i_setting,
                              const generic_ffdc_codes i_ffdc_code,
                              T (&o_data)[X][Y])
{
    // Currenlty only valid for a DIMM target, for Nimbus, traits enforces this at compile time
    // Use case is currently for pre_eff_config which is supported in both Axone and Nimbus
    const auto l_port_index = mss::index( find_target<TT::TARGET>(i_target) );
    const auto l_dimm_index = mss::index(i_target);

    FAPI_ASSERT( l_port_index < X,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_port_index)
                 .set_LIST_SIZE(X)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(i_target),
                 "Port index (%d) was larger than max (%d) on %s",
                 l_port_index,
                 X,
                 mss::spd::c_str(i_target) );

    FAPI_ASSERT( l_dimm_index < Y,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_dimm_index)
                 .set_LIST_SIZE(Y)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(i_target),
                 "DIMM index (%d) was larger than max (%d) on %s",
                 l_dimm_index,
                 Y,
                 mss::spd::c_str(i_target) );

    o_data[l_port_index][l_dimm_index] = i_setting;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Mapping boilerplate check
/// @tparam T FAPI2 target type
/// @tparam IT map key type
/// @tparam OT map value type
/// @param[in] i_target the FAPI target
/// @param[in] i_map SPD to attribute data mapping
/// @param[in] i_ffdc_code FFDC function code
/// @param[in] i_key Key to query map
/// @param[out] o_output value from key
/// @return FAPI2_RC_SUCCESS iff okay
///
template< fapi2::TargetType T, typename IT, typename OT >
inline fapi2::ReturnCode lookup_table_check(const fapi2::Target<T>& i_target,
        const std::vector<std::pair<IT, OT>>& i_map,
        const generic_ffdc_codes i_ffdc_code,
        const IT i_key,
        OT& o_output)
{
    const bool l_is_val_found = mss::find_value_from_key(i_map, i_key, o_output);

    FAPI_ASSERT( l_is_val_found,
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(i_key)
                 .set_DATA(o_output)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(i_target),
                 "Failed to find a mapped value for %d on %s",
                 i_key,
                 mss::spd::c_str(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets attr data fields
/// @tparam P proc_type
/// @tparam TT data engine class traits (e.g. preDataInitTraits, etc.)
/// @tparam T FAPI2 target type
/// @tparam IT Input data type
/// @param[in] i_target the FAPI target
/// @param[in] i_setting value we want to set attr with
/// @return FAPI2_RC_SUCCESS iff okay
///
template< proc_type P,
          typename TT,
          fapi2::TargetType T,
          typename IT >
inline fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                                   const IT i_setting)
{
    const auto l_attr_target = mss::find_target<TT::TARGET_TYPE>(i_target);
    typename TT::attr_type l_attr_list = {};
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list) );

    FAPI_TRY( update_data<P>(i_target, i_setting, TT::FFDC_CODE, l_attr_list) );
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list) );

fapi_try_exit:
    return fapi2::current_err;
}

// Controller agnostic functions

namespace gen
{

///
/// @brief Get the target associated with the SPD facade
/// @param[in] i_data the SPD data
/// return a fapi2 DIMM target
///
static inline fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_target(const spd::facade& i_data)
{
    return i_data.get_dimm_target();
}

///
/// @brief Get the target associated with the EFD decoder
/// @param[in] i_data the EFD data
/// return a fapi2 DIMM target
///
static inline fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> get_target(const std::shared_ptr<efd::base_decoder>& i_data)
{
    return i_data->get_ocmb_target();
}

///
/// @brief Helper function to update the structure that holds attr data
/// @tparam X size of 1st array index
/// @tparam Y size of 2nd array index
/// @tparam T Input/output data type
/// @tparam FFDC the FFDC type
/// @param[in] i_efd_data the EFD data
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data attribute data structure to set
/// @return FAPI2_RC_SUCCESS iff okay
///
template < size_t X,
           size_t Y,
           typename T,
           typename FFDC >
inline fapi2::ReturnCode update_data(const std::shared_ptr<efd::base_decoder>& i_efd_data,
                                     const T i_setting,
                                     const FFDC i_ffdc_code,
                                     T (&o_data)[X][Y])
{
    const auto l_ocmb = i_efd_data->get_ocmb_target();

    // TK, remove hard-code when VPDinfo struct adds an iv_dimm index
    // For explorer we can only have 1 DDIMM (index 0), or up to 2 DIMMs
    constexpr size_t l_dimm_index = 0;
    const auto l_rank = i_efd_data->get_rank();

    FAPI_ASSERT( l_dimm_index < X,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_dimm_index)
                 .set_LIST_SIZE(X)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(l_ocmb),
                 "Dimm index (%d) was larger than max (%d) on %s",
                 l_dimm_index,
                 X,
                 mss::spd::c_str(l_ocmb) );

    FAPI_ASSERT( l_rank < Y,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_rank)
                 .set_LIST_SIZE(X)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(l_ocmb),
                 "Rank index (%d) was larger than max (%d) on %s",
                 l_rank,
                 Y,
                 mss::spd::c_str(l_ocmb) );

    FAPI_DBG("Updating data[%d][%d] with %d for %s", l_dimm_index, l_rank, i_setting, spd::c_str(l_ocmb));
    o_data[l_dimm_index][l_rank] = i_setting;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to update the structure that holds attr data
/// @tparam X size of 1st array index
/// @tparam T Input/output data type
/// @tparam FFDC the FFDC type
/// @param[in] i_data the SPD data
/// @param[in] i_target the DIMM target
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data attribute data structure to set
/// @return FAPI2_RC_SUCCESS iff okay
///
template < size_t X,
           typename T,
           typename FFDC >
inline fapi2::ReturnCode update_data( const spd::facade& i_spd_data,
                                      const T i_setting,
                                      const FFDC i_ffdc_code,
                                      T (&o_data)[X])
{
    // TK remove hard-code to DIMM0, use REL_POS attr
    const auto l_dimm = i_spd_data.get_dimm_target();
    const size_t l_dimm_index = 0;

    FAPI_ASSERT( l_dimm_index < X,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_dimm_index)
                 .set_LIST_SIZE(X)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(l_dimm),
                 "Dimm index (%d) was larger than max (%d) on %s",
                 l_dimm_index,
                 X,
                 mss::spd::c_str(l_dimm) );

    FAPI_DBG("Updating data[%d] with %d for %s", l_dimm_index, i_setting, spd::c_str(l_dimm));
    o_data[l_dimm_index] = i_setting;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to update the structure that holds attr data
/// @tparam DT the data type
/// @tparam IT Input data type
/// @tparam FFDC type
/// @tparam OT Output data type
/// @param[in] i_data the data (e.g. EFD, SPD)
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data output to set
/// @return FAPI2_RC_SUCCESS iff okay
///
template < typename DT,
           typename IT,
           typename FFDC,
           typename OT >
inline fapi2::ReturnCode update_data( const DT& i_data,
                                      const IT i_setting,
                                      const FFDC i_ffdc_code,
                                      OT& o_data )
{
    FAPI_DBG("Updating data with %d for %s", i_setting, spd::c_str(get_target(i_data)));
    o_data = i_setting;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Sets attr data fields
/// @tparam TT data engine class traits (e.g. preDataInitTraits, etc.)
/// @tparam T FAPI2 target type
/// @tparam IT Input data type
/// @param[in] i_target the FAPI target
/// @param[in] i_setting value we want to set attr with
/// @return FAPI2_RC_SUCCESS iff okay
///
template< typename TT,
          fapi2::TargetType T,
          typename IT >
inline fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                                   const IT i_setting)
{
    const auto l_attr_target = mss::find_target<TT::TARGET>(i_target);
    typename TT::attr_type l_attr_list = {};
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list) );

    FAPI_TRY( update_data(i_target, i_setting, TT::FFDC_CODE, l_attr_list) );
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to get the target associated with generic attribute setting
/// @param[in] i_target
/// return a fapi2 MEM_PORT target
///
static inline fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> get_attr_target(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_target)
{
    return mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
}

///
/// @brief Helper function to get the target associated with generic attribute setting
/// @param[in] i_target
/// return a fapi2 MEM_PORT target
///
inline fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> get_attr_target(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    // Explorer has only one MEM_PORT per OCMB, so we are looking for the 0th pos relative to the OCMB
    // Will need to update to take into account a mem_channel index in VPDinfo if we ever support this.
    // Per FW, for the DDIMM case we can't support unique settings per channel because the SPD
    // doesn't know about anything outside of the DDIMM itself.
    return mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target)[0];
}

///
/// @brief Sets attr data fields
/// @tparam TT data engine class traits (e.g. preDataInitTraits, etc.)
/// @tparam DT the data type
/// @tparam IT Input data type
/// @param[in] i_target the FAPI target
/// @param[in] i_setting value we want to set attr with
/// @return FAPI2_RC_SUCCESS iff okay
///
template< typename TT,
          typename DT,
          typename IT >
inline fapi2::ReturnCode set_field(const DT& i_data,
                                   const IT i_setting)
{
    // Grab the target associated w/the data (e.g. SPD or EFD)
    const auto l_data_target = get_target(i_data);

    // Grab the target associated w/the attribute to set
    const auto l_attr_target = get_attr_target(l_data_target);

    // Get the attribute data in its entirety
    typename TT::attr_type l_attr_list = {};
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list) );

    // Update the portion of interest (can vary per dimm and/or rank)
    FAPI_TRY( update_data(i_data, i_setting, TT::FFDC_CODE, l_attr_list) );

    // Set the contents back to the attribute
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Template recursive algorithm for setting attrs
/// @class attr_engine
/// @tparam ET enum type - conceptually a list of attrs to set
/// @tparam F enum value - the specific attr value from ET to set
/// @tparam TT defaulted to attrEngineTraits<ET, F>
/// @tparam V defaulted to void (dispatch tag)
///
template < typename ET,
           ET F,
           typename TT = mss::attrEngineTraits<ET, F>,
           typename V = void >
struct attr_engine
{
    ///
    /// @brief Sets attributes fields F in ET
    /// @tparam DT the data type
    /// @param[in] i_data the data (efd_decoder, spd_facade, etc.)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename DT >
    static fapi2::ReturnCode single_set(const DT& i_data)
    {
        typename TT::attr_integral_type l_value = 0;
        FAPI_TRY( TT::get_value_to_set(i_data, l_value) );

        FAPI_TRY( set_field<TT>(i_data, l_value) );

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Sets attributes fields F in ET
    /// @tparam DT the data type
    /// @param[in] i_data the data (efd_decoder, spd_facade, etc.)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename DT >
    static fapi2::ReturnCode set(const DT& i_data)
    {
        FAPI_TRY( (attr_engine<ET, F>::single_set(i_data)) );

        // Compiler isn't smart enough to deduce F - 1u (decrementing the enum values by 1)
        // Cast needed to help the compiler deduce this value is an ET type
        // This does the recursive call to unroll a compile-time looping of a enum list of attrs to set
        FAPI_TRY( (attr_engine < ET, static_cast<ET>(F - 1u) >::set(i_data)) );

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Algorithm for setting SI attrs
/// @class attr_engine
/// @tparam ET enum type
/// @tparam F enum value
/// @note partial specialization when F == 0 (base case). Which is a NOP.
///
template < typename ET, ET F>
struct attr_engine< ET,
           F,
           mss::attrEngineTraits<ET, F>,
           typename std::enable_if<0u == F>::type >
{
    ///
    /// @brief Sets attributes fields F in ET
    /// @tparam DT the data type
    /// @param[in] i_data the data (efd_decoder, spd_facade, etc.)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename DT >
    static fapi2::ReturnCode set(const DT& i_data)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }
};

}// gen
}//mss

#endif
