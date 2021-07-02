/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/plugins/initsvcudparserfactory.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#ifndef INITSVC_UDPARSERFACTORY_H
#define INITSVC_UDPARSERFACTORY_H

/**
 *  @file initsvcudparserfactory.H
 *
 *  Defines the InitSvcUserDetailsParserFactory.H class
 */
#include "errludparserfactory.H"
#include "initsvcudistep.H"

namespace INITSERVICE
{

/**
 * @class InitSvcUserDetailsParserFactory
 *
 * This factory produces ErrlUserDetailsParser objects to parse the specified
 * InitService user detail data.
*/
class InitSvcUserDetailsParserFactory : public ERRORLOG::ErrlUserDetailsParserFactory
{
public:

    /**
     *  @brief Constructor
     */
    InitSvcUserDetailsParserFactory()
    {
        registerParser<InitSvcUserDetailsParserIstep>(INIT_SVC_UDT_ISTEP);
        registerParser<InitSvcUserDetailsParserIstepStats>(INIT_SVC_UDT_ISTEP_STATS);
    }

private:

    // Disabled
    InitSvcUserDetailsParserFactory(const InitSvcUserDetailsParserFactory &);
    InitSvcUserDetailsParserFactory & operator=(
        const InitSvcUserDetailsParserFactory &);
};

}

#endif

