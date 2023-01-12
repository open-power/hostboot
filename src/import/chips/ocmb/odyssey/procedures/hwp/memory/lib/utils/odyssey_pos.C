/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/utils/odyssey_pos.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file odyssey_pos.C
/// @brief Tools to return target's position from a fapi2 target
///
// *HWP HWP Owner: Geetha Pisapati <geetha.pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB, FSP, SBE

#include <generic/memory/lib/utils/pos.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

namespace mss
{

///
/// @brief Return a DIMM's relative position from a port
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return pos(i_target) % mcTypeTraits<mss::mc_type::ODYSSEY>::DIMMS_PER_PORT;
}

///
/// @brief Return a DIMM's relative position from an OCMB
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return pos(i_target) % (mcTypeTraits<mss::mc_type::ODYSSEY>::DIMMS_PER_PORT *
                            mcTypeTraits<mss::mc_type::ODYSSEY>::PORTS_PER_OCMB);
}

///
/// @brief Return an MEM_PORT's relative position from an OCMB
/// @param[in] i_target a target representing the target in question
/// @return The position of the memory port relative to the processor chip
///
template<>
posTraits<fapi2::TARGET_TYPE_MEM_PORT>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target)
{
    uint8_t l_rel_pos = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_target, l_rel_pos));
    return l_rel_pos;

fapi_try_exit:
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    FAPI_ERR(TARGTIDFORMAT " Attribute access error!", TARGTID);
    return 0;
}

///
/// @brief Return a TEMP_SENSOR's relative position from an OCMB
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_TEMP_SENSOR>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>&
        i_target)
{
    // TODO:ZEN:MST-1814 Add support for relative_pos for TEMP_SENSOR to OCMB_CHIP
    // Update to official code when platform support is added for TEMP_SENSOR pos attributes
    // return pos(i_target) % ody::NUM_DTS;

    // As the platform code is not working yet for pos of a TEMP_SENSOR, just returning 0 for now
    // When the platform support is available, delete the return 0 and uncomment the above code
    return 0;
}


///
/// @brief Return an MEM_PORT's relative position from itself
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template<>
posTraits<fapi2::TARGET_TYPE_MEM_PORT>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    return 0;
}

///
/// @brief Return an OCMB's relative position from a proc_chip
/// @param[in] i_target a target representing the target in question
/// @return The position of the OCMB chip relative to the processor chip
///
template<>
posTraits<fapi2::TARGET_TYPE_OCMB_CHIP>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_PROC_CHIP>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    uint8_t l_bus_pos = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BUS_POS, i_target, l_bus_pos));
    return l_bus_pos;

fapi_try_exit:
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    FAPI_ERR(TARGTIDFORMAT " Attribute access error!", TARGTID);
    return 0;
}

///
/// @brief Return a mem_port's relative position from a proc_chip
/// @param[in] i_target a target representing the target in question
/// @return The position of the memory port relative to the processor chip
///
template<>
posTraits<fapi2::TARGET_TYPE_MEM_PORT>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_PROC_CHIP>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target)
{
    typedef mcTypeTraits<mss::mc_type::ODYSSEY> TT;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    return (relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(i_target)) +
           (relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_PROC_CHIP>(l_ocmb) * TT::PORTS_PER_OCMB);
}

///
/// @brief Return an OMIC's relative position from an MC
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
/// @note this needs to live here so it doesn't cause multiple definition link errors in mss_p10 library
///
template<>
posTraits<fapi2::TARGET_TYPE_OMIC>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MC>(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    return pos(i_target) % mcTypeTraits<mss::mc_type::ODYSSEY>::OMIC_PER_MC;
}

///
/// @brief Return an OMI's relative position from an OMIC
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
/// @note this needs to live here so it doesn't cause multiple definition link errors in mss_p10 library
///
template<>
posTraits<fapi2::TARGET_TYPE_OMI>::pos_type
relative_pos<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OMIC>(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    return pos(i_target) % mcTypeTraits<mss::mc_type::ODYSSEY>::OMI_PER_OMIC;
}

}// mss
