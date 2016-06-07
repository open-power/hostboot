/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/mrs_load.H $          */
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
/// @file mrs_load.H
/// @brief Code to support mrs_loads
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MRS_LOAD_H_
#define _MSS_MRS_LOAD_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

#include <lib/utils/c_str.H>
#include <lib/shared/mss_kind.H>

namespace mss
{

///
/// @brief A structure to represent an MRS operation
/// @tparam T, the target type of the CCS engine chiplet
///
template< fapi2::TargetType T >
struct mrs_data
{
    // Which MRS# this is
    fapi2::buffer<uint8_t> iv_mrs;

    // The attribute getter. For MRS we pass in the ARR0 of the CCS instruction
    // as that allows us to encapsulate the attribute processing and the bit
    // manipulation in one function.
    fapi2::ReturnCode (*iv_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, ccs::instruction_t<T>&, const uint64_t);
    fapi2::ReturnCode (*iv_dumper)(const ccs::instruction_t<T>&, const uint64_t);

    // The delay needed after this MRS word is written
    uint64_t iv_delay;

    mrs_data( uint64_t i_mrs,
              fapi2::ReturnCode (*i_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, ccs::instruction_t<T>&, const uint64_t),
              fapi2::ReturnCode (*i_dumper)(const ccs::instruction_t<T>&, const uint64_t),
              uint64_t i_delay ):
        iv_mrs(i_mrs),
        iv_func(i_func),
        iv_dumper(i_dumper),
        iv_delay(i_delay)
    {}
};

///
/// @brief Perform the mrs_load operations
/// @tparam T, the fapi2::TargetType of i_target
/// @param[in] i_target, a fapi2::Target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode mrs_load( const fapi2::Target<T>& i_target );


//
// Implement the polymorphism for mrs_load
//

// -# Register the API.
/// -# Define the template parameters for the overloaded function
/// @note the first argument is the api name, and the rest are the api's template parameters.
/// @note this creates __api_name##_overload

template< mss::kind_t K >
struct perform_mrs_load_overload
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
struct perform_mrs_load_overload< DEFAULT_KIND >
{
    static const bool available = true;
};

template<>
struct perform_mrs_load_overload< KIND_RDIMM_DDR4 >
{
    static const bool available = true;
};

template<>
struct perform_mrs_load_overload< KIND_LRDIMM_DDR4 >
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
/// @brief Perform the mrs_load operations
/// @tparam K, the kind of DIMM we're operating on (derived)
/// @param[in] i_target, a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::kind_t K = FORCE_DISPATCH >
typename std::enable_if< perform_mrs_load_overload<DEFAULT_KIND>::available, fapi2::ReturnCode>::type
perform_mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                  std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);

//
// We know we registered overloads for perform_mrs_load, so we need the entry point to
// the dispatcher. Add a set of these for all TargetTypes which get overloads
// for this API
//
template<>
fapi2::ReturnCode perform_mrs_load<FORCE_DISPATCH>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);

template<>
fapi2::ReturnCode perform_mrs_load<DEFAULT_KIND>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);

//
// Boilerplate dispatcher
//
template< kind_t K, bool B = perform_mrs_load_overload<K>::available >
inline fapi2::ReturnCode perform_mrs_load_dispatch( const kind_t& i_kind,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst)
{
    // We dispatch to another kind if:
    // We don't have an overload defined (B == false)
    // Or, if we do have an overload (B == true) and this is not out kind.
    if ((B == false) || ((B == true) && (K != i_kind)))
    {
        return perform_mrs_load_dispatch < (kind_t)(K - 1) > (i_kind, i_target, i_inst);
    }

    // Otherwise, we call the overload.
    return perform_mrs_load<K>(i_target, i_inst);
}

// DEFAULT_KIND is 0 so this is the end of the recursion
template<>
inline fapi2::ReturnCode perform_mrs_load_dispatch<DEFAULT_KIND>(const kind_t&,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst)
{
    return perform_mrs_load<DEFAULT_KIND>(i_target, i_inst);
}

}
#endif
