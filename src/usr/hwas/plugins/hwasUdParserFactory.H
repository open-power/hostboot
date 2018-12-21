/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/plugins/hwasUdParserFactory.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef HWAS_UD_PARSER_FACTORY_H
#define HWAS_UD_PARSER_FACTORY_H

#include "errludparserfactory.H"
#include "errludParser_pgData.H"
#include "../hwas/common/hwas_reasoncodes.H"

namespace HWAS
{
    class UserDetailsParserFactory :
        public ERRORLOG::ErrlUserDetailsParserFactory
    {
    public:
        UserDetailsParserFactory()
        {
            registerParser<UdParserPartialGoodIssue>
                (HWAS_UDT_PARTIAL_GOOD_DATA);
        }
    private:
        // Parser isn't compiled with c++11 in all environments, and
        // therefore "delete" of unused interfaces (like below) is not
        // supported, nor are functions with move semantics
        // Disable compiler provided default functions
        UserDetailsParserFactory(const UserDetailsParserFactory &);
        UserDetailsParserFactory& operator=(const UserDetailsParserFactory &);
    };
}

#endif
