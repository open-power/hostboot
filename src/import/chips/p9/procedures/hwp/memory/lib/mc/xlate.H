/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/xlate.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file xmalte.H
/// @brief Definitions for translation registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_XLT_H_
#define _MSS_XLT_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/shared/mss_const.H>
#include <lib/utils/scom.H>
#include <lib/utils/c_str.H>
#include <lib/dimm/kind.H>

namespace mss
{

namespace mc
{

///
/// @brief A small class to represent the setup of a translation register based on DIMM characteristics
///
struct xlate_setup
{
    ///
    /// @brief Constructor to make a translation register setup structure.
    /// @param[in] i_kind a DIMM kind structure representing the ... err... kind of DIMM
    /// @param[in] i_func a function pointer to a function which does the configuring
    ///
    xlate_setup( const dimm::kind i_kind,
                 void (*i_func)( const dimm::kind&, const uint64_t, const bool,
                                 fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>& ) ):
        iv_kind(i_kind),
        iv_func(i_func)
    {
    }

    // Keep around the kind of DIMM this nugget represents
    dimm::kind iv_kind;

    // The function to call to setup the translation registers to setup for our DIMM kind.
    void (*iv_func)( const dimm::kind&, const uint64_t, const bool,
                     fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>&, fapi2::buffer<uint64_t>& );
};


///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in] o_xlate a buffer representing the xlate register to modify
/// @param[in] o_xlate1 a buffer representing the xlate register to modify
/// @param[in] o_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R4Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R4Gbx4( const dimm::kind& i_kind,
                         const uint64_t i_offset,
                         const bool i_largest,
                         fapi2::buffer<uint64_t>& o_xlate,
                         fapi2::buffer<uint64_t>& o_xlate1,
                         fapi2::buffer<uint64_t>& o_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in] o_xlate a buffer representing the xlate register to modify
/// @param[in] o_xlate1 a buffer representing the xlate register to modify
/// @param[in] o_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R4Gbx4( const dimm::kind& i_kind,
                         const uint64_t i_offset,
                         const bool i_largest,
                         fapi2::buffer<uint64_t>& o_xlate,
                         fapi2::buffer<uint64_t>& o_xlate1,
                         fapi2::buffer<uint64_t>& o_xlate2 );

} // ns mc

} // ns mss

#endif
