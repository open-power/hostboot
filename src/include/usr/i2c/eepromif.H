/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eepromif.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#ifndef __EEPROMIF_H
#define __EEPROMIF_H

namespace EEPROM
{

/**
 * @brief Enumerations to link EEPROM types to EEPROM's chip number behind
 *        a device
*/
typedef enum
{
  VPD_PRIMARY   = 0,
  VPD_BACKUP    = 1,
  SBE_PRIMARY   = 2,
  SBE_BACKUP    = 3,
  LAST_CHIP_TYPE
} eeprom_chip_types_t;

/**
 * @brief This function tests to see if the VPD_PRIMARY eeprom is present
 *        for the specific target.
 *
 * @param[in] i_target - Target device.
 *
 * @return bool - True if the eeprom is present, false otherwise.
 */
bool eepromPresence ( TARGETING::Target * i_target );



};  // end namespace EEPROM

#endif  // end __EEPROMIF_H

