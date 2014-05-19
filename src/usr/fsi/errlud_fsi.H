/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/errlud_fsi.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef ERRL_UD_FSI_H
#define ERRL_UD_FSI_H

/**
 *  @file errlud_fsi.H
 *
 *  Defines the classes that logs and parses various HDAT structures
 */

#include <errl/errluserdetails.H>

namespace FSI
{

/**
 * @class UdPresence
 *
 * Adds FSI Link/Presence information to an error log as user detail data
 */
class UdPresence : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *  
     *  @param i_target  Chip being detected/acted upon
     */
    UdPresence( TARGETING::Target* i_target );

    /**
     *  @brief Destructor
     */
    virtual ~UdPresence();

  private:
    // Disabled
    UdPresence(UdPresence &);
    UdPresence & operator=(UdPresence &);
};

/**
 * @class UdOperation
 *
 * Adds FSI Operation Information to an error log as user detail data
 */
class UdOperation : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_target  Target of FSI Op
     *  @param i_address  Address of FSI Op
     *  @param i_readNotWrite  True=read, False=write
     */
    UdOperation( TARGETING::Target* i_target,
                 uint64_t i_address,
                 bool i_readNotWrite );

    /**
     *  @brief Destructor
     */
    virtual ~UdOperation();

  private:
    // Disabled
    UdOperation(UdPresence &);
    UdOperation & operator=(UdOperation &);
};


}

#endif
