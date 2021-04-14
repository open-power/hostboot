/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_dyninit_bitvec_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

//------------------------------------------------------------------------------
/// @file  p10_dyninit_bitvec_utils.H
/// @brief Utilities for p10 dynamic init bit vector management
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer   : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

#ifndef _P10_DYNINIT_BITVEC_UTILS_H_
#define _P10_DYNINIT_BITVEC_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_dyninit_bitvec.H>

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

namespace p10_dyninit_bitvec_utils
{

///
/// @brief Test that requested bit position is within range of bit vector's
///        current precise bit count
///
/// @param[in] i_bvec    Bit vector structure
/// @param[in] i_bit     Bit position to test
///
/// @returns bool True if i_bit is in range, else false
///
bool
test_bit_in_range(
    const p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit);

///
/// @brief Assert that requested bit position is within range of bit vector's
///        current precise bit count
///
/// @param[in] i_bvec    Bit vector structure
/// @param[in] i_bit     Bit position to test
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
verify_bit_in_range(
    const p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit);

///
/// @brief Bit vector utility function -- check if specific bit position is set
///
/// @param[in]  i_bvec   Bit vector structure
/// @param[in]  i_bit    Bit position to test
/// @param[out] o_set    True if i_bit posiition is set in i_bvec, else false
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
is_bit_set(
    const p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit,
    bool& o_set);

///
/// @brief Bit vector utility function -- set specific bit position
///
/// @param[in]  i_bvec   Bit vector structure
/// @param[in]  i_bit    Bit position to set
/// @param[in]  i_desc   Bit description for trace
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
set_bit(
    p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit,
    const char* i_desc);

///
/// @brief Bit vector utility function -- clear specific bit position
///
/// @param[in]  i_bvec   Bit vector structure
/// @param[in]  i_bit    Bit position to clear
/// @param[in]  i_desc   Bit description for trace
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if i_bit is in range, else error
///
fapi2::ReturnCode
clear_bit(
    p10_dyninit_bitvec& i_bvec,
    const uint16_t i_bit,
    const char* i_desc);

///
/// @brief Dump bit vector contents for debug
///
/// @param[in]  i_bvec   Bit vector structure
///
/// @returns void
///
void
dump_bitvec(
    const p10_dyninit_bitvec& i_bvec);

///
/// @brief Initialize bit vector from platform state
///
/// Queries platform attributes to initialize bit vector content sized
/// to match build time attribute properties
///
/// @param[in]  i_target     Processor scope target for attribute query
/// @param[in]  i_type       Type of bit vector to create.  Used to query
///                          appropriate platform attributes
/// @param[out] o_bvec       Bit vector filled to platform state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
init_bitvec_from_plat(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_dyninit_bitvec_type i_type,
    p10_dyninit_bitvec& o_bvec);

///
/// @brief Push bit vector state into platform attribute storage
///
/// @param[in]  i_target     Processor scope target for attribute query
/// @param[in]  i_type       Type of bit vector to create.  Used to query
///                          appropriate platform attributes
/// @param[in]  i_bvec       Bit vector filled to platform state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
save_bitvec_to_plat(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p10_dyninit_bitvec& i_bvec);


}; // namespace p10_dyninit_bitvec_utils

#endif // _P10_DYNINIT_BITVEC_UTILS_H_
