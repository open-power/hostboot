/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/errlud_pldm.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#ifndef ERRL_UD_PLDM_H
#define ERRL_UD_PLDM_H

/**
 *  @file errlud_pldm.H
 *
 *  Defines the classes that logs and parses various PLDM data
 */

#include <errl/errluserdetails.H>

namespace PLDM
{

/**
 * @class UdPldmFrInRequestParameters
 *
 * Adds Inbound Request PLDM Flight Recorder information to an error log as user detail data
 */
class UdPldmFrInRequestParameters : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     */
    UdPldmFrInRequestParameters();

    /**
     *  @brief Destructor
     */
    virtual ~UdPldmFrInRequestParameters();

  private:
    // Disabled
    UdPldmFrInRequestParameters(UdPldmFrInRequestParameters &);
    UdPldmFrInRequestParameters & operator=(UdPldmFrInRequestParameters &);
};

/**
 * @class UdPldmFrOutRequestParameters
 *
 * Adds Outbound Request PLDM Flight Recorder information to an error log as user detail data
 */
class UdPldmFrOutRequestParameters : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     */
    UdPldmFrOutRequestParameters();

    /**
     *  @brief Destructor
     */
    virtual ~UdPldmFrOutRequestParameters();

  private:
    // Disabled
    UdPldmFrOutRequestParameters(UdPldmFrOutRequestParameters &);
    UdPldmFrOutRequestParameters & operator=(UdPldmFrOutRequestParameters &);
};

/**
 * @class UdPldmFrInResponseParameters
 *
 * Adds Inbound Response PLDM Flight Recorder information to an error log as user detail data
 */
class UdPldmFrInResponseParameters : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     */
    UdPldmFrInResponseParameters();

    /**
     *  @brief Destructor
     */
    virtual ~UdPldmFrInResponseParameters();

  private:
    // Disabled
    UdPldmFrInResponseParameters(UdPldmFrInResponseParameters &);
    UdPldmFrInResponseParameters & operator=(UdPldmFrInResponseParameters &);
};

/**
 * @class UdPldmFrOutResponseParameters
 *
 * Adds Outbound Response PLDM Flight Recorder information to an error log as user detail data
 */
class UdPldmFrOutResponseParameters : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     */
    UdPldmFrOutResponseParameters();

    /**
     *  @brief Destructor
     */
    virtual ~UdPldmFrOutResponseParameters();

  private:
    // Disabled
    UdPldmFrOutResponseParameters(UdPldmFrOutResponseParameters &);
    UdPldmFrOutResponseParameters & operator=(UdPldmFrOutResponseParameters &);
};


} // end PLDM namespace

#endif
