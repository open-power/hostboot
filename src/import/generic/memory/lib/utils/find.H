/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/find.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file find.H
/// @brief Templates for finding things
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_FIND_H
#define _MSS_FIND_H

#include <fapi2.H>

#ifndef __PPE__
    #include <vector>
    #include <generic/memory/lib/utils/c_str.H>
    #include <generic/memory/lib/utils/pos.H>
    #include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#endif

namespace mss
{

///
/// @brief Helper to find a set of elements based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @param[in] std::false_type tag dispatch if T != M
/// @param[in] i_state [optional] fapi2 target state (defaults to TARGET_STATE_FUNCTIONAL)
/// @return a vector of M targets.
///
template< fapi2::TargetType M, fapi2::TargetType T >
static inline std::vector< fapi2::Target<M> > find_targets_impl( const fapi2::Target<T>& i_target,
        std::false_type,
        fapi2::TargetState i_state )
{
    return i_target.template getChildren<M>(i_state);
}

///
/// @brief Helper to find a set of elements based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @param[in] std::true_type tag dispatch if T == M
/// @param[in] i_state [optional] fapi2 target state (defaults to TARGET_STATE_FUNCTIONAL)
/// @return a vector of M targets.
///
template< fapi2::TargetType M, fapi2::TargetType T >
static inline std::vector< fapi2::Target<M> > find_targets_impl( const fapi2::Target<T>& i_target,
        std::true_type,
        fapi2::TargetState i_state )
{
    return std::vector< fapi2::Target<M> > {i_target};
}

///
/// @brief find a set of elements based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @param[in] std::true_type tag dispatch if T == M
/// @param[in] i_state [optional] fapi2 target state (defaults to TARGET_STATE_FUNCTIONAL)
/// @return a vector of M targets.
/// @note Only works for valid parent-child relationships
/// So calling find_targets<TARGET_TYPE_DIMM>(l_mca) will work here
/// but calling find_targets<TARGET_TYPE_DIMM>(l_mcs) will not work
/// Compiler will freak out and we'll never get a bad relationship/ error at runtime
/// If we do, it's on fapi2
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline std::vector< fapi2::Target<M> > find_targets( const fapi2::Target<T>& i_target,
        fapi2::TargetState i_state = fapi2::TARGET_STATE_FUNCTIONAL )
{
    return find_targets_impl<M>(i_target, std::integral_constant<bool, M == T> {}, i_state);
}

///
/// @brief Helper to find an element based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @param[in] std::false_type tag dispatch if T != M
/// @return an M target.
/// @note Only works for valid parent-child relationships
///
template< fapi2::TargetType M, fapi2::TargetType T >
static inline fapi2::Target<M> find_target_impl( const fapi2::Target<T>& i_target,
        std::false_type )
{
    return i_target.template getParent<M>();
}

///
/// @brief Helper to find an element based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @param[in] std::true_type tag dispatch if T == M
/// @return an M target.
/// @note Only works for valid parent-child relationships
///
template< fapi2::TargetType M, fapi2::TargetType T >
static inline fapi2::Target<M> find_target_impl( const fapi2::Target<T>& i_target,
        std::true_type )
{
    return i_target;
}

///
/// @brief find an element based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @return an M target.
/// @note Only works for valid parent-child relationships
/// Will work for MCA and DIMM
/// Will not work for MCS and DIMM
/// The compiler will let you know if it doesn't work
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline fapi2::Target<M> find_target( const fapi2::Target<T>& i_target)
{
    return find_target_impl<M>(i_target, std::integral_constant<bool, M == T> {});
}

#ifndef __PPE__
///
/// @brief find the OCMB_CHIP given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a OCMB_CHIP target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> find_target(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MEM_PORT>()
           .getParent<fapi2::TARGET_TYPE_OCMB_CHIP>();
}

