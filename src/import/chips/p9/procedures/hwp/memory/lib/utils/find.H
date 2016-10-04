/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/find.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_FIND_H
#define _MSS_FIND_H

#include <fapi2.H>
#include <map>
#include <vector>

#include <lib/utils/pos.H>

namespace mss
{

///
/// @brief find a set of elements based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @return a vector of M targets.
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline std::vector< fapi2::Target<M> > find_targets( const fapi2::Target<T>& i_target);

///
/// @brief find an element based on a fapi2 target
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @return an M target.
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline fapi2::Target<M> find_target( const fapi2::Target<T>& i_target );

///
/// @brief find the McBIST given a McBIST
/// @param[in] i_self the fapi2 target mcBIST
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_self)
{
    return i_self;
}

///
/// @brief find the McBIST given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCA>().getParent<fapi2::TARGET_TYPE_MCBIST>();
}

///
/// @brief find the McBIST given a MCA
/// @param[in] i_target the fapi2 target MCA
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCBIST>();
}


///
/// @brief find all the dimm connected to an MCS
/// @param[in] i_target a fapi2::Target MCS
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    // At this time, fapi2 (cronus?) doesn't seem to recognize a DIMM is the child of an MCS.
    for (const auto& p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        auto l_these_dimms( p.getChildren<fapi2::TARGET_TYPE_DIMM>() );
        l_dimms.insert(l_dimms.end(), l_these_dimms.begin(), l_these_dimms.end());
    }

    return l_dimms;
}

///
/// @brief find all the dimms connected to an MCBIST
/// @param[in] i_target a fapi2::Target MCBIST
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    for (const auto& p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        auto l_these_dimms( p.getChildren<fapi2::TARGET_TYPE_DIMM>() );
        l_dimms.insert(l_dimms.end(), l_these_dimms.begin(), l_these_dimms.end());
    }

    return l_dimms;
}

///
/// @brief find all the MCS connected to an MCBIST
/// @param[in] i_target a fapi2::Target MCBIST
/// @return a vector of fapi2::TARGET_TYPE_MCS
/// @note Cronus should support MCS children of an MCBIST - so this might be temporary
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> > find_targets
( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> > l_mcses;

    // At this time, fapi2 (cronus?) doesn't seem to recognize a MCS is the child of an MCBIST
    for (const auto& p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        fapi2::Target<fapi2::TARGET_TYPE_MCS> l_mcs = p.getParent<fapi2::TARGET_TYPE_MCS>();

        if ( l_mcses.end() == std::find_if( l_mcses.begin(), l_mcses.end(),
                                            [l_mcs](const fapi2::Target<fapi2::TARGET_TYPE_MCS>& c)
    {
        return l_mcs == c;
    }) )
        {
            l_mcses.push_back(l_mcs);
        }
    }

    return l_mcses;
}

///
/// @brief find all the MCA connected to an MCBIST
/// @param[in] i_target a fapi2::Target MCBIST
/// @return a vector of fapi2::TARGET_TYPE_MCA
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> > find_targets
( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    return i_target.getChildren<fapi2::TARGET_TYPE_MCA>();
}
///
/// @brief find all the MCA connected to an MCS
/// @param[in] i_target a fapi2::Target MCS
/// @return a vector of fapi2::TARGET_TYPE_MCA
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> > find_targets
( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target )
{
    return i_target.getChildren<fapi2::TARGET_TYPE_MCA>();
}

///
/// @brief find the MCS given a MCA
/// @param[in] i_target the fapi2 target MCA
/// @return a MCS target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCS> find_target( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCS>();
}


///
/// @brief find all the DIMM connected to an MCA
/// @param[in] i_target a fapi2::Target MCA
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > find_targets
( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    return i_target.getChildren<fapi2::TARGET_TYPE_DIMM>();
}

///
/// @brief find the MCS given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a MCS target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCS> find_target( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCA>().getParent<fapi2::TARGET_TYPE_MCS>();
}

///
/// @brief find the MCA given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a MCA target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCA> find_target( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCA>();
}


///
/// @brief find the McBIST given a MCS
/// @param[in] i_target the fapi2 target MCS
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCBIST>();
}

///
/// @brief find the PROC_CHIP given a MCBIST
/// @param[in] i_target the fapi2 target MCBIST
/// @return a PROC_CHIP target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> find_target( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&
        i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
}

///
/// @brief find all the MCBISTs connected to a PROC_CHIP
/// @param[in] i_target a fapi2::Target PROC_CHIP
/// @return a vector of fapi2::TARGET_TYPE_MCBIST
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCBIST> > find_targets( const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
{
    return i_target.getChildren<fapi2::TARGET_TYPE_MCBIST>();
}

///
/// @brief find a key value from a vector of STL pairs
/// @tparam T  input type
/// @tparam OT the output type to be returned
/// @param[in] i_vector_of_pairs the input vector of pairs
/// @param[in] i_key the "map" key
/// @param[in] o_value the value found from given key
/// @return the value corresponding to the key
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
        FAPI_ERR("Did not find a mapping value to key: %d", i_key);
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
/// @return FAPI2_RC_SUCCESS
///
template<typename T, typename OT>
fapi2::ReturnCode find_key_from_value(const std::vector<std::pair<T, OT> >& i_vector_of_pairs,
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
        FAPI_ERR("Did not find a mapping key to value: %d", i_value);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    o_key = l_value_iterator->first;
    return fapi2::FAPI2_RC_SUCCESS;

}// find_value_from_key



///
/// @brief find a key value from a C-style array of STL pairs
/// @tparam T  input type
/// @tparam OT the output type to be returned
/// @tparam N size of the array being passed in
/// @param[in] i_array the input array of pairs
/// @param[in] i_key the "map" key
/// @param[in] o_value the value found from given key
/// @return the value corresponding to the key
/// @note To use on short arrays. O(N), simple search
///
template<typename T, typename OT, size_t N>
fapi2::ReturnCode find_value_from_key( const std::pair<T, OT> (&i_array)[N],
                                       const T& i_key,
                                       OT& o_value)
{
    // TK Use sort and binary search for larger arrays
    if (i_array == nullptr)
    {
        FAPI_ERR("nullptr passed to the find_value_from_key function");
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    for (size_t i = 0; i < N; i++)
    {
        if (i_array[i].first == i_key)
        {
            o_value = i_array[i].second;
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

    FAPI_ERR ("No match found for find_value_from_key");
    return fapi2::FAPI2_RC_INVALID_PARAMETER;
}

///
/// @brief Determine if a thing is functional
/// @tparam P, the type of the parent which holds the things of interest
/// @tparam I, the type of the item we want to check for
/// @param[in] i_target the parent containing the thing we're looking for
/// @param[in] i_rel_pos the relative position of the item of interest.
/// @return bool true iff the thing at i_rel_pos is noted as functional
///
template< fapi2::TargetType I, fapi2::TargetType P >
bool is_functional( const fapi2::Target<P>& i_target, const uint64_t i_rel_pos )
{
    // Not sure of a good way to do this ... we get all the functional
    // children of the parent and look for our relative position ...
    for (const auto& i : i_target.template getChildren<I>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        if (mss::template relative_pos<P>(i) == i_rel_pos)
        {
            return true;
        }
    }

    return false;
}

}// mss

#endif
