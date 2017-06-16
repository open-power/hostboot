/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/rosetta_map/rosetta_map.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// @file rosetta_map.H
/// @brief Mapping functions for module C4 pin names to PHY instance names
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ROSETTA_MAP_H_
#define _MSS_ROSETTA_MAP_H_

#include <vector>
#include <algorithm>
#include <fapi2.H>

#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>

namespace mss
{

///
/// @brief Types of signals/pins mapped by the rosetta_map
///
enum rosetta_type
{
    DQ,
    DQS,
    ADDRESS,
    CLOCK,
    WE,
    RAS,
    CAS,
    CS,
    CKE,
    ODT,
    BA,
    BG,
    CID,
    ACTN
};

///
/// @brief c_str specialization for rosetta_type
/// @param[in] i_input - input you want the const char * for
/// @return const char * representation of given rosetta_type
///
inline const char* c_str( const rosetta_type& i_input )
{
    switch (i_input)
    {
        case DQ:
            sprintf(c_str_storage, "DQ");
            break;

        case DQS:
            sprintf(c_str_storage, "DQS");
            break;

        case ADDRESS:
            sprintf(c_str_storage, "ADDRESS");
            break;

        case CLOCK:
            sprintf(c_str_storage, "CLOCK");
            break;

        case WE:
            sprintf(c_str_storage, "WE");
            break;

        case RAS:
            sprintf(c_str_storage, "RAS");
            break;

        case CAS:
            sprintf(c_str_storage, "CAS");
            break;

        case CS:
            sprintf(c_str_storage, "CS");
            break;

        case CKE:
            sprintf(c_str_storage, "CKE");
            break;

        case ODT:
            sprintf(c_str_storage, "ODT");
            break;

        case BA:
            sprintf(c_str_storage, "BA");
            break;

        case BG:
            sprintf(c_str_storage, "BG");
            break;

        case CID:
            sprintf(c_str_storage, "CID");
            break;

        case ACTN:
            sprintf(c_str_storage, "ACTN");
            break;

        default:
            sprintf(c_str_storage, "ERROR");
            break;
    }

    return c_str_storage;
}

namespace rosetta_map
{

// PhyMap is an alias for the mapping table for each pin type mapped in the rosetta_map
using PhyMap = std::vector<std::vector<std::pair<uint64_t, uint64_t>>>;

} // close namespace rosetta_map

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the module C4 to PHY pin mapping
/// @tparam T fapi2::TargetType representing the PHY
/// @tparam R rosetta_type enumeration of signal/pin to map
///
template< fapi2::TargetType T, rosetta_type R >
class rosettaTraits;

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for DQ
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, DQ>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for DQS
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, DQS>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for ADDRESS
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, ADDRESS>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for CLOCK
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, CLOCK>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for WE
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, WE>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for RAS
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, RAS>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for CAS
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, CAS>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for CS
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, CS>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for CKE
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, CKE>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for ODT
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, ODT>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for BA
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, BA>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for BG
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, BG>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for CID
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, CID>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

///
/// @class rosettaTraits
/// @brief a collection of traits associated with the Nimbus module c4 pin to PHY instance mapping for ACTN
///
template<>
class rosettaTraits<fapi2::TARGET_TYPE_MCA, ACTN>
{
    public:
        // Each pin type has a table of vector<vector<pair>>, indexed by [port][c4bit]-->{block, lane}
        static const rosetta_map::PhyMap C4_TO_PHY;
};

namespace rosetta_map
{

///
/// @brief Given a module C4 pin index, return the PHY DP16 instance and lane
/// @tparam R rosetta_type enumeration of signal/pin to map
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to rosettaTraits<T, R>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_c4_pin the index of the module C4 pin
/// @param[out] o_dp the DP instance
/// @param[out] o_lane the lane index
/// @return FAPI2_RC_SUCCESS iff ok
///
template< rosetta_type R, fapi2::TargetType T, typename TT = rosettaTraits<T, R> >
fapi2::ReturnCode c4_to_phy( const fapi2::Target<T>& i_target,
                             const uint64_t i_c4_pin,
                             uint64_t& o_dp,
                             uint64_t& o_lane )
{
    const auto l_pos = mss::pos(i_target);
    const auto& l_mapping = TT::C4_TO_PHY[l_pos];
    char l_str_buffer[fapi2::MAX_ECMD_STRING_LEN] = {};

    // Make a copy of c_str(R) so it doesn't get overwritten by mss::c_str(i_target)
    strcpy(l_str_buffer, c_str(R));

    FAPI_ASSERT(i_c4_pin < l_mapping.size(),
                fapi2::MSS_C4_PIN_OUT_OF_RANGE()
                .set_MCA_TARGET(i_target)
                .set_TYPE(R)
                .set_INDEX(i_c4_pin),
                "%s Module C4 pin type %s, index %d is beyond maximum value %d", mss::c_str(i_target), l_str_buffer, i_c4_pin,
                (l_mapping.size() - 1) );

    o_dp   = l_mapping[i_c4_pin].first;
    o_lane = l_mapping[i_c4_pin].second;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a PHY DP16 instance and lane, return the corresponding module C4 pin index
/// @tparam R rosetta_type enumeration of signal/pin to map
/// @tparam T fapi2 Target Type - derived
/// @tparam TT traits type defaults to rosettaTraits<T, R>
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_dp the DP instance
/// @param[in] i_lane the lane index
/// @param[out] o_c4_pin the index of the module C4 pin
/// @return FAPI2_RC_SUCCESS iff ok
///
template< rosetta_type R, fapi2::TargetType T, typename TT = rosettaTraits<T, R> >
fapi2::ReturnCode phy_to_c4( const fapi2::Target<T>& i_target,
                             const uint64_t i_dp,
                             const uint64_t i_lane,
                             uint64_t& o_c4_pin )
{
    const auto l_pos = mss::pos(i_target);
    const auto& l_mapping = TT::C4_TO_PHY[l_pos];
    char l_str_buffer[fapi2::MAX_ECMD_STRING_LEN] = {};

    // Make a copy of c_str(R) so it doesn't get overwritten by mss::c_str(i_target)
    strcpy(l_str_buffer, c_str(R));

    const auto l_it = std::find(l_mapping.begin(), l_mapping.end(), std::make_pair(i_dp, i_lane));

    FAPI_ASSERT(l_it != l_mapping.end(),
                fapi2::MSS_NO_C4_PIN_MAPPING()
                .set_MCA_TARGET(i_target)
                .set_TYPE(R)
                .set_DP(i_dp)
                .set_LANE(i_lane),
                "%s No module C4 pin mapping found for type %s, DP %d, lane %d", mss::c_str(i_target), l_str_buffer, i_dp, i_lane );

    o_c4_pin = l_it - l_mapping.begin();

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace rosetta_map
} // close namespace mss

#endif