///
/// @brief find the PROC_CHIP given a OCMB_CHIP
/// @param[in] i_target the fapi2 target OCMB_CHIP
/// @return a PROC_CHIP target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> find_target(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_OMI>()
           .getParent<fapi2::TARGET_TYPE_MC>()
           .getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
}

///
/// @brief find the MCC given a OCMB_CHIP
/// @param[in] i_target the fapi2 target OCMB_CHIP
/// @return a MCC target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCC> find_target(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_OMI>()
           .getParent<fapi2::TARGET_TYPE_MCC>();
}

/// @brief find the OMIC given a OCMB_CHIP
/// @param[in] i_target the fapi2 target OCMB_CHIP
/// @return a OMIC target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_OMIC> find_target(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_OMI>()
           .getParent<fapi2::TARGET_TYPE_OMIC>();
}

///
/// @brief find all the OCMB_CHIPs connected to a PROC_CHIP
/// @param[in] i_target a fapi2::Target PROC_CHIP
/// @param[in] i_state fapi2 target state
/// @return a vector of fapi2::TARGET_TYPE_OCMB_CHIP
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> > l_ocmbs;

    for (const auto& l_mc : i_target.getChildren<fapi2::TARGET_TYPE_MC>(i_state))
    {
        for (const auto& l_omi : l_mc.getChildren<fapi2::TARGET_TYPE_OMI>(i_state))
        {
            auto l_these_ocmbs( l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(i_state) );
            l_ocmbs.insert(l_ocmbs.end(), l_these_ocmbs.begin(), l_these_ocmbs.end());
        }
    }

    return l_ocmbs;
}

///
/// @brief find all the DIMMS connected to an MI
/// @param[in] i_target a fapi2::Target MI
/// @param[in] i_state fapi2 target state
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    for (const auto& l_omi : i_target.getChildren<fapi2::TARGET_TYPE_OMI>(i_state))
    {
        for (const auto& l_ocmb : l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(i_state))
        {
            auto l_these_dimms( l_ocmb.getChildren<fapi2::TARGET_TYPE_DIMM>(i_state) );
            l_dimms.insert(l_dimms.end(), l_these_dimms.begin(), l_these_dimms.end());
        }
    }

    return l_dimms;
}

///
/// @brief find all the OCMB_CHIPs connected to an MI
/// @param[in] i_target a fapi2::Target MI
/// @param[in] i_state fapi2 target state
/// @return a vector of fapi2::TARGET_TYPE_OCMB_CHIP
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> > l_ocmbs;

    for (const auto& l_omi : i_target.getChildren<fapi2::TARGET_TYPE_OMI>(i_state))
    {
        auto l_these_ocmbs( l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(i_state) );
        l_ocmbs.insert(l_ocmbs.end(), l_these_ocmbs.begin(), l_these_ocmbs.end());
    }

    return l_ocmbs;
}
#endif
///
/// @brief find all the MEM_PORTs connected to a PROC_CHIP
/// @param[in] i_target a fapi2::Target PROC_CHIP
/// @param[in] i_state fapi2 target state
/// @return a vector of fapi2::TARGET_TYPE_MEM_PORT
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> > l_ports;
#ifdef __PPE__
    l_ports = i_target.getChildren<fapi2::TARGET_TYPE_MEM_PORT>(i_state);
#else

    for (const auto& l_mc : i_target.getChildren<fapi2::TARGET_TYPE_MC>(i_state))
    {
        for (const auto& l_omi : l_mc.getChildren<fapi2::TARGET_TYPE_OMI>(i_state))
        {
            for (const auto& l_ocmb : l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(i_state))
            {
                auto l_these_ports( l_ocmb.getChildren<fapi2::TARGET_TYPE_MEM_PORT>(i_state) );
                l_ports.insert(l_ports.end(), l_these_ports.begin(), l_these_ports.end());
            }
        }
    }

#endif
    return l_ports;
}

