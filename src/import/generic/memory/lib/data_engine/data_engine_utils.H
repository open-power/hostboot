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
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/spd/ddimm/efd_decoder.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

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
        FAPI_TRY( (calc_spd_time_in_ps<ET, F>(i_spd, l_timing_in_ps)) );

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

    // mss::index of rank number will % 4 (RANKS_PER_DIMM) to get us the corresponding dimm
    const size_t l_dimm_index = mss::index(i_efd_data->get_rank());
    const auto l_dimm_rank = i_efd_data->get_rank() % mss::MAX_RANK_PER_DIMM; // TK HARDCODE TEST REMOVE ME!

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

    FAPI_ASSERT( l_dimm_rank < Y,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_dimm_rank)
                 .set_LIST_SIZE(X)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(l_ocmb),
                 "Rank index (%d) was larger than max (%d) on %s",
                 l_dimm_rank,
                 Y,
                 mss::spd::c_str(l_ocmb) );

    FAPI_DBG("Updating data[%d][%d] with %d for %s", l_dimm_index, l_dimm_rank, i_setting, spd::c_str(l_ocmb));
    o_data[l_dimm_index][l_dimm_rank] = i_setting;

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

    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list),
              "Failed get_attr() for %s", spd::c_str(i_target) );

    FAPI_TRY( update_data(i_target, i_setting, TT::FFDC_CODE, l_attr_list),
              "Failed update_data for %s", spd::c_str(i_target) );

    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list),
              "Failed set_attr() for %s", spd::c_str(i_target) );

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
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list),
              "Failed get_attr()");

    // Update the portion of interest (can vary per dimm and/or rank)
    FAPI_TRY( update_data(i_data, i_setting, TT::FFDC_CODE, l_attr_list),
              "Failed update_data()");

    // Set the contents back to the attribute
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list),
              "Failed set_attr()");

fapi_try_exit:
    return fapi2::current_err;
}

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
