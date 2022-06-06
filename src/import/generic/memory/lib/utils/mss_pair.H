/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_pair.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot

///
/// @file mss_pair.H
/// @brief Custom pair implementation for use on the SBE
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_PAIR_H_
#define _MSS_PAIR_H_

namespace mss
{

///
/// @brief Custom pair implementation
/// @tparam T1 type of the key
/// @tparam T2 type of the value
///
template <typename T1, typename T2>
class pair
{
    public:

        T1 first;
        T2 second;

        ///
        /// @brief pair constructor
        ///
        constexpr pair() :
            first(T1()),
            second(T2())
        {}


        ///
        /// @brief pair constructor
        /// @param[in] i_first
        /// @param[in] i_second
        ///
        constexpr pair(const T1& i_first, const T2& i_second) :
            first(i_first),
            second(i_second)
        {}

        ///
        /// @brief Less than operator between two pairs
        /// @param[in] i_rhs right hand side in the comparison operator
        /// @return true if i_rhs is greater than this pair class
        ///
        bool operator<(const pair<T1, T2>& i_rhs) const
        {
            if(first != i_rhs.first)
            {
                return first < i_rhs.first;
            }

            return second < i_rhs.second;
        }
};

///
/// @brief find a key value from an array of STL pairs
/// @tparam size_t N the size of the array to search through
/// @tparam T key type
/// @tparam OT value type
/// @param[in] i_array_of_pairs the input array of pairs
/// @param[in] i_key the "map" key
/// @param[out] o_value the value found from given key
/// @return true if value is found, false otherwise
/// @note ARRAY NEEDS TO BE IN SORTED ORDER
///
template<size_t N, typename T, typename OT>
bool find_value_from_key(const pair<T, OT> (&i_array_of_pairs)[N],
                         const T& i_key,
                         OT& o_value)
{
    // Comparator lambda expression
    const auto compare = [](const pair<T, OT>& i_lhs, const T & i_key)
    {
        return (i_lhs.first < i_key);
    };

    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::lower_bound(std::begin(i_array_of_pairs),
                                    std::end(i_array_of_pairs),
                                    i_key,
                                    compare);

    // Did you find it? Let me know.
    if( (l_value_iterator == std::end(i_array_of_pairs)) || (i_key != l_value_iterator->first) )
    {
        return false;
    }

    o_value = l_value_iterator->second;
    return true;

}// find_value_from_key

///
/// @brief find a key value from an array of STL pairs
/// @tparam size_t N the size of the array to search through
/// @tparam T key type
/// @tparam OT value type
/// @param[in] i_array_of_pairs the input array of pairs
/// @param[in] i_value the "map" value, the second entry in the pairs
/// @param[out] o_key the first entry in the pair
/// @return true if value is found, false otherwise
///
template<size_t N, typename T, typename OT>
bool find_key_from_value(const pair<T, OT> (&i_array_of_pairs)[N],
                         const OT& i_value,
                         T& o_key)
{
    // Comparator lambda expression
    const auto compare = [&i_value](const pair<T, OT>& i_lhs)
    {
        return (i_lhs.second == i_value);
    };

    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if(std::begin(i_array_of_pairs),
                                    std::end(i_array_of_pairs),
                                    compare);

    // Did you find it? Let me know.
    if( (l_value_iterator == std::end(i_array_of_pairs)) || (i_value != l_value_iterator->second) )
    {
        // Static cast ensures that the below print will not fail at compile time
        FAPI_INF("Did not find a mapping key to value: %d", static_cast<uint64_t>(i_value));
        return false;
    }

    o_key = l_value_iterator->first;
    return true;

}// find_value_from_key
} // namespace mss

#endif
