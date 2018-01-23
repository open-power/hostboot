/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/mcbist_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file mcbist_workarounds.H
/// @brief Workarounds for the MCBISt engine
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_MCBIST_H_
#define _MSS_WORKAROUNDS_MCBIST_H_

#include <fapi2.H>
#include <lib/mcbist/mcbist.H>

namespace mss
{

namespace workarounds
{

namespace mcbist
{

///
/// @brief Replace reads with displays in the passed in MCBIST program
/// @param[in] the MCBIST program to check for read/display replacement
/// @note Useful for testing
///
void replace_read_helper(mss::mcbist::program<fapi2::TARGET_TYPE_MCBIST>& i_program);

///
/// @brief End of rank work around
/// For Nimbus DD1 the MCBIST engine doesn't detect the end of rank properly
/// for a 1R DIMM during a super-fast read. To work around this, we check the
/// MCBIST to see if any port has a 1R DIMM on it and if so we change our stop
/// conditions to immediate. However, because that doesn't work (by design) with
/// read, we also must change all reads to displays (slow read.)
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[in] i_program the mcbist program to check
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode end_of_rank( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                               mss::mcbist::program<fapi2::TARGET_TYPE_MCBIST>& i_program );

///
/// @brief WAT debug attention
/// For Nimbus DD1 the MCBIST engine uses the WAT debug bit as a workaround
/// @param[in] i_target the fapi2 target of the mcbist
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode wat_debug_attention( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief BROADCAST OUT OF SYNC workaround
/// A UE noise window is triggered by UE/AUEs causing an out of sync error
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[in] i_value value to enable or disable workaround
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode broadcast_out_of_sync( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const mss::states i_value );


} // close namespace mcbist
} // close namespace workarounds
} // close namespace mss

#endif

