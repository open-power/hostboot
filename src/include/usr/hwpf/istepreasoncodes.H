/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/istepreasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
/**
 * @file istepreasoncodes.H
 *
 * @brief Reason codes and module ids for the isteps
 *
 */
#ifndef __ISTEPREASONCODES_H
#define __ISTEPREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace ISTEP
{

/**
* @enum istepModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum istepModuleId
{
    ISTEP_INVALID_MODULE                                = 0x00,
    ISTEP_REPORTING_ERROR                               = 0x01,
    ISTEP_START_PAYLOAD_CALL_SHUTDOWN                   = 0x02,
    ISTEP_HOST_ACTIVATE_SLAVE_CORES                     = 0x03,
    ISTEP_BUILD_WINKLE_IMAGES                           = 0x04,
    ISTEP_PROC_SET_PORE_BAR                             = 0x05,
    ISTEP_HOST_ACTIVATE_MASTER                          = 0x06,
    ISTEP_SBE_CENTAUR_INIT                              = 0x07,
    ISTEP_ENABLE_CORE_CHECKSTOPS                        = 0x08,
};

/**
 * @enum istepReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum istepReasonCode
{
    ISTEP_INVALID_REASONCODE                    = ISTEP_COMP_ID | 0x00,
    ISTEP_FAILURE                               = ISTEP_COMP_ID | 0x01,
    ISTEP_TARGET_NULL                           = ISTEP_COMP_ID | 0x02,
    ISTEP_BAD_RC                                = ISTEP_COMP_ID | 0x03,
    ISTEP_FAIL_MASTER_WINKLE_RC                 = ISTEP_COMP_ID | 0x04,
    ISTEP_MM_UNMAP_ERR                          = ISTEP_COMP_ID | 0x05,
    ISTEP_LOAD_SLW_FROM_PNOR_FAILED             = ISTEP_COMP_ID | 0x06,
    ISTEP_REPAIR_LOADER_RETRY_OCCURED           = ISTEP_COMP_ID | 0x07,
    ISTEP_MM_MAP_ERR                            = ISTEP_COMP_ID | 0x08,
    ISTEP_INCORRECT_TARGET_COUNT                = ISTEP_COMP_ID | 0x09,
};  // end ISTEP

}
#endif
