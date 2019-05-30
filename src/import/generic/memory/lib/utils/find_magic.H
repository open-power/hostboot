/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/find_magic.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef _MSS_FIND_WITH_MAGIC_H
#define _MSS_FIND_WITH_MAGIC_H

#include <fapi2.H>
#include <vector>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief find the union of functionl targets and any magic targets
/// @note The PHY has a logic block which is only contained in the 0th PHY in the controller.
/// This makes the 0th PHY 'magic' in that it needs to always be present if not functional.
/// This function returns all functional targets and includes the magic target whether or not
/// it is truly functional.
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @return a vector of M targets.
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline std::vector< fapi2::Target<M> > find_targets_with_magic( const fapi2::Target<T>& i_target);

///
/// @brief find a set of magic elements based on a fapi2 target
/// @note The PHY has a logic block which is only contained in the 0th PHY in the controller.
/// This makes the 0th PHY 'magic' in that it needs to always be present if not functional.
/// This function returns all magic targets whether or not it is truly functional.
/// It does not include other functional or present targets.
/// @tparam M the target type to be returned
/// @tparam T the fapi2 target type of the argument
/// @param[in] i_target the fapi2 target T
/// @return a vector of M targets.
///
template< fapi2::TargetType M, fapi2::TargetType T >
inline std::vector< fapi2::Target<M> > find_magic_targets( const fapi2::Target<T>& i_target);

///
/// @brief find the magic MCA connected to an MCBIST
/// @param[in] i_target the fapi2::Target MCBIST
/// @return a vector of fapi2::TARGET_TYPE_MCA
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> >
find_magic_targets(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
{
    // The magic port is in position 0, relative to the MCBIST
    constexpr uint64_t RELATIVE_MAGIC_POS = 0;

    // This is only one magic MCA on every MCBIST, so we only return a vector of one
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCA>> l_magic_ports;

    // Get all the present MCA children and find the target with the relative position of 0
    for (const auto& p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>(fapi2::TARGET_STATE_PRESENT))
    {
        if (mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(p) == RELATIVE_MAGIC_POS)
        {
            l_magic_ports.push_back(p);
        }
    }

    // We don't care if the vector is empty. We don't know what the caller will do with this
    // and they might not care if there is no magic port either ...
    return l_magic_ports;
}

///
/// @brief find the union of functionl targets and any magic targets
/// @param[in] i_target the fapi2::Target MCBIST
/// @return a vector of i2::Target<fapi2::TARGET_TYPE_MCA>
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> >
find_targets_with_magic( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
{
    // We need the union of the functional target list and the magic target list. We can
    // get a little tricky with the MCA's - we know there's only one magic port.
    // So if the one magic port isn't in the list of functional ports, add it
    auto l_magic_ports = find_magic_targets<fapi2::TARGET_TYPE_MCA>(i_target);

    if (l_magic_ports.size() != 1)
    {
        FAPI_ERR("Found wrong number of magic ports on %s (%d)", mss::c_str(i_target), l_magic_ports.size());
        fapi2::Assert(false);
    }

    auto l_ports = mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target);
    const auto l_magic_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(l_magic_ports[0]);
    const auto l_magic_port = std::find_if(l_ports.begin(), l_ports.end(),
                                           [&l_magic_pos](const fapi2::Target<fapi2::TARGET_TYPE_MCA>& t)
    {
        // Check ports by relative position.
        const auto l_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(t);
        FAPI_DBG("checking for magic port at %d candidate is %d", l_magic_pos, l_pos);
        return l_magic_pos == l_pos;
    });

    if (l_magic_port == l_ports.end())
    {
        // Add the magic port to the front of the port vector.
        FAPI_DBG("inserting magic port %d", l_magic_pos);
        l_ports.insert(l_ports.begin(), l_magic_ports[0]);
    }

    // In either case, l_ports is the proper thing to return. Either the magic port was in
    // l_ports or it is now because we inserted it.
    return l_ports;
}

///
/// @brief Determine if a thing is functional
/// @tparam I, the type of the item we want to check for
/// @tparam P, the type of the parent which holds the things of interest
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
