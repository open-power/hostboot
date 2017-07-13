/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/bcw_load.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file bcw_load.H
/// @brief Code to support bcw_loads
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_BCW_LOAD_H_
#define _MSS_BCW_LOAD_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>

#include <generic/memory/lib/utils/c_str.H>
#include <lib/shared/mss_kind.H>

namespace mss
{

///
/// @brief Perform the bcw_load operations
/// @tparam T the fapi2::TargetType of i_target
/// @param[in] i_target a fapi2::Target
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode bcw_load( const fapi2::Target<T>& i_target );

//
// Implement the polymorphism for bcw_load
//

/// Register the API.
/// Define the template parameters for the overloaded function
/// @note the first argument is the api name, and the rest are the api's template parameters.
/// @note this creates __api_name##_overload
template< mss::kind_t K >
struct perform_bcw_load_overload
{
    static constexpr bool available = false;
};

/// Register the specific overloads. The first parameter is the name
/// of the api, the second is the kind of the element which is being
/// overloaded - an RDIMM, an LRDIMM, etc. The remaining parameters
/// indicate the specialization of the api itself.
/// @note You need to define the "DEFAULT_KIND" here as an overload. This
/// allows the mechanism to find the "base" implementation for things which
/// have no specific overload.
template<>
struct perform_bcw_load_overload< DEFAULT_KIND >
{
    static constexpr bool available = true;
};


template<>
struct perform_bcw_load_overload< KIND_RDIMM_DDR4 >
{
    // Buffer control words should not be sent for RDIMMs (NO-OP)
    static constexpr bool available = true;
};

template<>
struct perform_bcw_load_overload< KIND_LRDIMM_DDR4 >
{
    static constexpr bool available = true;
};

//
// Define the default case for overloaded calls. enable_if states that
// if there is a DEFAULT_KIND overload for this TargetType, then this
// entry point will be defined. Note the general case below is enabled if
// there is no overload defined for this TargetType
//

///
/// @brief Perform the bcw_load operations
/// @tparam K, the kind of DIMM we're operating on (derived)
/// @param[in] i_target, a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::kind_t K = FORCE_DISPATCH >
typename std::enable_if< perform_bcw_load_overload<DEFAULT_KIND>::available, fapi2::ReturnCode>::type
perform_bcw_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                  std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

//
// We know we registered overloads for perform_bcw_load, so we need the entry point to
// the dispatcher. Add a set of these for all TargetTypes which get overloads
// for this API
//

///
/// @brief Perform the bcw_load operations (FORCE_DISPATCH specialization)
/// @param[in] i_target the DIMM target
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<FORCE_DISPATCH>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief Perform the bcw_load operations (DEFAULT_KIND specialization)
/// @param[in] i_target the DIMM target
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode perform_bcw_load<DEFAULT_KIND>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

//
// Boilerplate dispatcher
//

///
/// @brief Perform the bcw_load operations
/// @tparam K the kind of DIMM we're operating on (derived)
/// @tparam B boolean that enables API from K dimm kind
/// @param[in] i_kind the dimm kind struct for the i_target
/// @param[in] i_target, a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< kind_t K, bool B = perform_bcw_load_overload<K>::available >
inline fapi2::ReturnCode perform_bcw_load_dispatch( const kind_t& i_kind,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    // We dispatch to another kind if:
    // We don't have an overload defined (B == false)
    // Or, if we do have an overload (B == true) and this is not our kind.
    if ((B == false) || ((B == true) && (K != i_kind)))
    {
        return perform_bcw_load_dispatch < (kind_t)(K - 1) > (i_kind, i_target, io_inst);
    }

    // Otherwise, we call the overload.
    return perform_bcw_load<K>(i_target, io_inst);
}

///
/// @brief Perform the bcw_load operations
/// @param[in] i_kind the dimm kind struct for the i_target
/// @param[in] i_target, a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note DEFAULT_KIND is 0 so this is the end of the recursion
///
template<>
inline fapi2::ReturnCode perform_bcw_load_dispatch<DEFAULT_KIND>(const kind_t&,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst)
{
    return perform_bcw_load<DEFAULT_KIND>(i_target, io_inst);
}

}
#endif
