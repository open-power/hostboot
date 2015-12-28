/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/shared/mss_kind.H $        */
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
/// @file mss_kind.H
/// @brief Implementation of mss specific types
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_KIND_H_
#define _MSS_KIND_H_

#include <fapi2.H>

///
/// @brief Class to compile-time inspect whether an API has an overload
/// @note contains a static bool which defaults to false. Any overload
/// will specialize this template and replace the value with true.
///
#define REGISTER_API( __api_name, ... )                                 \
    template< mss::kind_t K, __VA_ARGS__ >                              \
    struct __api_name##_overload                                        \
    { static const bool available = false; };

//
// Overload definitions for the specializations
//
#define REGISTER_OVERLOAD( __api_name, __kind, ... )           \
    template<>                                                 \
    struct __api_name##_overload< __kind, __VA_ARGS__>         \
    { static const bool available = true; };

namespace mss
{

// These must be contiguous and unique
enum kind_t
{
    // The default, base, etc. kind. Used to define the function
    // which would be in a base class. Also used to stop the
    // metaprogramming recursion of the dispatcher functions.
    DEFAULT_KIND = 0,

    // DIMM type and DRAM Generation representation
    KIND_RDIMM_EMPTY = 1,
    KIND_RDIMM_DDR4 = 2,
    KIND_LRDIMM_EMPTY = 3,
    KIND_LRDIMM_DDR4 = 4,

    // Used to force dispatching looking for overloads
    // This moust always be one more than that largest
    // kind_t.
    FORCE_DISPATCH = 4 + 1,
};

inline mss::kind_t dimm_kind( const uint64_t l_type, const uint64_t l_gen )
{
    // This is the conditional needed to differentiate dimm type/generation
    switch (l_type)
    {
        case fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM:
            if (l_gen == fapi2::ENUM_ATTR_EFF_DRAM_GEN_EMPTY)
            {
                return KIND_RDIMM_EMPTY;
            }

            if (l_gen == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
            {
                return KIND_RDIMM_DDR4;
            }

            return DEFAULT_KIND;
            break;

        case fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM:
            if (l_gen == fapi2::ENUM_ATTR_EFF_DRAM_GEN_EMPTY)
            {
                return KIND_LRDIMM_EMPTY;
            }

            if (l_gen == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
            {
                return KIND_LRDIMM_DDR4;
            }

            return DEFAULT_KIND;
            break;

        default:
            return DEFAULT_KIND;
            break;
    };
}

}
#endif
