/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eepromif.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
#include <i2c/eeprom_const.H>

namespace EEPROM
{

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
 * @brief this function will read all of the associated attributes needed
 *      to access the intended EEPROM.  These attributes will be used to
 *      determine the type of I2C device as well as how to address it via
 *      the I2C device driver.
 *
 * @param[in] i_target - Target device.
 *
 * @param[out] o_i2cInfo - The structure that will contain the attribute data
 *      read from the target device.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromReadAttributes ( TARGETING::Target * i_target,
                                  eeprom_addr_t & o_i2cInfo );


/**
 * @brief This function determines whether or not the i2cMasterPath provided
 *        along with i_i2cInfo points to a valid target. If it does not,
 *        o_target will result as NULL. If the target is valid then the
 *        o_target will point to the target pointer which i2cMasterPath
 *        represents.
 *
 * @param[in] i_target - The current Target.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *      NOTE: it is expected i2cMasterPath member is filled out
 *
 * @param[out] o_target - The "new" target that will be used for all operations
 *      from this point on.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromGetI2CMasterTarget ( TARGETING::Target * i_target,
                                      const eeprom_addr_t & i_i2cInfo,
                                      TARGETING::Target * &o_target );

/**
 * @brief Return a set of information related to every unique
 *        EEPROM in the system (currently used to build HDAT structure)
 *
 * @param[out] o_info - list of EEPROM Information
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
void getEEPROMs( std::list<EepromInfo_t>& o_info );

/**
 *
 * @brief A useful utility to dump (trace out) the EepromVpdPrimaryInfo data.
 *        Use as needed.
 *
 * @param [in] i_i2cInfo - The EepromVpdPrimaryInfo data to dump for user
 *
 */
void dumpEepromData(const TARGETING::EepromVpdPrimaryInfo & i_i2cInfo);

/**
 *
 * @brief A useful utility to dump (trace out) the eeprom_addr_t data.
 *         Use as needed.
 *
 * @param [in] i_i2cInfo - The eeprom_addr_t data to dump for user
 *
 */
void dumpEepromData(const eeprom_addr_t & i_i2cInfo);

};  // end namespace EEPROM

#endif  // end __EEPROMIF_H

