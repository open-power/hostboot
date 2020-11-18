/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/mrs_load.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file mrs_load.H
/// @brief Code to support mrs_loads
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GENERIC_MRS_LOAD_H_
#define _GENERIC_MRS_LOAD_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>


namespace mss
{

///
/// @brief MR Parameter Error Values
/// A set of enumerations allowing one error xml/code to represent all bad parameters
/// for MR encoding. The error info will take which MR has bad encoding, one of these
/// enumerations to indicate which field was incorrect, and then the incorrect value.
///
enum mrs_bad_field
{
    WRITE_CMD_LATENCY = 0,
    WRITE_RECOVERY = 1,
    CAS_LATENCY = 2,
    OUTPUT_IMPEDANCE = 3,
    CAS_WRITE_LATENCY = 4,
    CS_CMD_LATENCY = 5,
    CA_PARITY_LATENCY = 6,
    RTT_PARK = 7,
    TCCD = 8,
    RANK = 9,
    RTT_NOM = 10,
    MPR_READ_FORMAT = 11,
    RTT_WR = 12,
    MPR_PAGE = 13,
    MPR_MODE = 14,
    WR_LVL = 15,

    // Following is for MR_NUMBER entry into the BAD_MR_PARAM ffdc
    // Set to random value so it won't be confused with an actual MR number
    // This number doesn't really matter, we should be able to back track from the function numbers alone
    MRS_LOAD = 100,
};

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
    fapi2::ReturnCode (*iv_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, ccs::instruction_t&, const uint64_t);
    fapi2::ReturnCode (*iv_dumper)(const ccs::instruction_t&, const uint64_t);

    // The delay needed after this MRS word is written
    uint64_t iv_delay;

    ///
    /// @brief Construct the mrs_data struct
    /// @param[in] i_mrs, the mrs operation
    /// @param[in] *i_func function pointer for the attribute getter
    /// @param[in] *i_dumper return code from the MRS data dumper
    /// @param[in] i_delay, the delay post mrs command
    mrs_data( const uint64_t i_mrs,
              fapi2::ReturnCode (*i_func)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&, ccs::instruction_t&, const uint64_t),
              fapi2::ReturnCode (*i_dumper)(const ccs::instruction_t&, const uint64_t),
              const uint64_t i_delay ):
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
/// @param[in] i_nvdimm_workaround switch to indicate nvdimm workaround. Default to false
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode mrs_load( const fapi2::Target<T>& i_target, const bool i_nvdimm_workaround = false );

//
/// @class perform_mrs_load_overload
/// @brief Defines the template parameters for the overloaded function
/// @tparam K, the dimm kind of the dimms to load the mrs
//
template< kind_t K >
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

//
/// @class perform_mrs_load_overload
/// @brief Defines the struct for the default kind of dimm - specialization for DEFAULT_KIND
//
template<>
struct perform_mrs_load_overload< DEFAULT_KIND >
{
    static const bool available = true;
};

//
/// @class perform_mrs_load_overload
/// @brief Defines the struct for rdimm - specialization for RDIMM_DDR4
//
template<>
struct perform_mrs_load_overload< KIND_RDIMM_DDR4 >
{
    static const bool available = true;
};

//
/// @class perform_mrs_load_overload
/// @brief Defines the struct for lrdimm - specialization for LRDIMM_DDR4
//
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
template< kind_t K = FORCE_DISPATCH >
typename std::enable_if< perform_mrs_load_overload<DEFAULT_KIND>::available, fapi2::ReturnCode>::type
perform_mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                  std::vector< ccs::instruction_t >& io_inst);

///
/// @brief Function to perform mrs load overloads
/// @param[in] i_target the dimm target for the mrs's
/// @param[in,out] io_inst the MCBIST instruction
/// @note We know we registered overloads for perform_mrs_load, so we need the entry point to
/// the dispatcher. Add a set of these for all TargetTypes which get overloads
/// for this API
///
template<>
fapi2::ReturnCode perform_mrs_load<FORCE_DISPATCH>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst);

///
/// @brief Function to perform mrs load overloads
/// @param[in] i_target the dimm target for the mrs's
/// @param[in,out] io_inst the MCBIST instruction
/// @note We know we registered overloads for perform_mrs_load, so we need the entry point to
/// the dispatcher. Add a set of these for all TargetTypes which get overloads
/// for this API
///
template<>
fapi2::ReturnCode perform_mrs_load<DEFAULT_KIND>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst);

///
/// @brief Function to perform mrs load overloads
/// @param[in] i_kind the i_target's dimm_kind struct
/// @param[in] i_target the dimm target for the mrs's
/// @param[in,out] io_inst the MCBIST instruction
/// @note boilerplate
///
template< kind_t K, bool B = perform_mrs_load_overload<K>::available >
inline fapi2::ReturnCode perform_mrs_load_dispatch( const kind_t& i_kind,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst)
{
    // We dispatch to another kind if:
    // We don't have an overload defined (B == false)
    // Or, if we do have an overload (B == true) and this is not out kind.
    if ((B == false) || ((B == true) && (K != i_kind)))
    {
        return perform_mrs_load_dispatch < (kind_t)(K - 1) > (i_kind, i_target, io_inst);
    }

    // Otherwise, we call the overload.
    return perform_mrs_load<K>(i_target, io_inst);
}

///
/// @brief Function to perform mrs load overloads
/// @param[in] i_kind the i_target's dimm_kind struct
/// @param[in] i_target the dimm target for the mrs's
/// @param[in,out] io_inst the MCBIST instruction
/// @note DEFAULT_KIND is 0 so this is the end of the recursion
///
template<>
inline fapi2::ReturnCode perform_mrs_load_dispatch<DEFAULT_KIND>(const kind_t&,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t >& io_inst)
{
    return perform_mrs_load<DEFAULT_KIND>(i_target, io_inst);
}

}//mss
#endif
