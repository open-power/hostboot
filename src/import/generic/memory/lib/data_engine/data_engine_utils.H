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
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/spd/ddimm/efd_decoder.H>
#include <generic/memory/lib/spd/spd_facade.H>

namespace mss
{

// Controller agnostic functions

namespace gen
{

///
/// @brief Helper to get the target associated with the SPD facade
/// @param[in] i_data the SPD data
/// return a fapi2 DIMM target
///
static inline fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_target(const spd::facade& i_data)
{
    return i_data.get_dimm_target();
}

///
/// @brief Helper to get the target associated with the EFD decoder
/// @param[in] i_data the EFD data
/// return a fapi2 DIMM target
///
static inline fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> get_target(const std::shared_ptr<efd::base_decoder>& i_data)
{
    return i_data->get_ocmb_target();
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
    const auto l_dimm = i_spd_data.get_dimm_target();
    const size_t l_dimm_index = mss::index(l_dimm);

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
/// @tparam T the FAPI2 TargetType
/// @tparam IT Input/Output data type
/// @tparam FFDC the FFDC type
/// @tparam X size of 1st array index
/// @param[in] i_target the FAPI2 target
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data attribute data structure to set
/// @return FAPI2_RC_SUCCESS iff okay
///
template < fapi2::TargetType T,
           typename IT,
           typename FFDC,
           size_t X >
inline fapi2::ReturnCode update_data( const fapi2::Target<T>& i_target,
                                      const IT i_setting,
                                      const FFDC i_ffdc_code,
                                      IT (&o_data)[X])
{
    const size_t l_dimm_index = mss::index(i_target);

    FAPI_ASSERT( l_dimm_index < X,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_dimm_index)
                 .set_LIST_SIZE(X)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(i_target),
                 "Dimm index (%d) was larger than max (%d) on %s",
                 l_dimm_index,
                 X,
                 mss::spd::c_str(i_target) );

    FAPI_DBG("Updating data[%d] with %d for %s", l_dimm_index, i_setting, spd::c_str(i_target));
    o_data[l_dimm_index] = i_setting;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to update the structure that holds attr data
/// @tparam T the FAPI2 TargetType
/// @tparam IT Input data type
/// @tparam FFDC type
/// @tparam OT Output data type
/// @param[in] i_target the FAPI2 target
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data output to set
/// @return FAPI2_RC_SUCCESS iff okay
///
template < fapi2::TargetType T,
           typename IT,
           typename FFDC,
           typename OT >
inline fapi2::ReturnCode update_data( const fapi2::Target<T>& i_target,
                                      const IT i_setting,
                                      const FFDC i_ffdc_code,
                                      OT& o_data )
{
    FAPI_DBG("Updating data with %d for %s", i_setting, spd::c_str(i_target));
    o_data = i_setting;
    return fapi2::FAPI2_RC_SUCCESS;
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
    const auto l_attr_target = mss::find_target<TT::TARGET_TYPE>(i_target);
    typename TT::attr_type l_attr_list = {};
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list) );

    FAPI_TRY( update_data(i_target, i_setting, TT::FFDC_CODE, l_attr_list) );
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list) );

fapi_try_exit:
    return fapi2::current_err;
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
    /// @tparam IT the input type
    /// @param[in] i_input input (efd_decoder, spd_facade, fapi2 target)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename IT >
    static fapi2::ReturnCode single_set(const IT& i_input)
    {
        typename TT::attr_integral_type l_value = 0;
        FAPI_TRY( TT::get_value_to_set(i_input, l_value) );

        FAPI_TRY( set_field<TT>(i_input, l_value) );

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Sets attributes fields F in ET
    /// @tparam IT the input type
    /// @param[in] i_input input (efd_decoder, spd_facade, fapi2 target)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename IT >
    static fapi2::ReturnCode set(const IT& i_input)
    {
        FAPI_TRY( (attr_engine<ET, F>::single_set(i_input)) );

        // Compiler isn't smart enough to deduce F - 1u (decrementing the enum values by 1)
        // Cast needed to help the compiler deduce this value is an ET type
        // This does the recursive call to unroll a compile-time looping of a enum list of attrs to set
        FAPI_TRY( (attr_engine < ET, static_cast<ET>(F - 1u) >::set(i_input)) );

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
    /// @tparam IT the input type
    /// @param[in] i_input input (efd_decoder, spd_facade, fapi2 target)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename IT >
    static fapi2::ReturnCode set(const IT& i_input)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }
};

///
/// @brief Return a DIMM's position from a fapi2 target
/// @tparam TT Traits associated with DIMM position (e.g. dimmPosTraits)
/// @tparam OT the output type
/// @param[in] i_target a target representing the target in question
/// @param[out] o_value The position relative to the chip
///
template< typename TT, typename OT>
fapi2::ReturnCode dimm_pos(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, OT& o_value)
{
    const auto l_proc_pos = mss::pos( TT::get_proc(i_target) );

    typename TT::pos_type l_pos = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_target, l_pos));

    // To get the FAPI_POS to the equivilent of ATTR_POS, we need to normalize the fapi_pos value
    // to the processor (stride across which ever processor we're on) and then add in the delta
    // per processor as ATTR_POS isn't processor relative (delta is the total dimm on a processor)
    o_value = ((l_pos - (l_proc_pos * TT::DIMM_STRIDE_PER_PROC)) % TT::TOTAL_DIMM) + (TT::TOTAL_DIMM * l_proc_pos);

fapi_try_exit:
    return fapi2::current_err;
}

}// gen
}//mss

#endif
