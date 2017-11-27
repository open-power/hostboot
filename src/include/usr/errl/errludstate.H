/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludstate.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#ifndef ERRL_UDSYSSTATE_H
#define ERRL_UDSYSSTATE_H

/**
 *  @file errludsysstate.H
 *
 *  Defines the ErrlUserDetailsState class that adds system state
 *  information to an error log as user detail data
 */

#include <errl/errluserdetails.H>
#include <stdint.h>


//Forward reference
namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsSysState
 *
 * Adds system state information to an error log
 */
class ErrlUserDetailsSysState : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsSysState();

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsSysState();

private:
    // Disabled
    ErrlUserDetailsSysState(const ErrlUserDetailsSysState &);
    ErrlUserDetailsSysState & operator=(const ErrlUserDetailsSysState &);
};

}

#endif
