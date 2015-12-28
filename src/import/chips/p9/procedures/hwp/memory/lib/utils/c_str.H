/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/c_str.H $            */
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
/// @file c_str.H
/// @brief Function to return the C-string name of a thing
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_C_STR_H_
#define _MSS_C_STR_H_

#include <fapi2.H>

///
/// @remark To create an overloaded function a few things need to be defined.
/// Sorry.
///

/// -# Document the function and define its signature *as a comment* Why as a comment?
/// We're going to use SFINAE to expose this signature if there has been no overload
/// defined for any of the template arguments. So, we don't know if this signature will
/// be the correct one until we instantiate the template. So this is here simply for
/// documentation. We do need a simple way for our callers to know how to call this
/// non-traditionally defined function - so we do that here.

///
/// @brief return the c-string name of the input, including any extension to the name defined by its type
/// @tparam T, the fapi2::TargetType of the input - derived.
/// @param[in] i_target, the fapi2::Target of interest
/// @return char const* a thread-safe c-string containing the element's name
/// @note to call: char* s = c_str(i_target);
///
//template< fapi2::TargetType T>
//const char* c_str( const fapi2::Target<T>& i_target);

///
/// -# Include the header which defines all the macros which will
/// expand into our overload templates. Note that the pre-processor
/// is single-pass so all of the pre-requisites for the larger macros
/// need to be defined prior to including them.
///
#include "../shared/mss_kind.H"

namespace mss
{

// Thread local storage for the string we're going to create.
extern thread_local char c_str_storage[fapi2::MAX_ECMD_STRING_LEN];

/// -# Register the API.
/// -# Define the template parameters for the overloaded function
/// @note the first argument is the api name, and the rest are the api's template parameters.
/// @note this creates __api_name##_overload - so in this case it defines
/// c_str_overload which is used below to mame decisions.
REGISTER_API( c_str, fapi2::TargetType T );

/// -# Register the specific overloads. The first parameter is the name
/// of the api, the second is the kind of the element which is being
/// overloaded - an RDIMM, an LRDIMM, etc. The remaining parameters
/// indicate the specialization of the api itself.
/// @note You need to define the "DEFAULT_KIND" here as an overload. This
/// allows the mechanism to find the "base" implementation for things which
/// have no specific overload.
REGISTER_OVERLOAD( c_str, DEFAULT_KIND,      fapi2::TARGET_TYPE_DIMM );
REGISTER_OVERLOAD( c_str, KIND_RDIMM_DDR4,   fapi2::TARGET_TYPE_DIMM );
REGISTER_OVERLOAD( c_str, KIND_RDIMM_EMPTY,  fapi2::TARGET_TYPE_DIMM );
REGISTER_OVERLOAD( c_str, KIND_LRDIMM_DDR4,  fapi2::TARGET_TYPE_DIMM );
REGISTER_OVERLOAD( c_str, KIND_LRDIMM_EMPTY, fapi2::TARGET_TYPE_DIMM );

///
/// -# Define the default case for overloaded calls. enable_if states that
/// if there is a DEFAULT_KIND overload for this TargetType, then this
/// entry point will be defined. Note the general case below is enabled if
/// there is no overload defined for this TargetType
///

template< mss::kind_t K = FORCE_DISPATCH, fapi2::TargetType T >
typename std::enable_if< c_str_overload<DEFAULT_KIND, T>::available, const char*>::type
c_str( const fapi2::template Target<T>& i_target );

///
/// -# Register the handler for the API, not the overloads. This is the
/// code which implements the general case of the template. Because it
/// is not a full specialization of the template, it must be defiend in
/// this header.
///
template< fapi2::TargetType T >
typename std::enable_if < ! c_str_overload<DEFAULT_KIND, T>::available, const char* >::type
c_str( const fapi2::template Target<T>& i_target )
{
    fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );
    return c_str_storage;
}

//
// We know we registered overloads for c_str, so we need the entry point to
// the dispatcher. Add a set of these for all TargetTypes which get overloads
// for this API
//
template<>
char const* c_str<FORCE_DISPATCH, fapi2::TARGET_TYPE_DIMM>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target );

template<>
char const* c_str<DEFAULT_KIND, fapi2::TARGET_TYPE_DIMM>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target );

//
// Boilerplate dispatcher
//
template< kind_t K, fapi2::TargetType T, bool B = c_str_overload<K, T>::available >
inline char const * c_str_dispatch( const kind_t& i_kind, const fapi2::Target<T>& i_target )
{
    // We dispatch to another kind if:
    // We don't have an overload defined (B == false)
    // Or, if we do have an overload (B == true) and this is not out kind.
    if ((B == false) || ((B == true) && (K != i_kind)))
    {
        return c_str_dispatch < (kind_t)(K - 1), T > (i_kind, i_target);
    }

    // Otherwise, we call the overload.
    return c_str<K, T>(i_target);
}

// DEFAULT_KIND is 0 so this is the end of the recursion
template<>
inline char const* c_str_dispatch<DEFAULT_KIND, fapi2::TARGET_TYPE_DIMM>(const kind_t&,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return c_str<DEFAULT_KIND, fapi2::TARGET_TYPE_DIMM>(i_target);
}

}
#endif
