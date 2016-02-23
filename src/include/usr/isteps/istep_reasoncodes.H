/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep_reasoncodes.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#ifndef _ISTEP_REASONCODES_H_
#define _ISTEP_REASONCODES_H_

#include <hbotcompid.H>
namespace ISTEP
{
    /**
     * @brief Defines the ISTEP error log module IDs
     */
    enum istepModuleId
    {
        MOD_INVALID_MODULE                                = 0x00,
        MOD_REPORTING_ERROR                               = 0x01,
        MOD_START_PAYLOAD_CALL_SHUTDOWN                   = 0x02,
        MOD_HOST_ACTIVATE_SLAVE_CORES                     = 0x03,
        MOD_BUILD_HCODE_IMAGES                            = 0x04,
        MOD_PROC_SET_PORE_BAR                             = 0x05,
        MOD_HOST_ACTIVATE_MASTER                          = 0x06,
        MOD_SBE_CENTAUR_INIT                              = 0x07,
        MOD_ENABLE_CORE_CHECKSTOPS                        = 0x08,
        MOD_DECONFIG_PHBS_BASED_ON_PCI_STATE              = 0x09,
        MOD_COMPUTE_PCIE_CONFIG_ATTRS                     = 0x0A,
        MOD_EXIT_CACHE_CONTAINED                          = 0x0B,
        MOD_HOST_GARD                                     = 0x0C,
    };

    /**
     * @brief Defines the ISTEP error log reason codes
     */
    enum istepReasonCode
    {
        RC_NO_MIRRORED_MEMORY                    = ISTEP_COMP_ID | 0x01,
        RC_MM_EXTEND_FAILED                      = ISTEP_COMP_ID | 0x02,
        RC_INVALID_REASONCODE                    = ISTEP_COMP_ID | 0x00,
        RC_FAILURE                               = ISTEP_COMP_ID | 0x01,
        RC_TARGET_NULL                           = ISTEP_COMP_ID | 0x02,
        RC_BAD_RC                                = ISTEP_COMP_ID | 0x03,
        RC_FAIL_MASTER_WINKLE                    = ISTEP_COMP_ID | 0x04,
        RC_MM_UNMAP_ERR                          = ISTEP_COMP_ID | 0x05,
        RC_LOAD_HCODE_FROM_PNOR_FAILED           = ISTEP_COMP_ID | 0x06,
        RC_REPAIR_LOADER_RETRY_OCCURED           = ISTEP_COMP_ID | 0x07,
        RC_MM_MAP_ERR                            = ISTEP_COMP_ID | 0x08,
        RC_INCORRECT_TARGET_COUNT                = ISTEP_COMP_ID | 0x09,
        RC_INVALID_TARGET_TYPE                   = ISTEP_COMP_ID | 0x0A,
        RC_INVALID_ATTR_VALUE                    = ISTEP_COMP_ID | 0x0B,
        RC_INVALID_CONFIGURATION                 = ISTEP_COMP_ID | 0x0C,
        RC_INVALID_PCIE_IOP_LANE_CONFIG          = ISTEP_COMP_ID | 0x0D,
        RC_MASTER_CORE_NULL                      = ISTEP_COMP_ID | 0x0E,
    };

};

#endif
