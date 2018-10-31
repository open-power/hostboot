/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/nvdimm_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file nvdimm_utils.H
/// @brief Subroutines to support nvdimm backup/restore process
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

namespace nvdimm
{

///
/// @brief Disable maintenance address mode
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode maint_addr_mode_off( const fapi2::Target<T>& i_target );

///
/// @brief Helper for self_refresh_exit().
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @note Uses memdiag to read the port to force CKE back to high.
/// Stolen from mss_lab_memdiags.C
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_exit_helper( const fapi2::Target<T>& i_target );

///
/// @brief Disable refresh and put target into self-refresh
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_entry( const fapi2::Target<T>& i_target );

///
/// @brief Take the target out of self-refresh and restart refresh
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_exit( const fapi2::Target<T>& i_target );

///
/// @brief Latch write vref at per-dram basis
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///

template< fapi2::TargetType T >
fapi2::ReturnCode pda_vref_latch( const fapi2::Target<T>& i_target );

///
/// @brief Full post-restore transition for NVDIMM
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///

template< fapi2::TargetType T >
fapi2::ReturnCode post_restore_transition( const fapi2::Target<T>& i_target );

}//ns nvdimm

}//ns mss
