/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/lib/utils/cumulus_find.H $ */
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
/// @file cumulus_find.H
/// @brief Templates for finding things
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CUMULUS_FIND_H
#define _MSS_CUMULUS_FIND_H

#include <fapi2.H>
#include <vector>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief find the DMI given an MBA
/// @param[in] i_target the fapi2 target MBA
/// @return a DMI target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_DMI> find_target(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>().getParent<fapi2::TARGET_TYPE_DMI>();
}

///
/// @brief find the PROC given a MEMBUF
/// @param[in] i_target the fapi2 target MEMBUF
/// @return a PROC target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> find_target(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&
        i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_DMI>().getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
}

///
/// @brief find the PROC_CHIP given a MBA
/// @param[in] i_target the fapi2 target MBA
/// @return a DMI target.
///
template<>
inline fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> find_target(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    return i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>()
           .getParent<fapi2::TARGET_TYPE_DMI>()
           .getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
}

///
/// @brief find all the MBA connected to an DMI
/// @param[in] i_target a fapi2::Target DMI
/// @return a vector of fapi2::TARGET_TYPE_MBA
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_MBA> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_MBA> > l_mbas;

    for (const auto& membuf_chip : i_target.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>(i_state))
    {
        auto l_these_mbas( membuf_chip.getChildren<fapi2::TARGET_TYPE_MBA>(i_state) );
        l_mbas.insert(l_mbas.end(), l_these_mbas.begin(), l_these_mbas.end());
    }

    return l_mbas;
}

///
/// @brief find all the DIMM connected to a centaur
/// @param[in] i_target a fapi2::Target TARGET_TYPE_MEMBUF_CHIP
/// @return a vector of fapi2::TARGET_TYPE_DIMM
///
template<>
inline std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> >
find_targets( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
              fapi2::TargetState i_state )
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms;

    for (const auto& l_mba : i_target.getChildren<fapi2::TARGET_TYPE_MBA>(i_state))
    {
        auto l_these_dimms( l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>(i_state) );
        l_dimms.insert(l_dimms.end(), l_these_dimms.begin(), l_these_dimms.end());
    }

    return l_dimms;
}

}// mss

#endif
