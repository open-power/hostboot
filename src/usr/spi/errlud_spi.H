/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/errlud_spi.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef ERRL_UD_SPI_H
#define ERRL_UD_SPI_H

/**
 *  @file errlud_spi.H
 *
 *  Defines the classes that logs and parses various SPI data
 */

#include <errl/errluserdetails.H>
#include <devicefw/driverif.H>
#include "spidd.H"

namespace SPI
{

/**
 * @class UdSpiEepromParameters
 *
 * Adds SPI EEPROM information to an error log as user detail data
 */
class UdSpiEepromParameters : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_opType       Operation Type
     *  @param i_accessType   Access Type
     *  @param i_spiOp        Class containing the SPI parameters
     */
    UdSpiEepromParameters(uint8_t i_opType,
                          int64_t i_accessType,
                          SpiEepromOp i_spiOp);

    /**
     *  @brief Destructor
     */
    virtual ~UdSpiEepromParameters();

  private:
    // Disabled
    UdSpiEepromParameters(UdSpiEepromParameters &);
    UdSpiEepromParameters & operator=(UdSpiEepromParameters &);
};


/**
 * @class UdSpiTpmParameters
 *
 * Adds SPI TPM information to an error log as user detail data
 */
class UdSpiTpmParameters : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_opType       Operation Type
     *  @param i_accessType   Access Type
     *  @param i_spiOp        Class containing the SPI parameters
     */
    UdSpiTpmParameters(uint8_t i_opType,
                       int64_t i_accessType,
                       SpiTpmOp i_spiOp);

    /**
     *  @brief Destructor
     */
    virtual ~UdSpiTpmParameters();

  private:
    // Disabled
    UdSpiTpmParameters(UdSpiTpmParameters &);
    UdSpiTpmParameters & operator=(UdSpiTpmParameters &);
};


} // end SPI namespace

#endif
