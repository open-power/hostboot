/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/unmask.H $  */
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
/// @file unmask.H
/// @brief Subroutines for unmasking and setting up MSS FIR
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_UNMASK_FIR_H_
#define _MSS_UNMASK_FIR_H_

#include <fapi2.H>

namespace mss
{

namespace unmask
{

///
/// @brief Unmask and setup actions performed after draminit_mc
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode after_draminit_mc( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after draminit_training
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode after_draminit_training( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after mss_scominit
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target of the MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode after_scominit( const fapi2::Target<T>& i_target );

///
/// @brief Unmask and setup actions performed after mss_ddr_phy_reset
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target of the MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode after_phy_reset( const fapi2::Target<T>& i_target );


}
}
#endif
