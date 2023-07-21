/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/plugins/sbeUdParserFactory.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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
#ifndef _SBEUDPARSERFACTORY_H
#define _SBEUDPARSERFACTORY_H

#include "errludparserfactory.H"
#include "errludP_sbe.H"

namespace SBE
{
    class UserDetailsParserFactory : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<SBE::UdParserSbeNoFormat>(SBE_UDT_NO_FORMAT);
                registerParser<SBE::UdParserSbeMessageCommand>(SBE_UDT_SBE_MESSAGE_CMD);
                registerParser<SBE::UdParserSbeMessageData>(SBE_UDT_SBE_MESSAGE_DATA);
            }

        private:
            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=(const UserDetailsParserFactory &);
    };
};

#endif

