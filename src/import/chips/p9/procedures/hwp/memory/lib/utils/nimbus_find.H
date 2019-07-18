/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/nimbus_find.H $ */
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

///
/// @file nimbus_find.H
/// @brief Nimbus templates specialization for finding things
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_NIMBUS_FIND_H
#define _MSS_NIMBUS_FIND_H

#include <fapi2.H>
#include <vector>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief find the McBIST given a DIMM
/// @param[in] i_target the fapi2 target DIMM
/// @return a McBIST target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_MCBIST> find_target(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MCA>().getParent<fapi2::TARGET_TYPE_MCBIST>();
}

///
/// @brief find all the dimm connected to an MCS
/// @param[in] i_target a fapi2::Target MCS
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    for (const auto& p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>(i_state))
    {
        auto l_these_dimms( p.getChildren<fapi2::TARGET_TYPE_DIMM>(i_state) );
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
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    for (const auto& p : i_target.getChildren<fapi2::TARGET_TYPE_MCA>(i_state))
    {
        auto l_these_dimms( p.getChildren<fapi2::TARGET_TYPE_DIMM>(i_state) );
        l_dimms.insert(l_dimms.end(), l_these_dimms.begin(), l_these_dimms.end());
    }

    return l_dimms;
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

}// mss

#endif
