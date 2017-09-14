/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_setup_evid.H $       */
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
/// @file  p9_setup_evid.H
/// @brief Setup External Voltage IDs
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *Team                : PM
// *Consumed by         : HB
// *Level               : 3
///

#ifndef __P9_SETUP_EVID_H__
#define __P9_SETUP_EVID_H__

#include <fapi2.H>
#include <p9_pstate_parameter_block.H>

extern "C"
{

/// @typedef VoltageConfigActions_t
/// enum of the two actions this hwp can perform
/// it can either compute default voltage settings
/// otherwise it can apply voltage setting to the system
    typedef enum
    {
        COMPUTE_VOLTAGE_SETTINGS,
        APPLY_VOLTAGE_SETTINGS
    } VoltageConfigActions_t;

/// @typedef p9_setup_evid_FP_t
/// function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode (*p9_setup_evid_FP_t) (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        const VoltageConfigActions_t);

/// @brief Set safe mode values to DPLL fmult,fmin and fmax
/// @param [in]  i_target TARGET_TYPE_PROC_CHIP
/// @param [in]  i_freq_proc_refclock_khz proc clock frequency
/// @param [in]  i_proc_dpll_divider proc dpll divider value
//@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode
    p9_setup_dpll_values (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                          const uint32_t  i_freq_proc_refclock_khz,
                          const uint32_t i_proc_dpll_divider);


/// @brief Read attributes containing part's boot voltages(VDD,VCS and VDN)
/// and set these voltage using the AVSBUS interface (VDD, VDN and VCS).
///
/// @param [in] i_target TARGET_TYPE_PROC_CHIP
/// @param [in] i_action Describes whether you wish to COMPUTE voltage settings
///                      during the step or if you would like to APPLY them.
/// @attr
/// @attritem  ATTR_VCS_BOOT_VOLTAGE  - 1mV grandularity setting for VCS rail
/// @attritem  ATTR_VDD_BOOT_VOLTAGE  - 1mV grandularity setting for VDD rail
/// @attritem  ATTR_VDN_BOOT_VOLTAGE  - 1mV grandularity setting for VDN rail
/// @attritem  ATTR_VDD_AVSBUS_BUSNUM - AVSBus Number having the VDD VRM
/// @attritem  ATTR_VDD_AVSBUS_RAIL   - AVSBus Rail number for VDD VRM
/// @attritem  ATTR_VDN_AVSBUS_BUSNUM - AVSBus Number having the VDN VRM
/// @attritem  ATTR_VDN_AVSBUS_RAIL   - AVSBus Rail number for VDN VRM
/// @attritem  ATTR_VCS_AVSBUS_BUSNUM - AVSBus Number having the VCS VRM
/// @attritem  ATTR_VCS_AVSBUS_RAIL   - AVSBus Rail number for VCS VRM
///
///@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode
    p9_setup_evid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  const VoltageConfigActions_t i_action);


} // extern C

#endif  // __P9_SETUP_EVID_H__
