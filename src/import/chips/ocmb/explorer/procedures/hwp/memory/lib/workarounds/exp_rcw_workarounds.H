/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_rcw_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file exp_rcw_workarounds.H
/// @brief RCW related workarounds for explorer
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup:  Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef _EXP_RCW_WORKAROUNDS_H_
#define _EXP_RCW_WORKAROUNDS_H_

#include <fapi2.H>
#include <lib/ccs/ccs_explorer.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Helper function to get F0RC08 value for RCD parity enable on planar RDIMM
/// @param[in] i_target the DIMM on which to operate
/// @param[out] o_value value to be used for RCW data
/// @return FAPI2_RC_SUCCESS
///
fapi2::ReturnCode f0rc08_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                uint8_t& o_value);

///
/// @brief Enable RCD parity checking using RCWs
/// @param[in] i_target port target on which to operate
/// @param[out] o_inst a vector of CCS instructions we should add to
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode setup_rcd_parity_rcws(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        std::vector< ccs::instruction_t<mss::mc_type::EXPLORER> >& o_inst);

///
/// @brief Enable RCD parity checking using RCWs
/// @param[in] i_target ocmb_chip target on which to operate
/// @param[in] i_is_planar value of ATTR_MEM_MRW_IS_PLANAR
/// @param[in] i_has_rcd true if this target has an RCD
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode planar_enable_rcd_parity(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_planar,
        const bool i_has_rcd);

} // workarounds
} // exp
} // mss

#endif
