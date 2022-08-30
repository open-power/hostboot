/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/exp_unmask.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot

///
/// @file exp_unmask.H
/// @brief Explorer specific unmask support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_EXP_UNMASK_H_
#define _MSS_EXP_UNMASK_H_

#include <fapi2.H>
#include <lib/fir/exp_fir_traits.H>

namespace mss
{
namespace exp
{
namespace unmask
{

///
/// @brief Helper for setting up the SRQ RCD parity error
/// @param[in] i_is_planar true if this is a planar system
/// @param[in] i_has_rcd true if this Explorer has an RCD
/// @param[in,out] io_srq_fir SRQ fir class
///
void srq_rcd_parity_helper(const uint8_t i_is_planar, const bool i_has_rcd,
                           mss::fir::reg<EXPLR_SRQ_SRQFIRQ>& io_srq_fir);

///
/// @brief Helper for setting the  SRQFIRQ_PORT_FAIL bit
/// @param[in] i_target the fapi2::Target
/// @param[in] i_is_planar true if this is a planar system
/// @param[in] i_has_rcd true if this Explorer has an RCD
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode  setup_srq_port_fail_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_planar,
        const bool i_has_rcd);

///
/// @brief Helper for setting up the FARB0Q bits related to RCD parity
/// @param[in] i_target the fapi2::Target
/// @param[in] i_is_planar true if this is a planar system
/// @param[in] i_has_rcd true if this Explorer has an RCD
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_farb_rcd_bits_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_planar, const bool i_has_rcd);

} // end unmask ns
} // end exp ns
} // end mss ns

#endif
