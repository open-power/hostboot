/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eepromif.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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

#include <list>

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
  LAST_CHIP_TYPE,
  FIRST_CHIP_TYPE = VPD_PRIMARY
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

/**
 * @brief Define a set of information about all EEPROMs in the
 *        system (primarily used to populate the devtree)
 */
struct EepromInfo_t
{
    TARGETING::Target* i2cMaster; //< I2C Master chip
    uint64_t engine; //< I2C engine (relative to master chip)
    uint64_t port; //< I2C port (relative to engine)
    uint64_t busFreq; //< Bus speed in Hz
    uint64_t devAddr; //< I2C device address (relative to port)
    uint64_t sizeKB; //< Size in KB
    uint64_t addrBytes; //< Number of bytes required for addressing
    eeprom_chip_types_t device; //< Identifies role of eeprom
    TARGETING::Target* assocTarg; //< Target associated with this device    
};

/**
 * @brief Return a set of information related to every unique
 *        EEPROM in the system
 *
 * @param[out] o_info - list of EEPROM Information
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
void getEEPROMs( std::list<EepromInfo_t>& o_info );



};  // end namespace EEPROM

#endif  // end __EEPROMIF_H

