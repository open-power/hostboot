/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/pos.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file pos.H
/// @brief Tools to return target's position from a fapi2 target
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_POS_H_
#define _MSS_POS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

///
/// @brief Trait classes for the mss::pos functions
///
template<fapi2::TargetType T>
class posTraits
{
    public:
        // Needed as some targets have chip_unit_pos attributes,
        // uint8_t and some attr_pos, uint32_t. We don't really care
        // but the type checking in the macros sure does ...
        typedef uint8_t pos_type;
};

///
/// @brief DIMM Trait class for the mss::pos functions
///
template<>
class posTraits<fapi2::TARGET_TYPE_DIMM>
{
    public:
        typedef uint32_t pos_type;
};

///
/// @brief DIMM Trait class for the mss::pos functions
///
template<>
class posTraits<fapi2::TARGET_TYPE_PMIC>
{
    public:
        typedef uint32_t pos_type;
};

///
/// @brief DIMM Trait class for the mss::pos functions
///
template<>
class posTraits<fapi2::TARGET_TYPE_GENERICI2CSLAVE>
{
    public:
        typedef uint32_t pos_type;
};

///
/// @brief Processor Trait class for the mss::pos functions
///
template<>
class posTraits<fapi2::TARGET_TYPE_PROC_CHIP>
{
    public:
        typedef uint32_t pos_type;
};

namespace mss
{

///
/// @brief Return a target's position from a fapi2 target
/// @tparam T the fapi2::TargetType
/// @param[in] i_target a target representing the target in question
/// @return The position relative to the chip
///
template< fapi2::TargetType T, typename TT = posTraits<T> >
inline typename TT::pos_type pos(const fapi2::Target<T>& i_target)
{
    typename TT::pos_type l_pos = 0;

    // Don't use FAPI_TRY as you'll mess up fapi2::current_err which
    // limits where this can be used.
    if (FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    return l_pos;

fapi_try_exit:
    // If we can't get our unit position, we're in other trouble
    FAPI_ERR("can't get our chip unit position");
    fapi2::Assert(false);
    return 0;
}

///
/// @brief Return a processor's position from a fapi2 target
/// @param[in] i_target a target representing the target in question
/// @return The position relative to the chip
///
template<>
inline posTraits<fapi2::TARGET_TYPE_PROC_CHIP>::pos_type
pos(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    posTraits<fapi2::TARGET_TYPE_PROC_CHIP>::pos_type l_pos = 0;

    if (FAPI_ATTR_GET(fapi2::ATTR_POS, i_target, l_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    return l_pos;

fapi_try_exit:
    // If we can't get our position, we're in other trouble
    FAPI_ERR("can't get our position");
    fapi2::Assert(false);
    return 0;

}

///
/// @brief Return a DIMM's position from a fapi2 target
/// @param[in] i_target a target representing the target in question
/// @return The position relative to the chip
/// @warning assumes this attr is already set after pre_eff_config
///
inline posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type
pos(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type l_pos = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_DIMM_POS_METADATA, i_target, l_pos));

    return l_pos;

fapi_try_exit:
    // If we can't get our position, we're in other trouble
    FAPI_ERR("can't get our dimm position");
    fapi2::Assert(false);
    return 0;
}

///
/// @brief Return a target's relative position from a fapi2 target
/// @tparam R the fapi2::TargetType we want the position relative to
/// @tparam T the fapi2::TargetType
/// @param[in] i_target a target representing the target in question
/// @return The position relative to chiplet R
///
template< fapi2::TargetType R, fapi2::TargetType T, typename TT = posTraits<T> >
typename TT::pos_type relative_pos(const fapi2::Target<T>& i_target);

///
/// @brief Return a target's fapi position from a fapi2 target
/// @tparam T the fapi2::TargetType
/// @param[in] i_target a target representing the target in question
/// @return The position relative to the system
///
template< fapi2::TargetType T, typename TT = posTraits<T> >
inline uint32_t fapi_pos(const fapi2::Target<T>& i_target)
{
    uint32_t l_pos = 0;

    // Don't use FAPI_TRY as you'll mess up fapi2::current_err which
    // limits where this can be used.
    if (FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_target, l_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    return l_pos;

fapi_try_exit:
    // If we can't get our fapi position, we're in other trouble
    FAPI_ERR("can't get our fapi position");
    fapi2::Assert(false);
    return 0;
}

///
/// @brief Sort the provided target vector in order of pos (low to high)
///
/// @tparam T TargetType
/// @param[in,out] io_targets vector of targets to sort
///
template <fapi2::TargetType T>
inline void sort_targets_by_pos(std::vector<fapi2::Target<T>>& io_targets)
{
    std::sort(io_targets.begin(), io_targets.end(), [] (
                  const fapi2::Target<T>& l_first_target,
                  const fapi2::Target<T>& l_second_target) -> bool
    {
        return mss::fapi_pos(l_first_target) < mss::fapi_pos(l_second_target);
    });
}

}
#endif
