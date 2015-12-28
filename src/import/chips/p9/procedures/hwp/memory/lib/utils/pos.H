/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/pos.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file pos.H
/// @brief Tools to return target's position from a fapi2 target
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchailt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_POS_H_
#define _MSS_POS_H_

#include <fapi2.H>

namespace mss
{

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

template<>
class posTraits<fapi2::TARGET_TYPE_DIMM>
{
    public:
        typedef uint32_t pos_type;
};

template<>
class posTraits<fapi2::TARGET_TYPE_PROC_CHIP>
{
    public:
        typedef uint32_t pos_type;
};

///
/// @brief Return a target's position from a fapi2 target
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target, a DIMM target representing the DIMM in question
/// @return The position
///
template< fapi2::TargetType T, typename TT = posTraits<T> >
inline typename TT::pos_type pos(const fapi2::Target<T>& i_target)
{
    typename TT::pos_type i_pos = 0;

    // Don't use FAPI_TRY as you'll mess up fapi2::current_err which
    // lmits where this can be used.
    if (FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, i_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    return i_pos;

fapi_try_exit:
    // If we can't get our unit position, we're in other trouble
    FAPI_ERR("can't get our chip unit position");
    fapi2::Assert(false);
    return 0;
}

template<>
inline posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type pos(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    posTraits<fapi2::TARGET_TYPE_DIMM>::pos_type i_pos = 0;

    if (FAPI_ATTR_GET(fapi2::ATTR_POS, i_target, i_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    return i_pos;

fapi_try_exit:
    // If we can't get our position, we're in other trouble
    FAPI_ERR("can't get our position");
    fapi2::Assert(false);
    return 0;

}

template<>
inline posTraits<fapi2::TARGET_TYPE_PROC_CHIP>::pos_type pos(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&
        i_target)
{
    posTraits<fapi2::TARGET_TYPE_PROC_CHIP>::pos_type i_pos = 0;

    if (FAPI_ATTR_GET(fapi2::ATTR_POS, i_target, i_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    return i_pos;

fapi_try_exit:
    // If we can't get our position, we're in other trouble
    FAPI_ERR("can't get our position");
    fapi2::Assert(false);
    return 0;

}
}
#endif
