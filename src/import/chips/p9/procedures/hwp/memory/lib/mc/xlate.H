/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/xlate.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R4Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R2T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R2T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R2T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R4T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R4T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R4T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R8T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R8T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R8T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R16T4Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R16T8Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R16T16Gbx4( const dimm::kind& i_kind,
                             const uint64_t i_offset,
                             const bool i_largest,
                             fapi2::buffer<uint64_t>& io_xlate0,
                             fapi2::buffer<uint64_t>& io_xlate1,
                             fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R1T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R1T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R1T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R2T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R2T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R2T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R4T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R4T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R4T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R8T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R8T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R8T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_4R4T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 8Gbx4 DDR4 RDIMM
///
void xlate_dimm_4R4T8Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 16Gbx4 DDR4 RDIMM
///
void xlate_dimm_4R4T16Gbx4( const dimm::kind& i_kind,
                            const uint64_t i_offset,
                            const bool i_largest,
                            fapi2::buffer<uint64_t>& io_xlate0,
                            fapi2::buffer<uint64_t>& io_xlate1,
                            fapi2::buffer<uint64_t>& io_xlate2 );
///
/// @brief Helper to setup the translation map - useful for testing
/// @param[in] i_dimm_kinds std::vector of DIMM kind's representing the DIMM (Not const as we sort the vector)
/// @param[out] fapi2::buffer<uint64_t> o_xlate0  - xlt register 0's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate1  - xlt register 1's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate2  - xlt register 2's value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_xlate_map_helper( std::vector<dimm::kind>& i_dimm_kinds,
        fapi2::buffer<uint64_t>& o_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R1T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM is in slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2 total ranks 4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R2T4Gbx4( const dimm::kind& i_kind,
                           const uint64_t i_offset,
                           const bool i_largest,
                           fapi2::buffer<uint64_t>& io_xlate0,
                           fapi2::buffer<uint64_t>& io_xlate1,
                           fapi2::buffer<uint64_t>& io_xlate2 );

} // ns mc

} // ns mss

#endif
