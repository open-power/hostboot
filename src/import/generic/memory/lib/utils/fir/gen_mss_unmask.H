/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/fir/gen_mss_unmask.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file gen_mss_unmask.H
/// @brief Subroutines for unmasking and setting up MSS FIR
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GEN_MSS_UNMASK_FIR_H_
#define _GEN_MSS_UNMASK_FIR_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace unmask
{

///
/// @brief Unmask and setup actions performed after draminit_mc
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_draminit_mc( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after draminit_training
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_draminit_training( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after *_omi_init
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_mc_omi_init( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after mss_scominit
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_scominit( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after mss_ddr_phy_reset
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_phy_reset( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after exp_omi_setup
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_mc_omi_setup( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions for memdiags related FIR
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_memdiags( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions for scrub related FIR
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode after_background_scrub( const fapi2::Target<T>& i_target );

}
}
#endif
