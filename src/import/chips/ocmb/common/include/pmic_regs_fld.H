/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/include/pmic_regs_fld.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file pmic_regs_fld.H
/// @brief PMIC Register Fields
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_REGS_FLD__
#define __PMIC_REGS_FLD__

#include <lib/utils/pmic_consts.H>

///
/// @brief Register fields for PMIC devices
/// @class pmicFields
/// @tparam P pmic_product
///
template<mss::pmic::product P>
struct pmicFields;

///
/// @brief Fields for JEDEC_COMPLIANT PMICs
///
template<>
struct pmicFields<mss::pmic::product::JEDEC_COMPLIANT>
{
    static constexpr uint8_t R2F_SECURE_MODE                = 0x02;
    static constexpr uint8_t R32_VR_ENABLE                  = 0x07;
    static constexpr uint8_t PMIC_DEVICE                    = 0x00;

    static constexpr uint8_t SWA_SWB_PHASE_MODE_SELECT      = 0x00;

    static constexpr uint8_t SWA_VOLTAGE_RANGE              = 0x05;
    static constexpr uint8_t SWB_VOLTAGE_RANGE              = 0x04;
    static constexpr uint8_t SWC_VOLTAGE_RANGE              = 0x03;
    static constexpr uint8_t SWD_VOLTAGE_RANGE              = 0x00;

    static constexpr uint8_t SEQUENCE_ENABLE                = 0x07;
    static constexpr uint8_t SEQUENCE_SWA_ENABLE            = 0x06;
    static constexpr uint8_t SEQUENCE_SWB_ENABLE            = 0x05;
    static constexpr uint8_t SEQUENCE_SWC_ENABLE            = 0x04;
    static constexpr uint8_t SEQUENCE_SWD_ENABLE            = 0x03;

    // R08
    static constexpr uint8_t R08_VIN_BULK_INPUT_PWR_GOOD_STATUS = 0x07;
    static constexpr uint8_t R08_CRITICAL_TEMP_SHUTDOWN_STATUS  = 0x06;
    static constexpr uint8_t R08_SWA_PWR_GOOD_STATUS            = 0x05;
    static constexpr uint8_t R08_SWB_PWR_GOOD_STATUS            = 0x04;
    static constexpr uint8_t R08_SWC_PWR_GOOD_STATUS            = 0x03;
    static constexpr uint8_t R08_SWD_PWR_GOOD_STATUS            = 0x02;
    static constexpr uint8_t R08_VIN_MGMT_INPUT_OVER_VOLTAGE    = 0x01;
    static constexpr uint8_t R08_VIN_BULK_INPUT_OVER_VOLTAGE    = 0x00;

    // R09
    static constexpr uint8_t R09_PMIC_HIGH_TEMP_WARNING_STATUS                      = 0x07;
    static constexpr uint8_t R09_VBIAS_PWR_GOOD_STATUS                              = 0x06;
    static constexpr uint8_t R09_VOUT_1_8_V_PWR_GOOD_STATUS                         = 0x05;
    static constexpr uint8_t R09_VIN_MGMT_TO_VIN_BULK_SWITCHOVER_STATUS             = 0x04;
    static constexpr uint8_t R09_SWA_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 0x03;
    static constexpr uint8_t R09_SWB_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 0x02;
    static constexpr uint8_t R09_SWC_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 0x01;
    static constexpr uint8_t R09_SWD_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS = 0x00;

    // R0A
    static constexpr uint8_t R0A_SWA_OUTPUT_OVER_VOLTAGE_STATUS = 0x07;
    static constexpr uint8_t R0A_SWB_OUTPUT_OVER_VOLTAGE_STATUS = 0x06;
    static constexpr uint8_t R0A_SWC_OUTPUT_OVER_VOLTAGE_STATUS = 0x05;
    static constexpr uint8_t R0A_SWD_OUTPUT_OVER_VOLTAGE_STATUS = 0x04;
    static constexpr uint8_t R0A_PEC_ERROR_STATUS               = 0x03;
    static constexpr uint8_t R0A_PARITY_ERROR_STATUS            = 0x02;
    static constexpr uint8_t R0A_IBI_STATUS                     = 0x01; // 0x00 reserved

    // R0B
    static constexpr uint8_t R0B_SWA_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 0x07;
    static constexpr uint8_t R0B_SWB_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 0x06;
    static constexpr uint8_t R0B_SWC_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 0x05;
    static constexpr uint8_t R0B_SWD_OUTPUT_CURRENT_LIMITER_WARNING_STATUS  = 0x04;
    static constexpr uint8_t R0B_SWA_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 0x03;
    static constexpr uint8_t R0B_SWB_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 0x02;
    static constexpr uint8_t R0B_SWC_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 0x01;
    static constexpr uint8_t R0B_SWD_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS    = 0x00;

    // 0x14
    static constexpr uint8_t R14_GLOBAL_CLEAR_STATUS = 0x00;

    static constexpr uint8_t DELAY_FLD_LENGTH               = 3;
    static constexpr uint8_t VOLTAGE_SETTING_START          = 0;
    static constexpr uint8_t VOLTAGE_SETTING_LENGTH         = 7;
};

#endif
