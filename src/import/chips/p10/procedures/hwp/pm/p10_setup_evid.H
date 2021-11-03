/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_setup_evid.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_setup_evid.H
/// @brief Setup External Voltage IDs
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *Team                : PM
// *Consumed by         : HB
// *Level               : 1
///

#ifndef __P10_SETUP_EVID_H__
#define __P10_SETUP_EVID_H__

#include <fapi2.H>
#include <p10_pstate_parameter_block.H>

enum P10_SETUP_EVID_CONSTANTS
{
// By convention, the Pstate GPE will use bridge 0.  Other entities
// will use bridge 1
    BRIDGE_NUMBER = 1,

// Default voltages if mailbox -> attributes are not setup
    AVSBUS_RETRY_COUNT = 5,

};




extern "C"
{

    /// @typedef VoltageConfigActions_t
    /// enum of the two actions this hwp can perform
    /// it can either compute default voltage settings
    /// otherwise it can apply voltage setting to the system
    /// @typedef p10_setup_evid_FP_t
    /// function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode (*p10_setup_evid_FP_t) (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        const VoltageConfigActions_t);

    /// @brief Set safe mode values to DPLL fmult,fmin and fmax
    /// @param [in]  i_target TARGET_TYPE_PROC_CHIP
    /// @param [in]  i_freq_proc_refclock_khz proc clock frequency
    /// @param [in]  i_proc_dpll_divider proc dpll divider value
    //@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode
    p10_setup_dpll_values (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
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
    p10_setup_evid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                   const VoltageConfigActions_t i_action);

    /// @brief update VDD,VDN and VCS voltage values
    /// @param [in]  i_target TARGET_TYPE_PROC_CHIP
    /// @param [in]  i_bus_num AVS BUS number
    /// @param [in]  i_rail_select AVS bus rail select
    /// @param [in]  i_voltage_mv voltage value in mv
    /// @param [in]  i_ext_vrm_step_size_mv Maximum VRM step size in mv
    /// @param [in]  i_present_boot_voltage present voltage read from hw
    /// @param [in]  i_evid_value EVID setup mode
    //@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode
    p10_setup_evid_voltageWrite(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint8_t i_bus_num,
        const uint8_t i_rail_select,
        const uint32_t i_voltage_mv,
        const uint32_t i_ext_vrm_step_size_mv,
        const uint32_t i_present_boot_voltage,
        const uint8_t i_evid_value);

    /// @brief Read DPLL freq value from hw
    /// @param [in]  i_target TARGET_TYPE_PROC_CHIP
    /// @param [in]  i_freq_proc_refclock_khz proc clock frequency
    /// @param [in]  i_proc_dpll_divider proc dpll divider value
    /// @param [out] o_dpll_lesser_value dpll is greater or lesser than safe mode
    //freq
    /// @param [out] o_fmult_data dpll freq data
    /// @param [out] o_safe_model_dpll_value safe mode dpll value
    /// @param [out] o_safe_model_dpll_fmin_value safe mode dpll value for FMIN
    //@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.

    fapi2::ReturnCode
    p10_read_dpll_value (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                         const uint32_t  i_freq_proc_refclock_khz,
                         const uint32_t i_proc_dpll_divider,
                         bool&  o_dpll_lesser_value,
                         fapi2::buffer<uint64_t>& o_fmult_data,
                         uint32_t& o_safe_model_dpll_value,
                         uint32_t& o_safe_model_dpll_fmin_value);

    /// @brief Update DPLL freq value
    /// @param [in]  i_target TARGET_TYPE_PROC_CHIP
    /// @param [in]  i_safe_mode_dpll_value safe mode dpll value
    /// @param [in]  i_safe_mode_dpll_fmin_value safe mode dpll value for FMIN
    //@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode
    p10_update_dpll_value (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           const uint32_t  i_safe_mode_dpll_value,
                           const uint32_t  i_safe_mode_dpll_fmin_value);

    /// @brief Read ext voltage from hw
    /// @param [in]  i_target TARGET_TYPE_PROC_CHIP
    /// @param [in]  i_bus_num AVS BUS number
    /// @param [in]  i_rail_select AVS bus rail select
    /// @param [out] o_voltage_mv ext voltage value
    //@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode
    p10_setup_evid_voltageRead(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                               const uint8_t* i_bus_num,
                               const uint8_t* i_rail_select,
                               uint32_t* o_voltage_mv);

    /// @brief Update VDD/VCS voltage
    /// @param [in]  i_target TARGET_TYPE_PROC_CHIP
    /// @param [in]  i_bus_num AVS BUS number
    /// @param [in]  i_rail_select AVS bus rail select
    /// @param [in]  i_voltage_mv  boot mode voltage
    /// @param [in]  i_ext_vrm_step_size_mv vrm step size value
    /// @param [in]  i_present_boot_voltage boot voltage rom hw
    //@return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode
    update_VDD_VCS_voltage(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           const uint8_t* i_bus_num,
                           const uint8_t* i_rail_select,
                           const uint32_t* i_voltage_mv,
                           const uint32_t* i_ext_vrm_step_size_mv,
                           const uint32_t* i_present_boot_voltage);


} // extern C

#endif  // __P10_SETUP_EVID_H__
