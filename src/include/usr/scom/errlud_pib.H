/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/errlud_pib.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef ERRL_UD_PIB_H
#define ERRL_UD_PIB_H

/**
 *  @file errlud_fsi.H
 *
 *  Defines the classes that logs and parses various HDAT structures
 */

#include <errl/errluserdetails.H>

namespace SCOM
{

/**
 * @class UdPibInfo
 *
 * Adds PIB information to an error log as user detail data
 */
class UdPibInfo : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_pibErr Error returned from operation
     */
    UdPibInfo( uint8_t i_pibErr );

    /**
     *  @brief Destructor
     */
    virtual ~UdPibInfo();

    UdPibInfo(UdPibInfo &) = delete;
    UdPibInfo & operator=(UdPibInfo &) = delete;
};


}

#endif