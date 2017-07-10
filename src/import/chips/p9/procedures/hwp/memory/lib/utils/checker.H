/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/checker.H $ */
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
/// @file checker.H
/// @brief Contains common functions that perform checks
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _CHECKER_H_
#define _CHECKER_H_

#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>

namespace mss
{
namespace check
{
///
/// @brief checks for invalid DQ data captured by from read FIFO
/// used for LRDIMM training appliations
/// @param[in]  i_target the dimm target
/// @param[in]  i_conditional conditional that we are testing against
/// @param[in]  i_data DQ data from DRAM
/// @param[in]  i_phase_timing phase timing we are iterating through
/// @param[in]  i_nibble nibble we are iterating through
/// @return fapi2::FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode invalid_dq_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool i_conditional,
        const fapi2::variable_buffer& i_data,
        const uint64_t i_phase_timing,
        const uint64_t i_nibble )
{
    constexpr uint64_t AADR_START = 0;
    constexpr uint64_t AADR_LEN = 64;

    constexpr uint64_t AAER_START = 64;
    constexpr uint64_t AAER_LEN = 8;

    uint64_t l_aaer = 0; // ecc
    uint64_t l_aadr = 0; // data

    // Can't printout the variable buffer directly. Extracting
    // data of interest for debugging purposes
    FAPI_TRY( i_data.extractToRight(l_aadr, AADR_START, AADR_LEN),
              "Failed to extract AADR data, start: %d, len: %d", AADR_START, AADR_LEN);

    FAPI_TRY( i_data.extractToRight(l_aaer, AAER_START, AAER_LEN),
              "Failed to extract AAER data, start: %d, len: %d", AAER_START, AAER_LEN);

    FAPI_ASSERT(i_conditional,
                fapi2::MSS_INVALID_DQ_DATA().
                set_PHASE_TIMING(i_phase_timing).
                set_NIBBLE(i_nibble).
                set_DIMM_TARGET(i_target).
                set_AADR(l_aadr).
                set_AAER(l_aaer),
                "%s. Invalid data received for phase: %d, nibble: %d, AADR: %d, AAER: %d.",
                mss::c_str(i_target), i_phase_timing,
                i_nibble, l_aadr, l_aaer );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks to make sure ATTR_MSS_MRW_TEMP_REFRESH_MODE and ATTR_MSS_MRW_FINE_REFRESH_MODE are set correctly
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note from DDR4 DRAM Spec (79-4B) 4.9.4 page 48
///
fapi2::ReturnCode temp_refresh_mode();

}// check
}// mss

#endif
