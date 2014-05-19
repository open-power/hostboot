/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/plugins/runtimeUdParserFactory.H $            */
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
#if !defined(_RUNTIMEUDPARSERFACTORY_H)
#define _RUNTIMEUDPARSERFACTORY_H

#include "errludparserfactory.H"
#include "errludP_hdat.H"

namespace RUNTIME
{
    class UserDetailsParserFactory 
        : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<RUNTIME::UdParserNaca>
                  (RUNTIME_UDT_NACA);
                registerParser<RUNTIME::UdParserSpira>
                  (RUNTIME_UDT_SPIRA);
                registerParser<RUNTIME::UdParserTuple>
                  (RUNTIME_UDT_TUPLE);
            }

        private:

            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=
                (const UserDetailsParserFactory &);
    };
};

#endif