#ifndef __PPE__
///
/// @brief Helper to find a set of elements based on a fapi2 target, then sort them
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @param[in] i_state [optional] fapi2 target state (defaults to TARGET_STATE_FUNCTIONAL)
/// @return a vector of M targets sorted by mss::pos (ascending)
///
template< fapi2::TargetType M, fapi2::TargetType T >
static inline std::vector< fapi2::Target<M> > find_targets_sorted_by_pos( const fapi2::Target<T>& i_target,
        fapi2::TargetState i_state = fapi2::TARGET_STATE_FUNCTIONAL )
{
    std::vector<fapi2::Target<M>> l_targets = find_targets<M, T>(i_target, i_state);
    sort_targets_by_pos(l_targets);
    return l_targets;
}

///
/// @brief find a key value from a vector of STL pairs
/// @tparam T  input type
/// @tparam OT the output type to be returned
/// @param[in] i_vector_of_pairs the input vector of pairs
/// @param[in] i_key the "map" key
/// @param[out] o_value the value found from given key
/// @return true if value is found, false otherwise
/// @note VECTOR NEEDS TO BE IN SORTED ORDER
///
template<typename T, typename OT>
bool find_value_from_key(const std::vector<std::pair<T, OT> >& i_vector_of_pairs,
                         const T& i_key,
                         OT& o_value)
{
    // Comparator lambda expression
    const auto compare = [](const std::pair<T, OT>& i_lhs, const T & i_key)
    {
        return (i_lhs.first < i_key);
    };

    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::lower_bound(i_vector_of_pairs.begin(),
                                    i_vector_of_pairs.end(),
                                    i_key,
                                    compare);

    // Did you find it? Let me know.
    if( (l_value_iterator == i_vector_of_pairs.end()) || (i_key != l_value_iterator->first) )
    {
        return false;
    }

    o_value = l_value_iterator->second;
    return true;

}// find_value_from_key

///
/// @brief find a key value from a vector of STL pairs
/// @tparam T  input type
/// @tparam OT the output type to be returned
/// @param[in] i_vector_of_pairs the input vector of pairs
/// @param[in] i_value the "map" value, the second entry in the pairs
/// @param[out] o_key the first entry in the pair
/// @return true if value is found, false otherwise
///
template<typename T, typename OT>
bool find_key_from_value(const std::vector<std::pair<T, OT> >& i_vector_of_pairs,
                         const OT& i_value,
                         T& o_key)
{
    // Comparator lambda expression
    const auto compare = [&i_value](const std::pair<T, OT>& i_lhs)
    {
        return (i_lhs.second == i_value);
    };

    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if(i_vector_of_pairs.begin(),
                                    i_vector_of_pairs.end(),
                                    compare);

    // Did you find it? Let me know.
    if( (l_value_iterator == i_vector_of_pairs.end()) || (i_value != l_value_iterator->second) )
    {
        // Static cast ensures that the below print will not fail at compile time
        FAPI_INF("Did not find a mapping key to value: %d", static_cast<uint64_t>(i_value));
        return false;
    }

    o_key = l_value_iterator->first;
    return true;

}// find_value_from_key

///
/// @brief find a key value from a C-style array of STL pairs
/// @tparam T  input type
/// @tparam OT the output type to be returned
/// @tparam N size of the array being passed in
/// @param[in] i_array the input array of pairs
/// @param[in] i_key the "map" key
/// @param[in] o_value the value found from given key
/// @return true if value is found, false otherwise
/// @note To use on short arrays. O(N), simple search
///
template<typename T, typename OT, size_t N>
bool find_value_from_key( const std::pair<T, OT> (&i_array)[N],
                          const T& i_key,
                          OT& o_value)
{
    // TK Use sort and binary search for larger arrays
    for (size_t i = 0; i < N; i++)
    {
        if (i_array[i].first == i_key)
        {
            o_value = i_array[i].second;
            return true;
        }
    }

    FAPI_ERR ("No match found for find_value_from_key");
    return false;
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
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

#endif // __PPE__
}// mss

#endif
