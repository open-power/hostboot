/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/errlud_sbeio.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2024                        */
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
#ifndef ERRL_UD_SBEIO_H
#define ERRL_UD_SBEIO_H

/**
 *  @file errlud_sbeio.H
 *
 *  Defines the classes that logs and parses various SBEIO data
 */

#include <errl/errluserdetails.H>
//#include <devicefw/driverif.H>

namespace SBEIO
{

/**
 * @class UdSPPECodeLevels
 *
 * Adds SPPE code levels to an error log as user detail data
 */
class UdSPPECodeLevels : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_chip  chip target
     */
    UdSPPECodeLevels( TARGETING::Target * i_chip );

    /**
     *  @brief Destructor
     */
    virtual ~UdSPPECodeLevels();

  private:
};

/**
 * @class UdFFDCDetails
 *
 * Adds basic details of the SBE Response to an error log as user detail data
 */
class UdSBEResponse : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_chip  chip target
     */
    UdSBEResponse( TARGETING::TargetHandle_t i_chip, uint32_t fifo_request, uint16_t magic,
                    uint16_t primary_status, uint16_t secondary_status);

    /**
     *  @brief Destructor
     */
    virtual ~UdSBEResponse();

  private:
};

} // end SBEIO namespace

#endif
