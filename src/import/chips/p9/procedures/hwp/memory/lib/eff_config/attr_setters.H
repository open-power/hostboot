/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/attr_setters.H $ */
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
/// @file attr_setters.H
/// @brief Create setter functions for mss attributes
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP




#ifndef _MSS_ATTR_SETTERS_H_
#define _MSS_ATTR_SETTERS_H_

#include <fapi2.H>



namespace mss
{
///
/// @brief Set ATTR_MSS_VOLT_VDDR and ATTR_MSS_VOLT_VPP
/// @param[in] i_target_mcs the MCS target
/// @param[in] l_selected_dram_voltage the voltage in millivolts for nominal voltage
/// @param[in] l_selected_dram_voltage_vpp voltage  in millivolts for the VPP
/// @return FAPI2_RC_SUCCESS iff ok
///

fapi2::ReturnCode set_voltage_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
        uint32_t l_selected_dram_voltage,
        uint32_t l_selected_dram_voltage_vpp);

}  // mss

#endif

