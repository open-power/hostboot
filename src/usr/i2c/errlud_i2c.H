/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/errlud_i2c.H $                                    */
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
#ifndef ERRL_UD_I2C_H
#define ERRL_UD_I2C_H

/**
 *  @file errlud_i2c.H
 *
 *  Defines the classes that logs and parses various I2C and EEPROM data
 */

#include <errl/errluserdetails.H>
#include <devicefw/driverif.H>
#include "i2c_common.H"
#include "eepromdd.H"

namespace I2C
{

/**
 * @class UdI2CParms
 *
 * Adds I2C information to an error log as user detail data
 */
class UdI2CParms : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_opType       Operation Type
     *  @param i_target       Chip being detected/acted upon
     *  @param i_buflen       Length of In/Out Buffer
     *  @param i_accessType   Access Type
     *  @param i_args         Miscellaneous Parameters
     */
    UdI2CParms( uint8_t i_opType,
               TARGETING::Target * i_target,
               uint64_t i_buflen,
               int64_t i_accessType,
               misc_args_t i_args  );

    /**
     *  @brief Destructor
     */
    virtual ~UdI2CParms();

  private:
    // Disabled
    UdI2CParms(UdI2CParms &);
    UdI2CParms & operator=(UdI2CParms &);
};

} // end I2C namespace

namespace EEPROM
{
/**
 * @class UdEepromParms
 *
 * Adds EEPROM information to an error log as user detail data
 */
class UdEepromParms : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_opType       Operation Type
     *  @param i_target       Chip being detected/acted upon
     *  @param i_buflen       Length of In/Out Buffer
     *  @param i_i2cInfo      Miscellaneous Parameters
     */
    UdEepromParms( uint8_t i_opType,
                   TARGETING::Target * i_target,
                   uint64_t i_buflen,
                   eeprom_addr_t i_i2cInfo );

    /**
     *  @brief Destructor
     */
    virtual ~UdEepromParms();

  private:
    // Disabled
    UdEepromParms(UdEepromParms &);
    UdEepromParms & operator=(UdEepromParms &);
};

} // end EEPROM namespace


#endif
