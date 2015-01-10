/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmipowerstate.H $                       */
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
#ifndef __IPMIPOWERSTATE_H
#define __IPMIPOWERSTATE_H
/**
 *  @file ipmiPowerState.H
 *
 *  IPMI set ACPI Power State
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <errl/errlentry.H>

namespace IPMI
{

/******************************************************************************/
// Enumerations
/******************************************************************************/
/**
 * @brief Used in Byte 1 field of the set ACPI Power State command
 */
enum ACPI_SYSTEM_POWER_STATE_TO_SET
{
    SET_SYSTEM_POWER_STATE = 0x80, // bit 7   set system power state
    SET_LEGACY_ON          = 0x20, // bit 6:0 indicates On for systems that
                                   // don't support ACPI or have ACPI
                                   // capabilities disabled

};

/**
 * @brief Used in Byte 2 field of the set ACPI Power State command
 */
enum ACPI_DEVICE_POWER_STATE_TO_SET
{
    NO_CHANGE_DEVICE_POWER  =   0x7F, // Use this value when communicating a
                                      // change to the system power state
                                      // without a change to the device
                                      // power state

};

/******************************************************************************/
// Functions
/******************************************************************************/

/**
 * @brief sets the ACPI Power State to Legacy On
 *
 * @return error
 */
errlHndl_t setACPIPowerState();


} // namespace

#endif
