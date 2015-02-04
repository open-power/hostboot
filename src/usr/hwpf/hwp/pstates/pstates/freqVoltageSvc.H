/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/freqVoltageSvc.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
/** @file freqVoltageSvc.H
 *  @brief Contains freqVoltage class declaration
 *
 *  This file contains information about frequency voltage service class. This
 *  class is used for reading/parsing/writing frequency and voltage related
 *  data.
 */

#ifndef __PSTATES_FREQVOLTAGESVC_H
#define __PSTATES_FREQVOLTAGESVC_H

#include <errl/errlentry.H>
#include <hwpf/fapi/fapiMvpdAccess.H>
#include <pstates.h>

namespace FREQVOLTSVC
{


/**
 *  @brief - Constants used to calculate boot voltage value and set
 *           ATTR_PROC_BOOT_VOLTAGE_VID attribute.
 */
static const uint32_t PROC_BOOT_VOLT_PORT0_ENABLE = 0x80000000;
static const uint8_t PROC_BOOT_VOLT_VDD_SHIFT = 16;
static const uint8_t PROC_BOOT_VOLT_VCS_SHIFT = 8;
static const uint32_t PROC_BOOT_VOLT_VDD_MASK = 0x00ff0000;
static const uint32_t PROC_BOOT_VOLT_VCS_MASK = 0x0000ff00;

    /**
     * @brief Set system frequency attribute
     *
     * @par Detailed Description:
     *      This function reads nominal, max turbo frequency, and min power
     *      save frequency from VPD and updates system target attributes.
     *
     * @return Error log handle indicating the status of the request
     *
     * @retval NULL  Successfully set system frequency
     * @retval !NULL Failed to set system frequency.
     */
    errlHndl_t setSysFreq();

    /**
     * @brief Run p8_build_pstate_datablock HWP
     *
     * @par Detailed Description:
     *     This function is wrapper for executing p8_build_pstate_datablock
     *     HW procedure.
     *
     * @param[in] i_procChip
     *     Valid functional Processor Chip target pointer
     * @param[out] o_data
     *     On success, holds pstate data
     *
     * @return Error log handle indicating the status of the request
     *
     * @retval NULL  Successfully retrieved pstate data
     * @retval !NULL Failed to get pstate data, ignore output
     */
    errlHndl_t runP8BuildPstateDataBlock(const TARGETING::Target * i_procChip,
                                         PstateSuperStructure * o_data);

    /**
     * @brief Run proc_get_voltage HWP
     *
     * @par Detailed Description:
     *     This function is wrapper for executing proc_get_voltage
     *     HW procedure.
     *
     * @param[in] io_procChip
     *     Valid functional Processor Chip target pointer
     * @param[in] i_bootFreqMhz
     *     Boot Frequency in MHZ
     *
     * @return Error log handle indicating the status of the request
     *
     * @retval NULL  Successfully retrieved boot voltage data
     * @retval !NULL Failed to get boot voltage, ignore output
     */
    errlHndl_t runProcGetVoltage(TARGETING::Target * io_procChip,
                                 const uint32_t i_bootFreqMhz);

    /**
     * @brief Get system frequency
     *
     * @par Detailed Description:
     *     This function reads nominal, max turbo and min PowerSave frequency
     *     from VPD.
     *     It also does validation (check if all functional core voltage data
     *     points to the same nominal frequency value). Returns error if
     *     validation fails.
     *     Max Turbo frequency returned is the lowest turbo freq of all the
     *     functional cores in the system, obtained from VPD.
     *     Min PowerSave frequency returned is the highest powersave freq of
     *     all the functional cores in the system, obtained from VPD.
     *
     * @param[out] o_sysNomFreqMhz
     *     On success, holds system nominal frequency
     *     On failure, set to zero.
     * @param[out] o_sysVPDTurboMaxFreqMhz
     *     On success, holds lowest turbo frequency
     *     On failure, set to zero.
     * @param[out] o_sysVPDPowerSaveMinFreqMhz
     *     On success, holds highest powersave frequency
     *     On failure, set to zero.
     *
     * @return Error log handle indicating the status of the request
     *
     * @retval NULL  Successfully retrieved system frequency
     * @retval !NULL Failed to get system frequency, ignore output
     */
    errlHndl_t getSysFreq(
        uint32_t & o_sysVPDPowerSaveMinFreqMhz,
        TARGETING::ATTR_NOMINAL_FREQ_MHZ_type & o_sysNomFreqMhz,
        TARGETING::ATTR_FREQ_CORE_MAX_type & o_sysVPDTurboMaxFreqMhz);

    /**
     * @brief Verify the system boot frequency attribute
     *
     * @par Detailed Description:
     *      This method reads the system's boot frequency (ATTR_BOOT_FREQ_MHZ)
     *      and verifies that it is greater than or equal to the minimum
     *      power save frequency from VPD.
     *
     * @param[in] i_pTarget
     *      Pointer to system target.
     */
    void verifyBootFreq(TARGETING::Target* const i_pTarget);

}; // end namespace FREQVOLTSVC

#endif // __PSTATES_FREQVOLTAGESVC_H
