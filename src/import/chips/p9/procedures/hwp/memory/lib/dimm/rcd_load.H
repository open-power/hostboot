/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/rcd_load.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file rcd_load.H
/// @brief Code to support rcd_loads
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RCD_LOAD_H_
#define _MSS_RCD_LOAD_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>

#include <lib/utils/c_str.H>
#include <lib/shared/mss_kind.H>

namespace mss
{

struct rcd_data
{
    // Which RC# this is
    fapi2::buffer<uint8_t> iv_rcd;

    // The attribute getter
    fapi2::ReturnCode (*iv_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t&);

    // The delay needed after this RCD word is written
    uint64_t iv_delay;

    rcd_data( uint64_t i_rcd,
              fapi2::ReturnCode (*i_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, uint8_t&),
              uint64_t i_delay ):
        iv_rcd(i_rcd),
        iv_func(i_func),
        iv_delay(i_delay)
    {}
};

///
/// @brief Perform the rcd_load operations
/// @tparam T, the fapi2::TargetType of i_target
/// @param[in] i_target, a fapi2::Target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode rcd_load( const fapi2::Target<T>& i_target );


//
// Implement the polymorphism for rcd_load
//

// -# Register the API.
/// -# Define the template parameters for the overloaded function
/// @note the first argument is the api name, and the rest are the api's template parameters.
/// @note this creates __api_name##_overload

template< mss::kind_t K >
struct perform_rcd_load_overload
{
    static const bool available = false;
};

/// -# Register the specific overloads. The first parameter is the name
/// of the api, the second is the kind of the element which is being
/// overloaded - an RDIMM, an LRDIMM, etc. The remaining parameters
/// indicate the specialization of the api itself.
/// @note You need to define the "DEFAULT_KIND" here as an overload. This
/// allows the mechanism to find the "base" implementation for things which
/// have no specific overload.
template<>
struct perform_rcd_load_overload< DEFAULT_KIND >
{
    static const bool available = true;
};

template<>
struct perform_rcd_load_overload< KIND_RDIMM_DDR4 >
{
    static const bool available = true;
};

template<>
struct perform_rcd_load_overload< KIND_LRDIMM_DDR4 >
{
    static const bool available = true;
};

///
/// -# Define the default case for overloaded calls. enable_if states that
/// if there is a DEFAULT_KIND overload for this TargetType, then this
/// entry point will be defined. Note the general case below is enabled if
/// there is no overload defined for this TargetType
///

///
/// @brief Perform the rcd_load operations
/// @tparam K, the kind of DIMM we're operating on (derived)
/// @param[in] i_target, a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::kind_t K = FORCE_DISPATCH >
typename std::enable_if< perform_rcd_load_overload<DEFAULT_KIND>::available, fapi2::ReturnCode>::type
perform_rcd_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                  std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);

//
// We know we registered overloads for perform_rcd_load, so we need the entry point to
// the dispatcher. Add a set of these for all TargetTypes which get overloads
// for this API
//
template<>
fapi2::ReturnCode perform_rcd_load<FORCE_DISPATCH>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);

template<>
fapi2::ReturnCode perform_rcd_load<DEFAULT_KIND>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);

//
// Boilerplate dispatcher
//
template< kind_t K, bool B = perform_rcd_load_overload<K>::available >
inline fapi2::ReturnCode perform_rcd_load_dispatch( const kind_t& i_kind,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst)
{
    // We dispatch to another kind if:
    // We don't have an overload defined (B == false)
    // Or, if we do have an overload (B == true) and this is not out kind.
    if ((B == false) || ((B == true) && (K != i_kind)))
    {
        return perform_rcd_load_dispatch < (kind_t)(K - 1) > (i_kind, i_target, i_inst);
    }

    // Otherwise, we call the overload.
    return perform_rcd_load<K>(i_target, i_inst);
}

// DEFAULT_KIND is 0 so this is the end of the recursion
template<>
inline fapi2::ReturnCode perform_rcd_load_dispatch<DEFAULT_KIND>(const kind_t&,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst)
{
    return perform_rcd_load<DEFAULT_KIND>(i_target, i_inst);
}

}
#endif
