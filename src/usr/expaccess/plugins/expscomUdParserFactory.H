/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/plugins/expscomUdParserFactory.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/**
 *  @file  expscomUdParserFactory.H
 *  @brief Registers Explorer User Detail parsers
 */
#if !defined(_EXPSCOMUDPARSERFACTORY_H)
#define _EXPSCOMUDPARSERFACTORY_H

#include "errludparserfactory.H"
#include "errludP_expscom.H"

namespace EXPSCOM
{
    class UserDetailsParserFactory
        : public ERRORLOG::ErrlUserDetailsParserFactory
    {
        public:
            UserDetailsParserFactory()
            {
                registerParser<UdParserExpActiveLog>
                  (EXPSCOM_UDT_ACTIVE_LOG);

                registerParser<UdParserExpSavedLogA>
                  (EXPSCOM_UDT_SAVED_LOG_A);
                registerParser<UdParserExpSavedLogB>
                  (EXPSCOM_UDT_SAVED_LOG_B);
            }

        private:

            UserDetailsParserFactory(const UserDetailsParserFactory &);
            UserDetailsParserFactory & operator=
                (const UserDetailsParserFactory &);
    };
};

#endif
