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
/// @brief Helper function for attribute setting
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
fapi2::ReturnCode data_setter(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const T i_setting,
                              const generic_ffdc_codes i_ffdc_code,
                              T (&o_data)[X][Y])
{
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
          typename IT
          >
inline fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                                   const IT i_setting)
{
    const auto l_attr_target = mss::find_target<TT::TARGET_TYPE>(i_target);
    typename TT::attr_type l_attr_list = {};
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list) );

    FAPI_TRY( data_setter<P>(i_target, i_setting, TT::FFDC_CODE, l_attr_list) );
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list) );

fapi_try_exit:
    return fapi2::current_err;
}

}//mss

#endif
