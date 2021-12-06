/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/exp_port.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file exp_port.H
/// @brief Code to support ports
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef __MSS_EXP_PORT_H_
#define __MSS_EXP_PORT_H_

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <explorer_scom_addresses_fld_fixes.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/utils/mss_exp_conversions.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/mc/exp_port_traits.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/lib/utils/mc/gen_mss_restore_repairs.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <mss_generic_attribute_getters.H>

namespace mss
{

///
/// @brief Round the symbol from dq_to_symbol to its base multiple of 4, for use with steering
/// @param[in] i_symbol symbol from dq_to_symbol
/// @return uint8_t rounded DQ symbol
///
uint8_t symbol_rounder(const uint8_t i_symbol);

///
/// @brief Configure clock stabilization time field
/// @param[in] i_target the OCMB target to operate on
/// @param[in] i_has_rcd flag to signify existence of RCD on DIMM
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode configure_tstab(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target, const bool i_has_rcd);

}// mss

#endif
