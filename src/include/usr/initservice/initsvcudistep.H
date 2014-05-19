/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initsvcudistep.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef INITSVC_UDSTEP_H
#define INITSVC_UDSTEP_H

/**
 *  @file initsvcudistep.H
 *
 *  Defines the InitSvcUserDetailsIstep class that adds IStep FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>

namespace   INITSERVICE
{

/**
 * @struct InitSvcUserDetailsIstepData
 *
 * Defines the user detail data
 */
struct InitSvcUserDetailsIstepData
{
    uint16_t iv_step;
    uint16_t iv_substep;
    char iv_pIstepname[0];
};

/**
 * @class InitSvcUserDetailsIstep
 *
 * Adds IStep FFDC to an error log as user detail data
 */
class InitSvcUserDetailsIstep : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *
     *  Captures the supplied IStep FFDC data internally
     *
     *  @param i_pIstepname Istep name
     *  @param i_step       Step number
     *  @param i_substep    Sub-step number
     */
    InitSvcUserDetailsIstep(const char * i_pIstepname,
                            const uint16_t i_step,
                            const uint16_t i_substep);

    /**
     *  @brief Destructor
     */
    virtual ~InitSvcUserDetailsIstep();

private:
    // Disabled
    InitSvcUserDetailsIstep(const InitSvcUserDetailsIstep &);
    InitSvcUserDetailsIstep & operator=(const InitSvcUserDetailsIstep &);
};

}

#endif

