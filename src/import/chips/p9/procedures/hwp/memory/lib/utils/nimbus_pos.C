/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/nimbus_pos.C $ */
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
/// @file nimbus_pos.C
/// @brief Tools to return target's position from a fapi2 target
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/pos.H>

namespace mss
{

///
/// @brief Return a MCA's relative position from an MCBIST
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_MCA>::pos_type
relative_pos<fapi2::TARGET_TYPE_MCBIST>(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{

    typedef mcTypeTraits<mc_type::NIMBUS> TT;
    return pos(i_target) % TT::PORTS_PER_MCBIST;
}

///
/// @brief Return a DIMM's relative position from an MCS
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type
relative_pos<fapi2::TARGET_TYPE_MCS>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    typedef mcTypeTraits<mc_type::NIMBUS> TT;
    return pos(i_target) % TT::DIMMS_PER_MCS;
}

///
/// @brief Return a DIMM's relative position from an MCA
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type
relative_pos<fapi2::TARGET_TYPE_MCA>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    typedef mcTypeTraits<mc_type::NIMBUS> TT;
    return pos(i_target) % TT::DIMMS_PER_PORT;
}

///
/// @brief Return a DIMM's relative position from an MCBIST
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type
relative_pos<fapi2::TARGET_TYPE_MCBIST>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    typedef mcTypeTraits<mc_type::NIMBUS> TT;
    return pos(i_target) % TT::DIMMS_PER_MCBIST;
}

///
/// @brief Return an MCS's relative position from a processor
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_MCS>::pos_type
relative_pos<fapi2::TARGET_TYPE_PROC_CHIP>(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    typedef mcTypeTraits<mc_type::NIMBUS> TT;
    return pos(i_target) % TT::MCS_PER_PROC;
}

///
/// @brief Return an MCA's relative position from an MCS
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_MCA>::pos_type
relative_pos<fapi2::TARGET_TYPE_MCS>(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef mcTypeTraits<mc_type::NIMBUS> TT;
    return pos(i_target) % TT::PORTS_PER_MCS;
}

}// mss
